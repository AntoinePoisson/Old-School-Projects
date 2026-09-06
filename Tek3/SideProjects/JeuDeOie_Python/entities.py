import pygame
from pygame.locals import *

class Entities:
    def __init__(self):
        self.reset()

    player_winner = -1

    background = pygame.image.load("images/Plateau.png")
    pion_blue_pos = [0, 440]
    pion_blue_texture = pygame.image.load("images/pion_blue.png")
    pion_blue_herse_pos = [-99, -99]

    pion_red_pos = [20, 460]
    pion_red_texture = pygame.image.load("images/pion_red.png")
    pion_red_herse_pos = [-99, -99]

    herse_texture = pygame.image.load("images/barriere.png")

    hitbox_des = pygame.Rect(((561,428), (90,26)))

    des_first_texture = pygame.image.load("images/fond vide.png")
    des_first_pos = (780, 400)

    des_second_texture = pygame.image.load("images/fond vide.png")
    des_second_pos = (910, 400)

    des_all_texture = [
        pygame.image.load("images/Des 1.png"),
        pygame.image.load("images/Des 2.png"),
        pygame.image.load("images/Des 3.png"),
        pygame.image.load("images/Des 4.png"),
        pygame.image.load("images/Des 5.png"),
        pygame.image.load("images/Des 6.png"),
    ]

    button_throw = pygame.image.load("images/bouton_1.png")
    button_throw_press = pygame.image.load("images/bouton_2.png")

    button_restart = pygame.image.load("images/image recommencer.png")

    button_leave = pygame.image.load("images/image quitter.png")

    texte_texture = pygame.image.load("images/image texte 0.jpg")

    hitbox_cells = [
        ((63,440), (61,60)),
        ((126,440), (61,60)),
        ((189,440), (61,60)),
        ((252,440), (60,60)),
        ((313,440), (62,60)),
        ((376,440), (61,60)),
        ((439,438), (61,62)),
        ((439,375), (61,62)),
        ((439,313), (61,61)),
        ((439,251), (61,60)),
        ((439,189), (61,61)),
        ((439,126), (61,61)),
        ((439,63), (61,62)),
        ((439,0), (61,62)),
        ((376,0), (62,62)),
        ((313,0), (62,62)),
        ((251,0), (61,62)),
        ((189,0), (61,62)),
        ((126,0), (62,62)),
        ((63,0), (62,62)),
        ((0,0), (62,62)),
        ((0,63), (62,62)),
        ((0,126), (62,61)),
        ((0,188), (62,62)),
        ((0,251), (62,61)),
        ((0,313), (62,61)),
        ((0,375), (62,62)),
        ((63,375), (62,61)),
        ((126,375), (62,62)),
        ((189,375), (61,62)),
        ((251,375), (61,62)),
        ((313,375), (62,62)),
        ((376,375), (62,62)),
        ((377,313), (61,61)),
        ((377,251), (61,61)),
        ((377,188), (61,62)),
        ((377,126), (61,61)),
        ((376,64), (62,61)),
        ((313,64), (62,61)),
        ((251,64), (61,61)),
        ((189,64), (61,61)),
        ((126,64), (62,61)),
        ((64,64), (61,61)),
        ((64,126), (61,61)),
        ((64,188), (61,62)),
        ((64,251), (61,61)),
        ((64,313), (61,61)),
        ((126,313), (62,61)),
        ((188,313), (62,61)),
        ((251,313), (61,61)),
        ((313,312), (62,62)),
        ((314,251), (62,61)),
        ((314,188), (62,62)),
        ((313,126), (62,62)),
        ((251,126), (61,62)),
        ((189,126), (61,61)),
        ((126,126), (61,61)),
        ((126,188), (62,62)),
        ((126,251), (62,61)),
        ((189,251), (61,61)),
        ((251,251), (62,61)),
        ((251,189), (62,61)),
        ((189,189), (61,61)),
    ]

    def reset(self):
        self.player_winner = -1
        self.background = pygame.image.load("images/Plateau.png")
        self.pion_blue_pos = [0, 440]
        self.pion_blue_texture = pygame.image.load("images/pion_blue.png")
        self.pion_blue_herse_pos = [-99, -99]
        self.pion_red_pos = [20, 460]
        self.pion_red_texture = pygame.image.load("images/pion_red.png")
        self.pion_red_herse_pos = [-99, -99]
        self.herse_texture = pygame.image.load("images/barriere.png")
        self.hitbox_des = pygame.Rect(((561,428), (90,26)))
        self.des_first_texture = pygame.image.load("images/fond vide.png")
        self.des_first_pos = (780, 400)
        self.des_second_texture = pygame.image.load("images/fond vide.png")
        self.des_second_pos = (910, 400)
        self.des_all_texture = [
            pygame.image.load("images/Des 1.png"),
            pygame.image.load("images/Des 2.png"),
            pygame.image.load("images/Des 3.png"),
            pygame.image.load("images/Des 4.png"),
            pygame.image.load("images/Des 5.png"),
            pygame.image.load("images/Des 6.png"),
        ]
        self.button_throw = pygame.image.load("images/bouton_1.png")
        self.button_throw_press = pygame.image.load("images/bouton_2.png")
        self.button_restart = pygame.image.load("images/image recommencer.png")
        self.button_leave = pygame.image.load("images/image quitter.png")
        self.texte_texture = pygame.image.load("images/image texte 0.jpg")
        self.hitbox_cells = [
            ((63,440), (61,60)),
            ((126,440), (61,60)),
            ((189,440), (61,60)),
            ((252,440), (60,60)),
            ((313,440), (62,60)),
            ((376,440), (61,60)),
            ((439,438), (61,62)),
            ((439,375), (61,62)),
            ((439,313), (61,61)),
            ((439,251), (61,60)),
            ((439,189), (61,61)),
            ((439,126), (61,61)),
            ((439,63), (61,62)),
            ((439,0), (61,62)),
            ((376,0), (62,62)),
            ((313,0), (62,62)),
            ((251,0), (61,62)),
            ((189,0), (61,62)),
            ((126,0), (62,62)),
            ((63,0), (62,62)),
            ((0,0), (62,62)),
            ((0,63), (62,62)),
            ((0,126), (62,61)),
            ((0,188), (62,62)),
            ((0,251), (62,61)),
            ((0,313), (62,61)),
            ((0,375), (62,62)),
            ((63,375), (62,61)),
            ((126,375), (62,62)),
            ((189,375), (61,62)),
            ((251,375), (61,62)),
            ((313,375), (62,62)),
            ((376,375), (62,62)),
            ((377,313), (61,61)),
            ((377,251), (61,61)),
            ((377,188), (61,62)),
            ((377,126), (61,61)),
            ((376,64), (62,61)),
            ((313,64), (62,61)),
            ((251,64), (61,61)),
            ((189,64), (61,61)),
            ((126,64), (62,61)),
            ((64,64), (61,61)),
            ((64,126), (61,61)),
            ((64,188), (61,62)),
            ((64,251), (61,61)),
            ((64,313), (61,61)),
            ((126,313), (62,61)),
            ((188,313), (62,61)),
            ((251,313), (61,61)),
            ((313,312), (62,62)),
            ((314,251), (62,61)),
            ((314,188), (62,62)),
            ((313,126), (62,62)),
            ((251,126), (61,62)),
            ((189,126), (61,61)),
            ((126,126), (61,61)),
            ((126,188), (62,62)),
            ((126,251), (62,61)),
            ((189,251), (61,61)),
            ((251,251), (62,61)),
            ((251,189), (62,61)),
            ((189,189), (61,61)),
        ]
        return self
