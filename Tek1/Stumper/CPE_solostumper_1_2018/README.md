# Solo Stumper 1 — alphabetical sorting

[![View on portfolio](https://img.shields.io/badge/View_on_portfolio-111827?style=for-the-badge&logo=githubpages&logoColor=white)](https://antoinepoisson.github.io/Old-School-Projects/projects/stumper-solo1-2018)

![C](https://img.shields.io/badge/C-A8B9CC?style=flat-square&logo=c&logoColor=111827) ![Timed challenge](https://img.shields.io/badge/Solo-challenge-B45309?style=flat-square)

**Epitech project** · Solo Stumpers (`B-CPE-130`) · Tek1 · 2018-2019 · 1 afternoon · Solo

> A timed solo exam: split a sentence into words and print them in alphabetical order — without ever comparing two words.

## Overview

Solo Stumpers are timed individual exams. The subject is handed out on the spot, the work is strictly individual, and the clock stops at the end of the afternoon. This one: take a sentence as a single argument, print its words in alphabetical order.

The obvious answer is a comparison sort over an array of strings. This one compares nothing. `sort_alpha()` sweeps the alphabet from `'A'` to `'Z'` and, on each of the 26 passes, prints every word whose initial matches that letter. The cost is 26 × n first-character tests — linear in the number of words, with no swap, no recursion and no scratch array.

The "already printed" flag lives inside the data. `destroy_ligne()` overwrites byte 0 of a word with `'\0'` the moment it prints it, and a zero first byte matches no letter on any later pass. That removes the parallel boolean array a straightforward version would need.

```console
$ ./sort_words "banana Apple cherry apricot Date"
Apple apricot banana cherry Date

$ ./sort_words "zebra Zulu alpha Alpha beta"
alpha Alpha beta zebra Zulu

$ ./sort_words

$ echo $?
0
```

Case is ignored, and words sharing an initial keep their order of appearance — the second letter is never looked at. A missing argument prints a bare newline and exits `0` rather than dereferencing `av[1]`.

## How it works

**The split.** `my_str_to_word_array()` does two passes over the argument. The first, `word_count()`, sizes the pointer array; the second cuts the sentence on spaces and tabs, `malloc`s one buffer per word and reports the count back through an `int *` out-parameter, since the return slot is already taken by the array itself.

```mermaid
flowchart LR
    A["One quoted sentence in argv"] --> B["word_count sizes the array"]
    B --> C["malloc of count plus 1 pointers"]
    C --> D["Cut on spaces and tabs"]
    D --> E["Word array, NULL terminated"]
    E --> F["sort_alpha: 26 passes, A to Z"]
    F --> G["Print, then blank byte 0"]

    classDef core fill:#0F766E,stroke:#0F766E,color:#ffffff;
    classDef alt fill:#111827,stroke:#111827,color:#ffffff;
    classDef accent fill:#7C3AED,stroke:#7C3AED,color:#ffffff;
    class B,C core
    class A alt
    class F,G accent
```

**The sweep.** The outer loop walks the alphabet, the inner loop walks the words. Nothing is moved: the output order is produced directly by the order in which the two loops meet.

```c
int sort_alpha(char *tab[], int ac)
{
    int i = 'A';
    int first = 0;

    for (; i <= 'Z'; i++)
        for (int i_two = 0; i_two < ac; i_two++) {
            if (analyze_chara(i, tab[i_two][0]) == 1) {
                if (first == 1) {
                    my_putstr(" ");
                }
                first = 1;
                destroy_ligne(tab, i_two);
            }
        }
    return (0);
}
```

**The comparison.** `analyze_chara()` is written by hand rather than delegated to `strcmp`. Past an early return on a leading tab, it runs five integer equalities inside three `if`s: `chara == base`, then the 32-byte gap between upper and lower case tested from each side in turn. Case folding with no lookup table — and the third `if` is the second one rearranged, since `chara + 32 == base` and `chara == base - 32` are the same statement.

On the first input above, the 26 passes emit this, and passes `'E'` through `'Z'` emit nothing at all:

| Pass | Words emitted |
| --- | --- |
| `'A'` | `Apple`, `apricot` |
| `'B'` | `banana` |
| `'C'` | `cherry` |
| `'D'` | `Date` |

| File | Lines | Role |
| --- | --- | --- |
| `my_str_to_word_array.c` | 53 | Sizes, allocates and fills the word array |
| `sort_alpha.c` | 29 | The 26-pass sweep from `'A'` to `'Z'` |
| `analyze_chara.c` | 28 | Case-insensitive match, plus the in-band "used" mark |
| `main.c` | 28 | Argument check, split, sweep, trailing newline |
| `init_tab.c` | 24 | Compiled into the binary, declared in `main.c`, never called |
| `check_error.c` | 17 | Exactly one argument, or a newline and exit `0` |

## What this project demonstrates

- A bucket sort on the first letter: 26 passes over the array instead of a comparison sort, so the ordering is produced by iteration rather than by moving data
- An ordering relation written by hand and case-insensitive, rather than delegated to `strcmp`
- A "visited" flag stored in the data itself — byte 0 of each word — instead of a side array

## Key features

- Words grouped by first letter, from a single quoted string passed as an argument
- Homemade splitting on spaces and tabs, count returned through an out-parameter
- Only the first character of a word is ever examined; ties keep input order
- Missing or empty argument exits cleanly on `0` instead of faulting

## Technical stack

- **Languages** — C
- **Tools** — Makefile, gcc, Git
- **Concepts** — string splitting, bucket sort on the first letter, hand-written case-insensitive comparison

## Engineering constraints

- Timed exam lasting one afternoon, subject discovered on the spot
- Strictly individual work
- No libc strings and no libc I/O: `malloc` and `write` are the only two libc calls in the whole binary, and output goes through the homemade `my_putstr` of a 30-file, 737-line `libmy`
- Nothing is freed — the program prints once and exits, so reclaiming is left to the kernel

## Verification

No test file ships with the project. The `tests_run` rule hands the `tests/` directory itself to `gcc` as if it were a source file, and that directory is not in the repository.

Re-audited today under AddressSanitizer. The order printed is right on letter-only input, but three defects sit under it, in two different files.

| Finding | Trigger | Site |
| --- | --- | --- |
| Out-of-bounds write past the pointer array | A word ending in a digit or punctuation, or a tab used as separator | `my_str_to_word_array.c:51` |
| Words are never NUL-terminated | Every word: the copy loop stops one byte short of the slot `malloc` reserved for it | `my_str_to_word_array.c:41` |
| `'!'` to `':'` sort as `'A'` to `'Z'` | Any non-letter initial; `'0'`–`'9'` (48–57) alias onto `'P'`–`'Y'` (80–89) | `analyze_chara.c:16` |

The first two are separate bugs in the same 53-line splitter. `word_count()` defines a word boundary as *a letter followed by a space*, while the split loop right below it cuts on *space, tab or end of string* — sizing an array by one rule and filling it by another. The missing NUL is independent of that mismatch: the copy loop's own guard fires on the separator before it can write index `length`.

The third lives in another file: the `±32` fold has no range check, so it folds punctuation and digits into the alphabet as readily as letters. Only the second finding is invisible in normal use, and only because a fresh heap comes back zeroed — under ASan, which poisons new allocations, `Apple` prints with a trailing garbage byte.

## Build & run

```bash
make
./sort_words "the Quick brown Fox jumps"
# brown Fox jumps Quick the
```

Produces `sort_words`. `all` depends on a phony target spelled `NAME` rather than `$(NAME)`, so every invocation relinks.

---

[← Stumper — timed algorithm challenges](../README.md) · [↑ Tek1](../../README.md) · [⌂ All projects](../../../README.md)
