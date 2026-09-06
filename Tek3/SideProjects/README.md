# Side projects — self-directed practice

[Tek3](../README.md) / **SideProjects**

Seven programs written outside any subject between December 2020 and June 2021, each one an excuse
to put a language or a tool under the hand instead of reading about it. The hardest is the Game of
the Goose: 63 squares whose rules forbid ever summing the two dice, because an opening 9 lands on
square 26 when it comes out 6+3 and on square 53 when it comes out 4+5.

| Project | What it is | Size |
| --- | --- | --- |
| [Discord Git bot](BotDiscord_JavaScript) | Pushes announced in the Discord channel matching the branch, in 46 lines on Node's bare `http` | Dec 2020 · 2 weeks |
| [Brick Breaker](BrickBreaker_Python) | 15 bricks holding 29 hits, in 212 lines of pygame across four files | Feb 2021 · 2 weeks |
| [Pong](Pong_Python) | Two-player Pong in the same four files, ball physics in 24 lines | Feb 2021 · 2 weeks |
| [Game of the Goose](JeuDeOie_Python) | 63 squares behind a 63-entry dispatch table, 84 images and 14 sounds | Mar 2021 · 2 weeks |
| [Hangman in Java](HangMan_Java) | 26 keys and a gallows painted by one `paintComponent`, not a single `JButton` | Apr 2021 · 2 weeks |
| [Hangman in Ruby](HangMan_Ruby) | The same game on Gosu: 136 lines against Java's 210 | May 2021 · 2 weeks |
| [Rock Paper Scissors](RockPaperScissors_Java) | Nine rule pairs collapsed into `(player - ia + 3) % 3` | Jun 2021 · 2 weeks |

```mermaid
flowchart LR
    A["Dec 2020<br>Discord bot, Node and Docker"] --> B["Feb 2021<br>Brick Breaker, pygame"]
    B -->|"four files reused"| C["Feb 2021<br>Pong, pygame"]
    C --> D["Mar 2021<br>Game of the Goose, 2297 lines"]
    D --> E["Apr 2021<br>Hangman, Java and Swing"]
    E -->|"same assets, same rules"| F["May 2021<br>Hangman, Ruby and Gosu"]
    F --> G["Jun 2021<br>Rock Paper Scissors, Swing"]

    classDef core fill:#0F766E,stroke:#0F766E,color:#ffffff;
    classDef alt fill:#111827,stroke:#111827,color:#ffffff;
    classDef accent fill:#7C3AED,stroke:#7C3AED,color:#ffffff;
    class B,C core
    class A,D,G alt
    class E,F accent
```

Two of the seven are written twice on purpose, and the repetition is the method.

**Hangman, Java then Ruby.** Same 700x450 window, same nine PNGs — byte-identical in both folders —
same `.config` word, same rules. Freezing the problem means every remaining difference in the code
belongs to the language: revealing a letter is `word.substring(0, i) + c + word.substring(i + 1)`
in Java and `DISPLAY_WORD[i] = el._text` in Ruby. The port also found a behavioural drift nobody
had noticed — Java starts its mistake counter at 2 and loses at 8, so it gives six wrong guesses
where Ruby gives eight.

**Pong then Brick Breaker.** The same four-file split — `run.py`, `game.py`, `entities.py`,
`endGame.py` — carries both games, so the second project spends its budget on the part that is
actually new. In Pong a paddle is a segment and one flipped velocity component is the entire
physics; in Brick Breaker the same intersection test has five correct answers, because a rectangle
has four faces and a corner, and the boolean that detects the hit has already thrown away what is
needed to resolve it.

<pre>
SideProjects/
├── <a href="BotDiscord_JavaScript">BotDiscord_JavaScript/</a>    Discord bot relaying Git pushes, routed by branch, containerised
├── <a href="BrickBreaker_Python">BrickBreaker_Python/</a>      Brick Breaker in pygame — collision resolved by comparing overlaps
├── <a href="Pong_Python">Pong_Python/</a>              Two-player Pong, sharing Brick Breaker's four-file split
├── <a href="JeuDeOie_Python">JeuDeOie_Python/</a>          Game of the Goose — 63 squares modelled as data, not conditions
├── <a href="HangMan_Java">HangMan_Java/</a>             Hangman in Java Swing, hand-drawn interface, first real Java project
├── <a href="HangMan_Ruby">HangMan_Ruby/</a>             The exact same Hangman, ported to Ruby for a direct comparison
└── <a href="RockPaperScissors_Java">RockPaperScissors_Java/</a>   Rock Paper Scissors in Java, small and deliberately finished
</pre>

---

[Tek3](../README.md)
