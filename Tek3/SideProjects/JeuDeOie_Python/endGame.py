import pygame
from pygame.locals import *
import time

def endGame(player, loop_main, window):
    win = pygame.image.load(("images/Victoire final R.png", "images/Victoire final B.png")[player == 1])
    restart = pygame.Rect((606,412), (88,26))
    leave = pygame.Rect((899,412), (47,26))

    window.blit(win, (500,0))
    pygame.display.flip()

    while True:
        for event in pygame.event.get():
            if event.type == MOUSEBUTTONUP:
                if event.button == 1 or event.button == 3:
                    if leave.collidepoint(event.pos):
                        loop_main = False
                        exit(0)
                    if restart.collidepoint(event.pos):
                        return 0
            if event.type == QUIT:
                loop_main = False
                exit(0)
    pass
