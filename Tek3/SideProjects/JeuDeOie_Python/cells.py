import pygame
from pygame.locals import *
from random import *
from config import *

def cell1(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_1
        entity.pion_red_pos[1] = Rouge_Y_1
        entity.texte_texture = pygame.image.load(image_texte_1)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_1
        entity.pion_blue_pos[1] = Bleu_Y_1
        entity.texte_texture = pygame.image.load(image_texte_1)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell2(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_2
        entity.pion_red_pos[1] = Rouge_Y_2
        entity.texte_texture = pygame.image.load(image_texte_2)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_2
        entity.pion_blue_pos[1] = Bleu_Y_2
        entity.texte_texture = pygame.image.load(image_texte_2)
        entity.pion_blue_herse_pos = [-99, -99]
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell3(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_3
        entity.pion_red_pos[1] = Rouge_Y_3
        entity.texte_texture = pygame.image.load(image_texte_3)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_3
        entity.pion_blue_pos[1] = Bleu_Y_3
        entity.texte_texture = pygame.image.load(image_texte_3)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell4(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_4
        entity.pion_red_pos[1] = Rouge_Y_4
        entity.texte_texture = pygame.image.load(image_texte_4)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_4
        entity.pion_blue_pos[1] = Bleu_Y_4
        entity.texte_texture = pygame.image.load(image_texte_4)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell5(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_5
        entity.pion_red_pos[1] = Rouge_Y_5
        entity.texte_texture = pygame.image.load(image_texte_5)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_5
        entity.pion_blue_pos[1] = Bleu_Y_5
        entity.texte_texture = pygame.image.load(image_texte_5)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell6(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_6
        entity.pion_red_pos[1] = Rouge_Y_6
        entity.texte_texture = pygame.image.load(image_texte_6)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_6
        entity.pion_blue_pos[1] = Bleu_Y_6
        entity.texte_texture = pygame.image.load(image_texte_6)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    son = pygame.mixer.Sound("musics/sound_jump.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell7(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_7
        entity.pion_red_pos[1] = Rouge_Y_7
        entity.texte_texture = pygame.image.load(image_texte_7)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_7
        entity.pion_blue_pos[1] = Bleu_Y_7
        entity.texte_texture = pygame.image.load(image_texte_7)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell8(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_8
        entity.pion_red_pos[1] = Rouge_Y_8
        entity.texte_texture = pygame.image.load(image_texte_8)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_8
        entity.pion_blue_pos[1] = Bleu_Y_8
        entity.texte_texture = pygame.image.load(image_texte_8)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell9(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_9
        entity.pion_red_pos[1] = Rouge_Y_9
        entity.texte_texture = pygame.image.load(image_texte_9)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_9
        entity.pion_blue_pos[1] = Bleu_Y_9
        entity.texte_texture = pygame.image.load(image_texte_9)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    son = pygame.mixer.Sound("musics/sound_oie.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell10(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_10
        entity.pion_red_pos[1] = Rouge_Y_10
        entity.texte_texture = pygame.image.load(image_texte_10)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_10
        entity.pion_blue_pos[1] = Bleu_Y_10
        entity.texte_texture = pygame.image.load(image_texte_10)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell11(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_11
        entity.pion_red_pos[1] = Rouge_Y_11
        entity.texte_texture = pygame.image.load(image_texte_11)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_11
        entity.pion_blue_pos[1] = Bleu_Y_11
        entity.texte_texture = pygame.image.load(image_texte_11)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell12(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_12
        entity.pion_red_pos[1] = Rouge_Y_12
        entity.texte_texture = pygame.image.load(image_texte_12)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_12
        entity.pion_blue_pos[1] = Bleu_Y_12
        entity.texte_texture = pygame.image.load(image_texte_12)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell13(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_13
        entity.pion_red_pos[1] = Rouge_Y_13
        entity.texte_texture = pygame.image.load(image_texte_13)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_13
        entity.pion_blue_pos[1] = Bleu_Y_13
        entity.texte_texture = pygame.image.load(image_texte_13)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell14(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_14
        entity.pion_red_pos[1] = Rouge_Y_14
        entity.texte_texture = pygame.image.load(image_texte_14)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_14
        entity.pion_blue_pos[1] = Bleu_Y_14
        entity.texte_texture = pygame.image.load(image_texte_14)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell15(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_15
        entity.pion_red_pos[1] = Rouge_Y_15
        entity.texte_texture = pygame.image.load(image_texte_15)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_15
        entity.pion_blue_pos[1] = Bleu_Y_15
        entity.texte_texture = pygame.image.load(image_texte_15)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell16(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_16
        entity.pion_red_pos[1] = Rouge_Y_16
        entity.texte_texture = pygame.image.load(image_texte_16)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_16
        entity.pion_blue_pos[1] = Bleu_Y_16
        entity.texte_texture = pygame.image.load(image_texte_16)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell17(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_17
        entity.pion_red_pos[1] = Rouge_Y_17
        entity.texte_texture = pygame.image.load(image_texte_17)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_17
        entity.pion_blue_pos[1] = Bleu_Y_17
        entity.texte_texture = pygame.image.load(image_texte_17)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell18(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_18
        entity.pion_red_pos[1] = Rouge_Y_18
        entity.texte_texture = pygame.image.load(image_texte_18)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_18
        entity.pion_blue_pos[1] = Bleu_Y_18
        entity.texte_texture = pygame.image.load(image_texte_18)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_oie.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell19(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_19
        entity.pion_red_pos[1] = Rouge_Y_19
        entity.texte_texture = pygame.image.load(image_texte_19)
        entity.pion_red_herse_pos = [entity.pion_red_pos[0], entity.pion_red_pos[1]]
    else:
        entity.pion_blue_pos[0] = Bleu_X_19
        entity.pion_blue_pos[1] = Bleu_Y_19
        entity.texte_texture = pygame.image.load(image_texte_19)
        entity.pion_blue_herse_pos = [entity.pion_blue_pos[0], entity.pion_blue_pos[1]]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    son = pygame.mixer.Sound("musics/sound_stun.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell20(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_20
        entity.pion_red_pos[1] = Rouge_Y_20
        entity.texte_texture = pygame.image.load(image_texte_20)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_20
        entity.pion_blue_pos[1] = Bleu_Y_20
        entity.texte_texture = pygame.image.load(image_texte_20)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell21(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_21
        entity.pion_red_pos[1] = Rouge_Y_21
        entity.texte_texture = pygame.image.load(image_texte_21)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_21
        entity.pion_blue_pos[1] = Bleu_Y_21
        entity.texte_texture = pygame.image.load(image_texte_21)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell22(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_22
        entity.pion_red_pos[1] = Rouge_Y_22
        entity.texte_texture = pygame.image.load(image_texte_22)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_22
        entity.pion_blue_pos[1] = Bleu_Y_22
        entity.texte_texture = pygame.image.load(image_texte_22)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell23(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_23
        entity.pion_red_pos[1] = Rouge_Y_23
        entity.texte_texture = pygame.image.load(image_texte_23)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_23
        entity.pion_blue_pos[1] = Bleu_Y_23
        entity.texte_texture = pygame.image.load(image_texte_23)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell24(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_24
        entity.pion_red_pos[1] = Rouge_Y_24
        entity.texte_texture = pygame.image.load(image_texte_24)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_24
        entity.pion_blue_pos[1] = Bleu_Y_24
        entity.texte_texture = pygame.image.load(image_texte_24)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell25(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_25
        entity.pion_red_pos[1] = Rouge_Y_25
        entity.texte_texture = pygame.image.load(image_texte_25)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_25
        entity.pion_blue_pos[1] = Bleu_Y_25
        entity.texte_texture = pygame.image.load(image_texte_25)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell26(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_26
        entity.pion_red_pos[1] = Rouge_Y_26
        entity.texte_texture = pygame.image.load(image_texte_26)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_26
        entity.pion_blue_pos[1] = Bleu_Y_26
        entity.texte_texture = pygame.image.load(image_texte_26)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    son = pygame.mixer.Sound("musics/sound_magic.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell27(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_27
        entity.pion_red_pos[1] = Rouge_Y_27
        entity.texte_texture = pygame.image.load(image_texte_27)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_27
        entity.pion_blue_pos[1] = Bleu_Y_27
        entity.texte_texture = pygame.image.load(image_texte_27)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    son = pygame.mixer.Sound("musics/sound_oie.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell28(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_28
        entity.pion_red_pos[1] = Rouge_Y_28
        entity.texte_texture = pygame.image.load(image_texte_28)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_28
        entity.pion_blue_pos[1] = Bleu_Y_28
        entity.texte_texture = pygame.image.load(image_texte_28)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell29(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_29
        entity.pion_red_pos[1] = Rouge_Y_29
        entity.texte_texture = pygame.image.load(image_texte_29)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_29
        entity.pion_blue_pos[1] = Bleu_Y_29
        entity.texte_texture = pygame.image.load(image_texte_29)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell30(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_30
        entity.pion_red_pos[1] = Rouge_Y_30
        entity.texte_texture = pygame.image.load(image_texte_30)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_30
        entity.pion_blue_pos[1] = Bleu_Y_30
        entity.texte_texture = pygame.image.load(image_texte_30)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell31(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_31
        entity.pion_red_pos[1] = Rouge_Y_31
        entity.texte_texture = pygame.image.load(image_texte_31)
        entity.pion_red_herse_pos = [entity.pion_red_pos[0], entity.pion_red_pos[1]]
    else:
        entity.pion_blue_pos[0] = Bleu_X_31
        entity.pion_blue_pos[1] = Bleu_Y_31
        entity.texte_texture = pygame.image.load(image_texte_31)
        entity.pion_blue_herse_pos = [entity.pion_blue_pos[0], entity.pion_blue_pos[1]]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    son = pygame.mixer.Sound("musics/sound_stun.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell32(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_32
        entity.pion_red_pos[1] = Rouge_Y_32
        entity.texte_texture = pygame.image.load(image_texte_32)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_32
        entity.pion_blue_pos[1] = Bleu_Y_32
        entity.texte_texture = pygame.image.load(image_texte_32)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell33(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_33
        entity.pion_red_pos[1] = Rouge_Y_33
        entity.texte_texture = pygame.image.load(image_texte_33)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_33
        entity.pion_blue_pos[1] = Bleu_Y_33
        entity.texte_texture = pygame.image.load(image_texte_33)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell34(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_34
        entity.pion_red_pos[1] = Rouge_Y_34
        entity.texte_texture = pygame.image.load(image_texte_34)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_34
        entity.pion_blue_pos[1] = Bleu_Y_34
        entity.texte_texture = pygame.image.load(image_texte_34)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell35(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_35
        entity.pion_red_pos[1] = Rouge_Y_35
        entity.texte_texture = pygame.image.load(image_texte_35)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_35
        entity.pion_blue_pos[1] = Bleu_Y_35
        entity.texte_texture = pygame.image.load(image_texte_35)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell36(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_36
        entity.pion_red_pos[1] = Rouge_Y_36
        entity.texte_texture = pygame.image.load(image_texte_36)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_36
        entity.pion_blue_pos[1] = Bleu_Y_36
        entity.texte_texture = pygame.image.load(image_texte_36)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    son = pygame.mixer.Sound("musics/sound_oie.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell37(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_37
        entity.pion_red_pos[1] = Rouge_Y_37
        entity.texte_texture = pygame.image.load(image_texte_37)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_37
        entity.pion_blue_pos[1] = Bleu_Y_37
        entity.texte_texture = pygame.image.load(image_texte_37)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell38(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_38
        entity.pion_red_pos[1] = Rouge_Y_38
        entity.texte_texture = pygame.image.load(image_texte_38)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_38
        entity.pion_blue_pos[1] = Bleu_Y_38
        entity.texte_texture = pygame.image.load(image_texte_38)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell39(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_39
        entity.pion_red_pos[1] = Rouge_Y_39
        entity.texte_texture = pygame.image.load(image_texte_39)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_39
        entity.pion_blue_pos[1] = Bleu_Y_39
        entity.texte_texture = pygame.image.load(image_texte_39)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell40(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_40
        entity.pion_red_pos[1] = Rouge_Y_40
        entity.texte_texture = pygame.image.load(image_texte_40)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_40
        entity.pion_blue_pos[1] = Bleu_Y_40
        entity.texte_texture = pygame.image.load(image_texte_40)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell41(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_41
        entity.pion_red_pos[1] = Rouge_Y_41
        entity.texte_texture = pygame.image.load(image_texte_41)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_41
        entity.pion_blue_pos[1] = Bleu_Y_41
        entity.texte_texture = pygame.image.load(image_texte_41)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell42(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_42
        entity.pion_red_pos[1] = Rouge_Y_42
        entity.texte_texture = pygame.image.load(image_texte_42)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_42
        entity.pion_blue_pos[1] = Bleu_Y_42
        entity.texte_texture = pygame.image.load(image_texte_42)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    son = pygame.mixer.Sound("musics/sound_thunder.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell43(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_43
        entity.pion_red_pos[1] = Rouge_Y_43
        entity.texte_texture = pygame.image.load(image_texte_43)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_43
        entity.pion_blue_pos[1] = Bleu_Y_43
        entity.texte_texture = pygame.image.load(image_texte_43)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell44(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_44
        entity.pion_red_pos[1] = Rouge_Y_44
        entity.texte_texture = pygame.image.load(image_texte_44)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_44
        entity.pion_blue_pos[1] = Bleu_Y_44
        entity.texte_texture = pygame.image.load(image_texte_44)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell45(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_45
        entity.pion_red_pos[1] = Rouge_Y_45
        entity.texte_texture = pygame.image.load(image_texte_45)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_45
        entity.pion_blue_pos[1] = Bleu_Y_45
        entity.texte_texture = pygame.image.load(image_texte_45)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    son = pygame.mixer.Sound("musics/sound_oie.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell46(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_46
        entity.pion_red_pos[1] = Rouge_Y_46
        entity.texte_texture = pygame.image.load(image_texte_46)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_46
        entity.pion_blue_pos[1] = Bleu_Y_46
        entity.texte_texture = pygame.image.load(image_texte_46)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell47(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_47
        entity.pion_red_pos[1] = Rouge_Y_47
        entity.texte_texture = pygame.image.load(image_texte_47)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_47
        entity.pion_blue_pos[1] = Bleu_Y_47
        entity.texte_texture = pygame.image.load(image_texte_47)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell48(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_48
        entity.pion_red_pos[1] = Rouge_Y_48
        entity.texte_texture = pygame.image.load(image_texte_48)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_48
        entity.pion_blue_pos[1] = Bleu_Y_48
        entity.texte_texture = pygame.image.load(image_texte_48)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell49(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_49
        entity.pion_red_pos[1] = Rouge_Y_49
        entity.texte_texture = pygame.image.load(image_texte_49)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_49
        entity.pion_blue_pos[1] = Bleu_Y_49
        entity.texte_texture = pygame.image.load(image_texte_49)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell50(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_50
        entity.pion_red_pos[1] = Rouge_Y_50
        entity.texte_texture = pygame.image.load(image_texte_50)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_50
        entity.pion_blue_pos[1] = Bleu_Y_50
        entity.texte_texture = pygame.image.load(image_texte_50)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell51(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_51
        entity.pion_red_pos[1] = Rouge_Y_51
        entity.texte_texture = pygame.image.load(image_texte_51)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_51
        entity.pion_blue_pos[1] = Bleu_Y_51
        entity.texte_texture = pygame.image.load(image_texte_51)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell52(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_52
        entity.pion_red_pos[1] = Rouge_Y_52
        entity.texte_texture = pygame.image.load(image_texte_52)
        entity.pion_red_herse_pos = [entity.pion_red_pos[0], entity.pion_red_pos[1]]
    else:
        entity.pion_blue_pos[0] = Bleu_X_52
        entity.pion_blue_pos[1] = Bleu_Y_52
        entity.texte_texture = pygame.image.load(image_texte_52)
        entity.pion_blue_herse_pos = [entity.pion_blue_pos[0], entity.pion_blue_pos[1]]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    son = pygame.mixer.Sound("musics/sound_prison.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell53(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_53
        entity.pion_red_pos[1] = Rouge_Y_53
        entity.texte_texture = pygame.image.load(image_texte_53)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_53
        entity.pion_blue_pos[1] = Bleu_Y_53
        entity.texte_texture = pygame.image.load(image_texte_53)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    son = pygame.mixer.Sound("musics/sound_magic.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell54(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_54
        entity.pion_red_pos[1] = Rouge_Y_54
        entity.texte_texture = pygame.image.load(image_texte_54)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_54
        entity.pion_blue_pos[1] = Bleu_Y_54
        entity.texte_texture = pygame.image.load(image_texte_54)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    son = pygame.mixer.Sound("musics/sound_oie.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell55(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_55
        entity.pion_red_pos[1] = Rouge_Y_55
        entity.texte_texture = pygame.image.load(image_texte_55)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_55
        entity.pion_blue_pos[1] = Bleu_Y_55
        entity.texte_texture = pygame.image.load(image_texte_55)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell56(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_56
        entity.pion_red_pos[1] = Rouge_Y_56
        entity.texte_texture = pygame.image.load(image_texte_56)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_56
        entity.pion_blue_pos[1] = Bleu_Y_56
        entity.texte_texture = pygame.image.load(image_texte_56)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell57(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_57
        entity.pion_red_pos[1] = Rouge_Y_57
        entity.texte_texture = pygame.image.load(image_texte_57)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_57
        entity.pion_blue_pos[1] = Bleu_Y_57
        entity.texte_texture = pygame.image.load(image_texte_57)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell58(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_58
        entity.pion_red_pos[1] = Rouge_Y_58
        entity.texte_texture = pygame.image.load(image_texte_58)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_58
        entity.pion_blue_pos[1] = Bleu_Y_58
        entity.texte_texture = pygame.image.load(image_texte_58)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    son = pygame.mixer.Sound("musics/sound_game_over.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell59(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_59
        entity.pion_red_pos[1] = Rouge_Y_59
        entity.texte_texture = pygame.image.load(image_texte_59)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_59
        entity.pion_blue_pos[1] = Bleu_Y_59
        entity.texte_texture = pygame.image.load(image_texte_59)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell60(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_60
        entity.pion_red_pos[1] = Rouge_Y_60
        entity.texte_texture = pygame.image.load(image_texte_60)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_60
        entity.pion_blue_pos[1] = Bleu_Y_60
        entity.texte_texture = pygame.image.load(image_texte_60)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell61(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_61
        entity.pion_red_pos[1] = Rouge_Y_61
        entity.texte_texture = pygame.image.load(image_texte_61)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_61
        entity.pion_blue_pos[1] = Bleu_Y_61
        entity.texte_texture = pygame.image.load(image_texte_61)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell62(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_62
        entity.pion_red_pos[1] = Rouge_Y_62
        entity.texte_texture = pygame.image.load(image_texte_62)
        entity.pion_red_herse_pos = [-99, -99]
    else:
        entity.pion_blue_pos[0] = Bleu_X_62
        entity.pion_blue_pos[1] = Bleu_Y_62
        entity.texte_texture = pygame.image.load(image_texte_62)
        entity.pion_blue_herse_pos = [-99, -99]
    window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.texte_texture, (560, 55))
    window.blit(entity.des_first_texture, entity.des_first_pos)
    window.blit(entity.des_second_texture, entity.des_second_pos)
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    pass

def cell63(player, entity, window):
    if (player == 3):
        entity.pion_red_pos[0] = Rouge_X_63
        entity.pion_red_pos[1] = Rouge_Y_63
        entity.pion_red_herse_pos = [-99, -99]
        entity.player_winner = 1
    else:
        entity.pion_blue_pos[0] = Bleu_X_63
        entity.pion_blue_pos[1] = Bleu_Y_63
        entity.pion_blue_herse_pos = [-99, -99]
        window.blit(entity.background, (0, 0))
    window.blit(entity.pion_blue_texture, (entity.pion_blue_pos[0], entity.pion_blue_pos[1]))
    window.blit(entity.pion_red_texture,(entity.pion_red_pos[0], entity.pion_red_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_blue_herse_pos[0], entity.pion_blue_herse_pos[1]))
    window.blit(entity.herse_texture,(entity.pion_red_herse_pos[0], entity.pion_red_herse_pos[1]))
    son = pygame.mixer.Sound("musics/sound_move_blue.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    son = pygame.mixer.Sound("musics/sound_win.wav")
    son.play(loops=0, maxtime=0, fade_ms=0)
    pygame.display.flip()
    entity.player_winner = player