import pygame
from pygame.locals import *

def displayRules(window):
    loop_rules = True
    while loop_rules:
        window.blit(pygame.image.load("images/background_menu_rules.jpg").convert(), ((0, 0)))
        pygame.display.flip()
        hitbox_all_window = pygame.Rect((0,0), (450,450))
        for event in pygame.event.get():
            if event.type == QUIT or event.type == KEYDOWN and event.key == K_ESCAPE or event.type== KEYDOWN and event.key == K_F2 or event.type == MOUSEBUTTONUP and hitbox_all_window.collidepoint(event.pos):
                loop_rules = False
    pass