# Stumper — timed algorithm challenges

[← Tek1](../README.md) · [⌂ All projects](../../README.md)

Five closed-room exams. The subject is handed out at the start of the afternoon, nothing can be prepared the night before, and a working C binary has to be delivered the same evening — twice alone, three times in a pair.

Boggle is where that bites hardest: a word hunted across a letter grid, with the visited set and the undo stack written by hand as one linked list because the pair refused recursion outright — half a day after first reading the word on a subject sheet.

| Project | What it is | Size | When |
| --- | --- | --- | --- |
| [Solo Stumper 1](CPE_solostumper_1_2018) | Alphabetical sort by 26 passes over the alphabet, no two words compared | 1 afternoon · solo | Dec 2018 |
| [Solo Stumper 2](CPE_solostumper_2_2018) | Palindrome by converging indices, 103 lines, three `write()` calls | 1 afternoon · solo | Jan 2019 |
| [Duo Stumper 1](CPE_duostumper_1_2018) | ASCII fractal grown by substitution to a grid of side `w^n` | 1 afternoon · pair | Mar 2019 |
| [Duo Stumper 2](CPE_duostumper_2_2018) | Boggle: grid backtracking driven by an explicit stack, never recursion | 1 afternoon · pair | Apr 2019 |
| [Duo Stumper 3](CPE_duostumper_3_2018) | Caesar cipher over a whole file swallowed in one `read()` | 1 afternoon · pair | May 2019 |

The shape of every one of these afternoons is the same:

```mermaid
flowchart LR
    A["Subject opened at the start of the afternoon"] --> B["Pick the data structure on the spot"]
    B --> C["Write it in C on a hand-made libmy"]
    C --> D["Reject malformed input before printing anything"]
    D --> E["Binary and Makefile delivered the same evening"]

    classDef core fill:#0F766E,stroke:#0F766E,color:#ffffff;
    classDef alt fill:#111827,stroke:#111827,color:#ffffff;
    classDef accent fill:#7C3AED,stroke:#7C3AED,color:#ffffff;
    class B,C core
    class A alt
    class E accent
```

No libc string layer in any of the five: `my_strlen`, `my_getnbr`, `my_putstr` and the splitting routines are local code, carried in from a hand-written library and reused under the clock. Solo Stumper 2 takes nothing from the system but `write()`.

## Projects (5)

### Solo Stumpers (`B-CPE-130`)

- **[Solo Stumper 1 — alphabetical sorting](CPE_solostumper_1_2018)** — *1 afternoon · Solo*
  A sentence in, its words out in order — produced by sweeping `'A'` to `'Z'`, never by comparing two words.

- **[Solo Stumper 2 — palindrome](CPE_solostumper_2_2018)** — *1 afternoon · Solo*
  Two indices walking in from the ends of the string: no reversed copy, no `malloc`, exit code 84 on a missing argument.

### Stumpers (`B-CPE-210`)

- **[Duo Stumper 1 — ASCII fractal](CPE_duostumper_1_2018)** — *1 afternoon · Team of 2*
  A base pattern read from the command line, replicated into a grid of 729 cells at depth 3, behind five format checks.

- **[Duo Stumper 2 — Boggle](CPE_duostumper_2_2018)** — *1 afternoon · Team of 2*
  Word search over four orthogonal neighbours, with one linked list serving as visited set and undo stack at once.

- **[Duo Stumper 3 — Caesar cipher](CPE_duostumper_3_2018)** — *1 afternoon · Team of 2*
  A shift cipher that keeps case, leaves every non-letter byte alone, and accepts a shift of `-23` or of a million.
