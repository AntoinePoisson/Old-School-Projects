import pygame
from pygame.locals import *
import time
from random import *
from entities import *
from cells import *

def throwDes():
    value_potential = [1, 2, 3, 4, 5, 6]
    res = choice(value_potential)
    son = pygame.mixer.Sound("musics/sound_roll_des.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    return res - 1

def callCells(selected, player, entity, window):
    switcher = {
        1: cell1,
        2: cell2,
        3: cell3,
        4: cell4,
        5: cell5,
        6: cell6,
        7: cell7,
        8: cell8,
        9: cell9,
        10: cell10,
        11: cell11,
        12: cell12,
        13: cell13,
        14: cell14,
        15: cell15,
        16: cell16,
        17: cell17,
        18: cell18,
        19: cell19,
        20: cell20,
        21: cell21,
        22: cell22,
        23: cell23,
        24: cell24,
        25: cell25,
        26: cell26,
        27: cell27,
        28: cell28,
        29: cell29,
        30: cell30,
        31: cell31,
        32: cell32,
        33: cell33,
        34: cell34,
        35: cell35,
        36: cell36,
        37: cell37,
        38: cell38,
        39: cell39,
        40: cell40,
        41: cell41,
        42: cell42,
        43: cell43,
        44: cell44,
        45: cell45,
        46: cell46,
        47: cell47,
        48: cell48,
        49: cell49,
        50: cell50,
        51: cell51,
        52: cell52,
        53: cell53,
        54: cell54,
        55: cell55,
        56: cell56,
        57: cell57,
        58: cell58,
        59: cell59,
        60: cell60,
        61: cell61,
        62: cell62,
        63: cell63,
    }
    funct = switcher.get(selected, lambda: "Invalid Cell")
    funct(player, entity, window)

def gameLoop(window, loop):
    loop_game = True
    while loop_game and loop:
        window = pygame.display.set_mode((1050,500))
        entity = Entities()
        window.blit(pygame.image.load("images/Plateau.png").convert(), ((0, 0)))
        window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
        window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
        pygame.display.flip()

        while loop_game and loop:
            for event in pygame.event.get():
                if event.type == QUIT:
                    loop = False
                    return -1
                elif event.type == MOUSEBUTTONUP:
                    if event.button == 1 or event.button == 3:

                        if entity.hitbox_des.collidepoint(event.pos):
                            value_first = throwDes()
                            value_second = throwDes()
                            window.blit(entity.button_throw_press, (561, 428))
                            pygame.display.flip()
                            time.sleep(0.2)
                            window.blit(entity.button_throw, (561, 428))
                            pygame.display.flip()
                            time.sleep(1.9)
                            des_first_texture = entity.des_all_texture[value_first]
                            des_second_texture = entity.des_all_texture[value_second]
                            window.blit(des_first_texture, entity.des_first_pos)
                            window.blit(des_second_texture, entity.des_second_pos)
                            pygame.display.flip()

                        for index in range(0, 63):
                            if (pygame.Rect(entity.hitbox_cells[index]).collidepoint(event.pos)):
                                callCells(index + 1, event.button, entity, window)
                        if (entity.player_winner != -1):
                            loop_game = False
                            return entity.player_winner

        pygame.display.flip()
    return -1