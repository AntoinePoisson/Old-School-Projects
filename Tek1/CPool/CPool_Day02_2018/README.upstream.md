# CPool Day02 — note on the data files

## `passwd` and `Day02/students.csv` contain synthetic data

The pool shipped these exercises with a real dump of the IONIS Unix directory:
over 26,000 accounts with login, UID, **full name**, school and promotion, for
Epitech, Epita, ETNA, e-artsup, SupInternet, ISBP, SupBiotech, ISEFAC and IPSA
students and staff.

That dump is personal data belonging to real people who never agreed to see it
published, so it is not part of this repository. It has been replaced with
generated files that keep the exact same structure — same field layout, same
home roots, same GID-to-promotion scheme, same campus codes, same login naming
rule (six characters of the surname, an underscore, then the first free letter
of the given name) — but every identity in them is invented.

The shell scripts in this directory are unchanged and still run against these
files. `looneytised.sh` in particular relies on the given names `theo1`,
`steven1`, `arnaud1` and `pierre-jean`, which the generated `passwd` still
provides.

The only visible difference is volume: 500 accounts instead of 26,413, and 162
rows instead of 3,177 in `students.csv`. Counts printed by the scripts
therefore differ from what the original data produced.

## Note on `skip.sh`

`skip.sh` uses `sed -n '1~2p'`, a GNU extension. It works on the school's Linux
machines but fails on the BSD `sed` shipped with macOS.
