# Rush 2 — What language is this?

[![View on portfolio](https://img.shields.io/badge/View_on_portfolio-111827?style=for-the-badge&logo=githubpages&logoColor=white)](https://antoinepoisson.github.io/Old-School-Projects/projects/cpool-rush2-2018)

![C](https://img.shields.io/badge/C-A8B9CC?style=flat-square&logo=c&logoColor=111827) ![Text analysis](https://img.shields.io/badge/Text-analysis-0F766E?style=flat-square) ![Timed challenge](https://img.shields.io/badge/Team-rush-B45309?style=flat-square)

**Epitech project** · Unix & C Lab Seminar (Part I) (`B-CPE-100`) · Tek1 · 2018-2019 · 1 afternoon · Team project · Grade B

> Guessing the language of a text from its letter statistics alone.

## Overview

Hand the program a sentence and a few letters, and it names the language it is written in — English, French, German or Spanish. It never looks a word up. No dictionary, no word list, no library: it counts letters and bets on the closest statistical profile.

That is the trick that breaks a substitution cipher. A language's letter frequencies are stable enough to identify it even when the words themselves are unreadable.

The C Pool rules remove every convenient tool. `write()` is the only system function allowed, so there is no `printf` and no `malloc` — yet the imposed output format demands percentages to two decimals, which then have to be assembled one digit at a time.

439 lines of C, and not one `.h` file: every prototype is re-declared by hand at the top of the file that needs it, and `<unistd.h>` is the only include in the whole project.

## How it works

The assignment climbs in four steps — count one letter, count several, print their frequency to the hundredth of a percent, then name the language. The third step is the one that matters: a text of 60 letters and a text of 6000 must produce comparable numbers, so raw counts are useless.

```mermaid
flowchart LR
    A["argv: the text, then one letter per argument"] --> B["check_error: each letter argument is one char"]
    B --> C["Count each letter, print n and its percentage"]
    C --> D["sum_and_compare"]
    D --> E["Four got_diff functions, one per table"]
    E --> F["Sum of absolute gaps, requested letters only"]
    F --> G["Scan upward, print every language at the minimum"]

    classDef core fill:#0F766E,stroke:#0F766E,color:#ffffff;
    classDef alt fill:#111827,stroke:#111827,color:#ffffff;
    classDef accent fill:#7C3AED,stroke:#7C3AED,color:#ffffff;
    class E,F core
    class A alt
    class G accent
```

**Fixed point instead of floats.** A frequency is carried as an integer number of hundredths of a percent: `count * 10000 / total`. Three letters out of 48 becomes `625`, and `display_nb` writes the digits one at a time, dropping a `.` in after the hundreds column — `6.25`.

`count_percent` gets there by rescaling numerator and denominator by ten over three passes, so the product that matters is `count * 100 * 10000`. That product is also the range of the representation: it stays inside a signed 32-bit `int` up to 2147 occurrences of one letter, and at 2148 it wraps, so the digits come out as punctuation — `a:2148 (''.'+%)`.

**The denominator is letters, not characters.** `strlen_alph` counts only `a-z` and `A-Z`, so spaces, digits and punctuation leave both sides of the ratio. Adding a comma to the text does not move a single percentage. Case is folded by adding or subtracting 32, since there is no `tolower`.

Each language sits in its own file behind the same signature, `got_diff_*`, and returns the sum of absolute gaps between the text's frequencies and its own table. Only the requested letters are summed, so the comparison vector is exactly as wide as the letters passed on the command line.

| Letter | English | French | German | Spanish |
| --- | --- | --- | --- | --- |
| `a` | 8.17 | 7.64 | 6.52 | 11.53 |
| `e` | 12.70 | 14.72 | 16.40 | 12.18 |
| `i` | 6.97 | 7.53 | 6.55 | 6.25 |
| `n` | 6.75 | 7.10 | 9.78 | 6.71 |
| `o` | 7.51 | 5.80 | 2.60 | 8.68 |

*Five rows of the four reference tables the binary carries, shown in percent; the code stores them as integers in hundredths of a percent.*

Picking the winner is a counting scan, not a series of comparisons — `i` walks up from zero until it reaches one of the four distances:

```c
for (i = 0; i != nfr || i != neng || i != nger|| i != nspa; i++) {
    if (i == nfr)
        my_putstr(french);
    if (i == neng)
        my_putstr(english);
    if (i == nger)
        my_putstr(german);
    if (i == nspa)
        my_putstr(spanish);
    if (i == nfr || i == neng || i == nger|| i == nspa)
        return (0);
}
```

All four `if`s are tested at the same `i`, so a tie prints every language that reaches the minimum, back to back and with no separator:

```console
$ ./rush2 "the quick brown fox jumps over the lazy dog and the cats" p
p:1 (2.22%)
=> English=> Spanish
```

English and Spanish both score 29 there, French 30: one `p` over 45 letters carries almost no signal, and a classifier that always answers has to answer here too. Ask for `e t a o n` on the same sentence and English wins alone, 919 against Spanish's 1838.

## What this project demonstrates

- Language recognition with no dictionary, purely from statistics
- The same principle as breaking a cipher by frequency analysis
- Fixed-point arithmetic and hand-written decimal output under a `write()`-only rule

## Key features

- Four reference profiles — English, French, German, Spanish — one file each, all behind the same function shape
- Case-insensitive counting restricted to `a-z` / `A-Z`, normalised by letter count rather than string length
- Percentages to the hundredth of a percent, assembled digit by digit with `write()` alone
- Ties are printed rather than hidden: every language sitting at the minimum distance is named

## Technical stack

- **Languages** — C
- **Tools** — Makefile, gcc, Git
- **Concepts** — frequency analysis, data normalisation, distance measure

## Engineering constraints

- team work, with a defence graded on the group's weakest explanation
- imposed binary: `rush2`
- only system function allowed: `write` — no `stdio.h`, no `malloc`
- only `a-z` and `A-Z` characters are counted, accents and punctuation ignored
- imposed output format, percentages to two decimal places

## Beyond the baseline

- The assignment hands over the reference frequencies and asks for an algorithm of your own; this one is an L1 distance taken over the requested letters alone, on a problem the assignment itself calls ambiguous
- No floating point anywhere: the percentage stays an integer number of hundredths of a percent from the division down to the last digit written
- The tables are transcribed to the hundredth of a percent — German `q` at `2`, French `w` at `5` — so rare letters still move the distance instead of rounding to zero

## Verification

Rush graded by the autograder, no tests written. The worked example the assignment gives for the final step comes back character for character, `cat -e` included:

```console
$ ./rush2 "Good things do not end with 'ium'. They end with 'mania' or 'teria'." a q e i | cat -e
a:3 (6.25%)$
q:0 (0.00%)$
e:4 (8.33%)$
i:6 (12.50%)$
=> English
```

The four tables are the program's only ground truth, and nothing in the build checks them. The assignment asks for unit tests on every function, and 102 hand-copied frequencies are exactly the kind of data one would have pinned down. Re-reading them against the published frequencies:

| Table | Finding |
| --- | --- |
| `ger.c` | German `k` holds `1417`, i.e. 14.17%, where the published figure is 1.417% — the digits are right and the decimal point is gone |
| `spa.c` | declared `[26]` where the other three are `[27]`, and filled with 25 initialisers: from `r` on the values slide, `r`'s slot holding `463`, the figure for `t`, and `z` at index 26 reading past the end |

The German one is measurable. On *"Der kleine Junge kauft ein Buch und geht durch die Strassen der Stadt"*, asking for `e n r` gives German a distance of 164 against French's 305. Adding `k` to the query pushes German to 1231 and French to 648, and the sentence is handed to French — the letter that most identifies German is the one that disqualifies it.

## Build & run

```bash
make          # produces ./rush2
```

```console
$ ./rush2 "Le vent souffle sur la vieille ville et la pluie tombe sur les toits de pierre" e a n o t
e:13 (20.63%)
a:2 (3.17%)
n:1 (1.58%)
o:3 (4.76%)
t:5 (7.93%)
=> French
```

The first argument is the text; every argument after it must be exactly one character, which `check_error` enforces before anything is counted.

---

[← C Pool — the entry bootcamp](../README.md) · [↑ Tek1](../../README.md) · [⌂ All projects](../../../README.md)
