#!/usr/bin/env node

/**
 * Builds `website-src/` and writes it to `website/` at the root of this repository, ready
 * for GitHub Pages.
 *
 *   node scripts/build-pages.mjs
 *
 * Neither `website-src/` nor `website/` is committed on `main`: the source stays local, and
 * `scripts/deploy-pages.mjs` publishes this build to the `gh-pages` branch. The build scans each
 * project's real file tree and a real excerpt of its source off disk, so it has to run from a
 * full checkout, and `website/` has to be produced here rather than inside the site.
 *
 * ## What GitHub Pages needs that Cloudflare does not
 *
 * Three things, and each one is silent when it is missing:
 *
 * 1. **A base path.** A project's pages are served under the repository name —
 *    `https://<owner>.github.io/<repo>/` — and there is no setting that changes it. Without
 *    `basePath` every `/_next/*` request, every link and every fetch resolves at the origin root,
 *    which is a different site. Resolved below and passed to the build as
 *    `NEXT_PUBLIC_BASE_PATH`; `next.config.ts` and `src/utils/config/Site.ts` do the rest.
 *
 * 2. **Directory indexes.** Pages resolves `/about/` to `about/index.html` and nothing else — it
 *    has no `cleanUrls`, so the `out/about.html` beside an index-less `out/about/` that Cloudflare
 *    resolves through `html_handling` is a 404 there. `EXPORT_TRAILING_SLASH=true` makes the
 *    export write `about/index.html` instead. That is the one difference between this build and
 *    the Cloudflare one that is visible in the URL bar.
 *
 * 3. **`.nojekyll`.** Pages runs a Jekyll pass unless that file exists, and Jekyll drops every
 *    path starting with an underscore. `_next/` is every script and stylesheet on the site: the
 *    HTML deploys, nothing else does, and the result is a page that renders as unstyled text with
 *    no error anywhere. Written below, and it is the single most load-bearing byte here.
 *
 * ## Configuration
 *
 * Nothing needs setting. In Actions, `actions/configure-pages` reports the real values and the
 * workflow passes them through; locally they are derived from the git remote:
 *
 *   PAGES_BASE_PATH   sub-path, e.g. `/Old-School-Projects__`. Empty for a domain root.
 *   PAGES_SITE_URL    full origin + sub-path, for canonicals, hreflang, the sitemap and llms.txt.
 *
 * A user or organisation page (`<owner>.github.io`) and a custom domain both live at a root, so
 * both resolve to an empty base path — the detection below treats them the same way.
 */

import { execFileSync } from 'node:child_process';
import { cpSync, existsSync, rmSync, readdirSync, statSync, writeFileSync } from 'node:fs';
import { dirname, join, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';

const REPO_ROOT = resolve(dirname(fileURLToPath(import.meta.url)), '..');
const SITE_DIR = join(REPO_ROOT, 'website-src');
const EXPORT_DIR = join(SITE_DIR, 'out');
const PUBLISH_DIR = join(REPO_ROOT, 'website');

const step = (message) => console.log(`\n\x1b[36m→\x1b[0m ${message}`);
const done = (message) => console.log(`\x1b[32m✓\x1b[0m ${message}`);

function fail(message) {
  console.error(`\x1b[31m✗\x1b[0m ${message}`);
  process.exit(1);
}

/** `owner/repo` from the Actions environment, or from the origin remote of this checkout. */
function repository() {
  if (process.env.GITHUB_REPOSITORY) {
    const [owner, name] = process.env.GITHUB_REPOSITORY.split('/');
    return { owner, name };
  }

  try {
    const url = execFileSync('git', ['remote', 'get-url', 'origin'], { cwd: REPO_ROOT, encoding: 'utf-8' }).trim();
    // Both forms: `git@github.com:owner/repo.git` and `https://github.com/owner/repo.git`.
    const match = /[:/]([^/:]+)\/([^/]+?)(?:\.git)?$/.exec(url);
    if (match) return { owner: match[1], name: match[2] };
  } catch {
    /* No remote, or no git. Falls through to the root-path default below. */
  }

  return null;
}

/**
 * Where the build will be served from.
 *
 * `PAGES_BASE_PATH` is honoured even when empty — that is how the workflow passes through what
 * `actions/configure-pages` reports for a custom domain, and how a local run targets a root.
 * `??` and not `||`, or an intentional empty string would fall back to the derived sub-path.
 */
function target() {
  const repo = repository();
  const isRootPage = repo && repo.name.toLowerCase() === `${repo.owner.toLowerCase()}.github.io`;

  const derivedBasePath = !repo || isRootPage ? '' : `/${repo.name}`;
  const derivedOrigin = repo ? `https://${repo.owner.toLowerCase()}.github.io` : 'http://localhost:3200';

  // A lone `/` is what configure-pages reports for a root deployment; it means "no sub-path".
  const basePath = (process.env.PAGES_BASE_PATH ?? derivedBasePath).replace(/\/+$/, '');
  const siteUrl = (process.env.PAGES_SITE_URL || `${derivedOrigin}${basePath}`).replace(/\/+$/, '');

  return { basePath, siteUrl, derived: !process.env.PAGES_SITE_URL };
}

/** Total bytes and file count under a directory, for the summary line. */
function measure(directory) {
  let bytes = 0;
  let files = 0;

  const walk = (current) => {
    for (const entry of readdirSync(current, { withFileTypes: true })) {
      const path = join(current, entry.name);
      if (entry.isDirectory()) walk(path);
      else {
        bytes += statSync(path).size;
        files += 1;
      }
    }
  };

  walk(directory);
  return { bytes, files };
}

const { basePath, siteUrl, derived } = target();

console.log('\x1b[1mback_in_school → GitHub Pages\x1b[0m');
console.log(`  base path   ${basePath || '(root)'}`);
console.log(`  site URL    ${siteUrl}${derived ? '  (derived from the git remote)' : ''}`);
console.log(`  output      ${PUBLISH_DIR}`);

if (!existsSync(join(SITE_DIR, 'node_modules'))) {
  fail(`dependencies are not installed. Run:\n    cd ${SITE_DIR} && pnpm install`);
}

step('Building the static export');
try {
  execFileSync('pnpm', ['build'], {
    cwd: SITE_DIR,
    stdio: 'inherit',
    env: {
      ...process.env,
      NEXT_PUBLIC_BASE_PATH: basePath,
      NEXT_PUBLIC_SITE_URL: siteUrl,
      EXPORT_TRAILING_SLASH: 'true'
    }
  });
} catch {
  fail('`pnpm build` failed. Nothing was written to website/.');
}

if (!existsSync(join(EXPORT_DIR, 'index.html'))) {
  fail(`the build reported success but ${EXPORT_DIR}/index.html does not exist.`);
}

// Replaced rather than merged: a stale file from a previous base path would still be served, and
// the hashed chunk names mean nothing here ever overwrites anything.
step('Replacing website/');
rmSync(PUBLISH_DIR, { recursive: true, force: true });
cpSync(EXPORT_DIR, PUBLISH_DIR, { recursive: true });

// See the note at the top. Without this the whole `_next/` tree is dropped by Jekyll and the site
// deploys as unstyled HTML with no error anywhere.
writeFileSync(join(PUBLISH_DIR, '.nojekyll'), '');
done('.nojekyll written');

const { bytes, files } = measure(PUBLISH_DIR);
const megabytes = (bytes / 1024 / 1024).toFixed(0);

console.log(`\n\x1b[32m✓ website/\x1b[0m — ${files} files, ${megabytes} MB`);
console.log(`  serves at ${siteUrl}/`);

// GitHub Pages publishes up to 1 GB. Most of the weight is the RSC segment payloads Next emits
// for client-side prefetching (~2,000 `.txt` files); they compress hard in transit and are only
// fetched on a navigation, but the number is worth seeing before it becomes a problem.
if (bytes > 700 * 1024 * 1024) {
  console.warn(`\x1b[33m!\x1b[0m ${megabytes} MB is close to the 1 GB GitHub Pages limit.`);
}
