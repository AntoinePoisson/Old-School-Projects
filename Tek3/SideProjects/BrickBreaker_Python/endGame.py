import pygame
from pygame.locals import *
import time

def endGame(player, loop_main, window):
    win = pygame.image.load(("images/loose.png", "images/win.png")[player == 1])
    restart = pygame.Rect((94,513), (88,26))
    leave = pygame.Rect((387,513), (47,26))

    window.blit(win, (0,0))
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
