#!/usr/bin/env node

/**
 * Publishes `website/` to the `gh-pages` branch, as a single commit with no parent.
 *
 *   node scripts/build-pages.mjs     # website-src/ → website/
 *   node scripts/deploy-pages.mjs    # website/ → gh-pages
 *
 * ## Why an orphan branch
 *
 * The export is ~680 MB across 2,700 files, and every rebuild rewrites all of it: the chunk
 * names are content hashes, so nothing is ever modified in place, only replaced. Committing
 * that on `main` would add the full weight to its history on every deploy, and git history is
 * append-only — none of it would ever be reclaimed. `main` would outgrow the archive it exists
 * to hold within a handful of deploys.
 *
 * So `gh-pages` carries one commit and no history. Each deploy replaces that commit outright
 * and force-pushes; the previous one is left unreferenced and GitHub garbage-collects it. The
 * branch stays the size of one build, permanently, and `main` never carries the site at all.
 *
 * ## How it is built
 *
 * Without checking anything out. `git add` writes to whatever `GIT_INDEX_FILE` points at, so
 * this stages `website/` into a scratch index, turns that into a tree, and commits the tree
 * with `commit-tree` — no parent, therefore no history. Your working tree and your real index
 * are never touched, which is what makes this safe to run mid-edit: nothing is stashed, nothing
 * is checked out, and a failure anywhere leaves the repository exactly as it was.
 *
 * ## Serving it
 *
 * Settings → Pages → Source: "Deploy from a branch", branch `gh-pages`, folder `/ (root)`.
 *
 * Not GitHub Actions: a workflow runs from the branch that was pushed, so one living on `main`
 * would never fire for a push to `gh-pages`. Serving the branch directly needs no workflow and
 * no Actions minutes. It does run the content through Jekyll, which drops every path starting
 * with an underscore — `_next/`, i.e. every script and stylesheet on the site. The `.nojekyll`
 * that `build-pages.mjs` writes into the export is what disables that pass, and this script
 * refuses to publish a build that is missing it.
 */

import { execFileSync } from 'node:child_process';
import { existsSync, mkdtempSync, rmSync, readdirSync, statSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { dirname, join, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';

const REPO_ROOT = resolve(dirname(fileURLToPath(import.meta.url)), '..');
const PUBLISH_DIR = join(REPO_ROOT, 'website');
const BRANCH = 'gh-pages';

const step = (message) => console.log(`\n\x1b[36m→\x1b[0m ${message}`);
const done = (message) => console.log(`\x1b[32m✓\x1b[0m ${message}`);

function fail(message) {
  console.error(`\x1b[31m✗\x1b[0m ${message}`);
  process.exit(1);
}

/**
 * Runs git in the repository, returning trimmed stdout.
 *
 * `cwd` moves the invocation without moving the repository: `--git-dir` keeps every call
 * pointed at this repository's object store, so the staging step can run from inside
 * `website/` — where its pathspecs resolve — while still writing objects here.
 */
function git(args, { cwd = REPO_ROOT, env = {}, stdio = 'pipe' } = {}) {
  return execFileSync('git', ['--git-dir', join(REPO_ROOT, '.git'), ...args], {
    cwd,
    encoding: 'utf-8',
    stdio,
    env: { ...process.env, ...env }
  })?.trim();
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

// ---------------------------------------------------------------------------------------------
// Checks. Each one is a way to publish a broken site silently, so none of them is a warning.

if (!existsSync(join(PUBLISH_DIR, 'index.html'))) {
  fail(`no build to publish — ${PUBLISH_DIR}/index.html does not exist.\n  Run: node scripts/build-pages.mjs`);
}

// See the note at the top: without it Jekyll drops _next/ and the site deploys as plain text.
if (!existsSync(join(PUBLISH_DIR, '.nojekyll'))) {
  fail('the build has no .nojekyll — Jekyll would drop _next/ and serve the site unstyled.\n  Rebuild with: node scripts/build-pages.mjs');
}

let remote;
try {
  remote = git(['remote', 'get-url', 'origin']);
} catch {
  fail('no `origin` remote to push to.');
}

// The base path is baked into the export at build time and cannot be corrected here, so a build
// made against a different repository name would deploy as a site with no styles and dead links.
const expected = /[:/]([^/:]+)\/([^/]+?)(?:\.git)?$/.exec(remote);
if (expected) {
  const [, owner, name] = expected;
  const isRootPage = name.toLowerCase() === `${owner.toLowerCase()}.github.io`;
  const basePath = isRootPage ? '' : `/${name}`;
  const html = execFileSync('head', ['-c', '20000', join(PUBLISH_DIR, 'index.html')], { encoding: 'utf-8' });
  const built = /(?:href|src)="(\/[^/"][^"]*?)\/_next\//.exec(html);
  const builtBasePath = built ? built[1] : '';

  if (builtBasePath !== basePath) {
    fail(
      `this build targets ${builtBasePath || '(root)'} but ${owner}/${name} serves at ${basePath || '(root)'}.\n` +
        '  Every stylesheet and script would 404. Rebuild with: node scripts/build-pages.mjs'
    );
  }
}

const { bytes, files } = measure(PUBLISH_DIR);
const megabytes = (bytes / 1024 / 1024).toFixed(0);

console.log('\x1b[1mback_in_school → gh-pages\x1b[0m');
console.log(`  source      ${PUBLISH_DIR}`);
console.log(`  remote      ${remote}`);
console.log(`  branch      ${BRANCH}  (replaced, not appended to)`);
console.log(`  payload     ${files} files, ${megabytes} MB`);

// ---------------------------------------------------------------------------------------------
// Build the commit without checking anything out.

const scratch = mkdtempSync(join(tmpdir(), 'gh-pages-'));
const indexFile = join(scratch, 'index');

try {
  step('Staging the export into a scratch index');
  // Run from inside the export, with it as the work tree, so the tree is rooted at the export
  // itself rather than at a `website/` directory inside it. -f because .gitignore excludes
  // website/ on this branch: keeping it out of main is the whole point of publishing it here.
  git(['--work-tree', '.', 'add', '-A', '-f', '.'], {
    cwd: PUBLISH_DIR,
    env: { GIT_INDEX_FILE: indexFile }
  });

  const tree = git(['write-tree'], { env: { GIT_INDEX_FILE: indexFile } });
  done(`tree ${tree.slice(0, 10)}`);

  step('Committing with no parent');
  const message = `Deploy site — ${new Date().toISOString().slice(0, 16).replace('T', ' ')} UTC`;
  const commit = git(['commit-tree', tree, '-m', message]);
  git(['update-ref', `refs/heads/${BRANCH}`, commit]);
  done(`${BRANCH} → ${commit.slice(0, 10)}`);

  step(`Force-pushing to ${remote}`);
  // Force because the branch is replaced wholesale every time; there is no shared history to
  // fast-forward and nothing on it that anyone edits by hand.
  git(['push', '--force', 'origin', `${BRANCH}:${BRANCH}`], { stdio: 'inherit' });

  console.log(`\n\x1b[32m✓ deployed\x1b[0m — ${files} files, ${megabytes} MB on ${BRANCH}`);
  console.log('  Settings → Pages → Source: "Deploy from a branch", gh-pages, / (root)');
} catch (error) {
  fail(`deploy failed: ${error.message}\n  Nothing was pushed; your working tree is untouched.`);
} finally {
  rmSync(scratch, { recursive: true, force: true });
}
