#!/usr/bin/python3

import pygame
from pygame.locals import *
from rules import displayRules
from game import gameLoop
from endGame import endGame

pygame.init()

sound_background = pygame.mixer.Sound("musics/sound_arcade.wav")
sound_background.play(loops=-1, maxtime=0, fade_ms=0)

loop_main = True

while loop_main:
    window = pygame.display.set_mode((450, 450))
    pygame.display.set_icon(pygame.image.load("images/icone.png"))
    pygame.display.set_caption("Jeu de l'oie")
    window.blit(pygame.image.load("images/background_home_menu.jpg"), ((0, 0)))
    pygame.display.flip()

    loop_menu = True
    selected = ""

    while loop_menu and loop_main:
        hitbox_f1 = pygame.Rect((25,347), (399,33))
        hitbox_f2 = pygame.Rect((25,389), (313,33))
        for event in pygame.event.get():
            if event.type == QUIT or event.type == KEYDOWN and event.key == K_ESCAPE:
                loop_main = False
            elif event.type == KEYDOWN:
                if event.key == K_F1:
                    loop_menu = False
                    selected = "InGame"
                elif event.key == K_F2:
                    loop_menu = False
                    selected = "Rules"
            if event.type == MOUSEBUTTONUP:
                if event.button == 1 or event.button == 3:
                    if hitbox_f1.collidepoint(event.pos):
                        loop_menu = False
                        selected = "InGame"
                    if hitbox_f2.collidepoint(event.pos):
                        loop_menu = False
                        selected = "Rules"

    if (selected == "InGame"):
        winner = gameLoop(window, loop_main)
        if (winner == -1):
            loop_main = False
        else:
            endGame(winner, loop_main, window)
        selected = ""

    if (selected == "Rules"):
        displayRules(window)
        selected = ""