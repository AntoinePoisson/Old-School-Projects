# Tek1 — 2018-2019

[⌂ All projects](../README.md)

Fifty projects in nine months, forty-eight of them in C, and for most of those the allowed-function
list stops at `read`, `write`, `malloc` and `free` — `printf`, `strlen` and `atoi` are rebuilt into
`libmy.a`, which 69 Makefiles under `Tek1/` link against. The year opens on a one-month pool at a
subject a day, and closes on three two-week team builds in the same May–June window: Corewar, 42sh
and My RPG.

The largest of the three is Corewar, 11,813 lines across 276 C files, and its difficulty is not the
size. Its `.cor` binary format has to run on another team's virtual machine: one byte of drift in
the 2,192-byte header and nothing executes at all.

| Module | What it is | Span | Grades |
| --- | --- | --- | --- |
| [CPool](CPool) | A subject a day for a month, then parsers and a bignum calculator with no libc | Oct 2018 – Jan 2019 · 22 projects | 22 × B |
| [Maths](Maths) | Vectors, homogeneous transforms, matrix inversion, ray–quadric roots — written in C | Oct 2018 – Jan 2019 · 5 projects | 5 × A |
| [CPE](CPE) | Sorting on two stacks, maze DFS, colony scheduling, and an assembler plus its VM | Nov 2018 – Jun 2019 · 6 projects | 3 × A · 3 × B |
| [PSU](PSU) | Syscalls, signals and ncurses, plus three shells ending on a team-built 42sh | Nov 2018 – Jun 2019 · 8 projects | 3 × A · 5 × B |
| [Graphics](Graphics) | Four CSFML games, from a shooting gallery to a 9,244-line RPG | Dec 2018 – Jun 2019 · 4 projects | 4 × A |
| [Stumper](Stumper) | Closed-room exams: subject handed out on the spot, binary due that afternoon | Dec 2018 – May 2019 · 5 projects | ungraded |

```mermaid
flowchart LR
    A["Oct 2018 — C Pool: a subject a day for a month"] --> B["Nov 2018 to Jan 2019 — libmy frozen, no-libc parsers and bignums,<br/>first algorithms, maths in C, first CSFML game"]
    B --> C["Feb to Apr 2019 — Minishell 1 and 2, Tetris, maze generation, colony routing"]
    C --> D["May to Jun 2019 — Corewar, 42sh and My RPG, two weeks each, in teams"]

    classDef core fill:#0F766E,stroke:#0F766E,color:#ffffff;
    classDef alt fill:#111827,stroke:#111827,color:#ffffff;
    classDef accent fill:#7C3AED,stroke:#7C3AED,color:#ffffff;
    class B,C core
    class A alt
    class D accent
```

<pre>
Tek1/
├── <a href="CPool">CPool/</a>                              C &amp; Unix bootcamp · 22 projects
│   ├── <a href="CPool/CPool_Day01_2018">CPool_Day01_2018/</a>            Unix environment                              · B
│   ├── <a href="CPool/CPool_Day02_2018">CPool_Day02_2018/</a>            shell scripting                               · B
│   ├── <a href="CPool/CPool_Day03_2018">CPool_Day03_2018/</a>            first C functions                              · B
│   ├── <a href="CPool/CPool_Day04_2018">CPool_Day04_2018/</a>            pointers                                       · B
│   ├── <a href="CPool/CPool_Day05_2018">CPool_Day05_2018/</a>            recursion                                      · B
│   ├── <a href="CPool/CPool_Day06_2018">CPool_Day06_2018/</a>            string manipulation                            · B
│   ├── <a href="CPool/CPool_Day07_2018">CPool_Day07_2018/</a>            static library and arguments                   · B
│   ├── <a href="CPool/CPool_Day08_2018">CPool_Day08_2018/</a>            compilation and dynamic allocation             · B
│   ├── <a href="CPool/CPool_Day09_2018">CPool_Day09_2018/</a>            structures                                     · B
│   ├── <a href="CPool/CPool_Day10_2018">CPool_Day10_2018/</a>            Makefiles and function pointers                 · B
│   ├── <a href="CPool/CPool_Day11_2018">CPool_Day11_2018/</a>            linked lists                                   · B
│   ├── <a href="CPool/CPool_Day12_2018">CPool_Day12_2018/</a>            file descriptors                               · B
│   ├── <a href="CPool/CPool_Day13_2018">CPool_Day13_2018/</a>            first CSFML program                            · B
│   ├── <a href="CPool/CPool_rush1_2018">CPool_rush1_2018/</a>            timed square-pattern parser                    · B
│   ├── <a href="CPool/CPool_rush2_2018">CPool_rush2_2018/</a>            language-frequency detector                    · B
│   ├── <a href="CPool/CPool_workshoplib_2018">CPool_workshoplib_2018/</a>      production-ready libmy                         · B
│   ├── <a href="CPool/CPool_Tree_2018">CPool_Tree_2018/</a>             procedural ASCII tree                          · B
│   ├── <a href="CPool/CPool_match-nmatch_2018">CPool_match-nmatch_2018/</a>     wildcard matching and backtracking             · B
│   ├── <a href="CPool/CPool_bistro-matic_2018">CPool_bistro-matic_2018/</a>     arbitrary-base expression engine               · B
│   ├── <a href="CPool/CPool_evalexpr_2018">CPool_evalexpr_2018/</a>         recursive-descent arithmetic parser             · B
│   ├── <a href="CPool/CPool_infinadd_2018">CPool_infinadd_2018/</a>         arbitrary-precision addition                    · B
│   └── <a href="CPool/CPool_finalstumper_2018">CPool_finalstumper_2018/</a>     timed output-recognition challenge              · B
├── <a href="Maths">Maths/</a>                               applied mathematics in C · 5 projects
│   ├── <a href="Maths/101pong_2018">101pong_2018/</a>                   vector motion and bounces                       · A
│   ├── <a href="Maths/102architect_2018">102architect_2018/</a>              homogeneous transformations                    · A
│   ├── <a href="Maths/103cipher_2018">103cipher_2018/</a>                 matrix cryptography                             · A
│   ├── <a href="Maths/104intersection_2018">104intersection_2018/</a>           line–quadric intersections                     · A
│   └── <a href="Maths/105torus_2018">105torus_2018/</a>                  numerical root finding                          · A
├── <a href="CPE">CPE/</a>                                 algorithms and data structures · 6 projects
│   ├── <a href="CPE/CPE_matchstick_2018">CPE_matchstick_2018/</a>            adversarial game AI                            · A
│   ├── <a href="CPE/CPE_pushswap_2018">CPE_pushswap_2018/</a>              constrained stack sorting                      · A
│   ├── <a href="CPE/CPE_getnextline_2018">CPE_getnextline_2018/</a>           buffered line reader                           · A
│   ├── <a href="CPE/CPE_dante_2018">CPE_dante_2018/</a>                 maze generation and pathfinding                · B
│   ├── <a href="CPE/CPE_lemin_2018">CPE_lemin_2018/</a>                 graph routing with concurrent agents           · B
│   └── <a href="CPE/CPE_corewar_2018">CPE_corewar_2018/</a>               assembler and shared-memory virtual machine    · B
├── <a href="PSU">PSU/</a>                                 Unix systems programming · 8 projects
│   ├── <a href="PSU/PSU_my_ls_2018">PSU_my_ls_2018/</a>                 Unix directory listing                          · B
│   ├── <a href="PSU/PSU_navy_2018">PSU_navy_2018/</a>                  battleship over Unix signals                    · B
│   ├── <a href="PSU/PSU_my_sokoban_2018">PSU_my_sokoban_2018/</a>            terminal puzzle game                           · B
│   ├── <a href="PSU/PSU_my_printf_2018">PSU_my_printf_2018/</a>             variadic formatted output                       · B
│   ├── <a href="PSU/PSU_minishell1_2018">PSU_minishell1_2018/</a>            first process-executing shell                   · A
│   ├── <a href="PSU/PSU_tetris_2018">PSU_tetris_2018/</a>                configurable ncurses Tetris                    · B
│   ├── <a href="PSU/PSU_minishell2_2018">PSU_minishell2_2018/</a>            shell parser, pipes and redirections            · A
│   └── <a href="PSU/PSU_42sh_2018">PSU_42sh_2018/</a>                  full interactive team shell                    · A
├── <a href="Graphics">Graphics/</a>                            real-time 2D games in C · 4 projects
│   ├── <a href="Graphics/MUL_my_hunter_2018">MUL_my_hunter_2018/</a>            event-driven shooting game                     · A
│   ├── <a href="Graphics/MUL_my_runner_2018">MUL_my_runner_2018/</a>            parallax endless runner                        · A
│   ├── <a href="Graphics/MUL_my_defender_2018">MUL_my_defender_2018/</a>          tower defence with level editor                · A
│   └── <a href="Graphics/MUL_my_rpg_2018">MUL_my_rpg_2018/</a>               complete role-playing game                     · A
└── <a href="Stumper">Stumper/</a>                             timed algorithm challenges · 5 projects
    ├── <a href="Stumper/CPE_solostumper_1_2018">CPE_solostumper_1_2018/</a>       alphabetical sorting under time pressure
    ├── <a href="Stumper/CPE_solostumper_2_2018">CPE_solostumper_2_2018/</a>       palindrome detection under time pressure
    ├── <a href="Stumper/CPE_duostumper_1_2018">CPE_duostumper_1_2018/</a>        pair-built ASCII fractal
    ├── <a href="Stumper/CPE_duostumper_2_2018">CPE_duostumper_2_2018/</a>        pair-built Boggle solver
    └── <a href="Stumper/CPE_duostumper_3_2018">CPE_duostumper_3_2018/</a>        pair-built Caesar cipher
</pre>

---

[⌂ All projects](../README.md) · [Next year — Tek2 →](../Tek2/README.md)
