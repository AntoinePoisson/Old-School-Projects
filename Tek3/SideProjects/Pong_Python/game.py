import pygame
from pygame.locals import *
from entities import *


movingValue = 35
FPS = 60


def movePlayerY(Player, IsUp):
    if (IsUp):
        Player.y += movingValue
        if (Player.y + Player.height > 500):
            Player.y = 500 - Player.height
    else:
        Player.y -= movingValue
        if (Player.y < 0):
            Player.y = 0
    return Player

def moveBall(Ball, PlayerOne, PlayerTwo):
    Ball.x += Ball.vector[0]
    Ball.y += Ball.vector[1]

    if (Ball.y + Ball.vector[1] <= 0):
        Ball.vector[1] = -Ball.vector[1]
    if (Ball.y + Ball.vector[1] >= 500):
        Ball.vector[1] = -Ball.vector[1]

    if (Ball.x + Ball.vector[0] <= 5 and Ball.x >= 0):
        if (Ball.y >= PlayerOne.y and Ball.y <= PlayerOne.y + PlayerOne.height):
            Ball.vector[0] = -Ball.vector[0]

    if (Ball.x + Ball.vector[0] >= 1045 and Ball.x <= 1055):
        if (Ball.y >= PlayerTwo.y and Ball.y <= PlayerTwo.y + PlayerTwo.height):
            Ball.vector[0] = -Ball.vector[0]
    if (Ball.vector[0] <= 0):
        Ball.vector[0] -= 0.001
    else:
        Ball.vector[0] += 0.001
    if (Ball.vector[1] <= 0):
        Ball.vector[1] -= 0.001
    else:
        Ball.vector[1] += 0.001

def gameLoop(window, loopMain):
    loop_game = True
    while loop_game and loopMain:
        window = pygame.display.set_mode((1050,500))
        entity = Entities()

        while loop_game and loopMain:
            if (entity.Ball.x < 0):
                return (2)
            if (entity.Ball.x > 1050):
                return (1)
            pygame.time.Clock().tick(FPS)
            window.fill((0, 0, 0))

            for event in pygame.event.get():
                if event.type == QUIT or event.type == KEYDOWN and event.key == K_ESCAPE:
                    loopMain = False
                    return -1

                elif event.type == pygame.KEYDOWN:
                    if event.key == K_z:
                        entity.PlayerOne = movePlayerY(entity.PlayerOne, False)
                        # print("Player 1: UP ", entity.PlayerOne.y)
                    elif event.key == K_s:
                        entity.PlayerOne = movePlayerY(entity.PlayerOne, True)
                        # print("Player 1: Down ", entity.PlayerOne.y)
                    elif event.key == K_UP:
                        entity.PlayerTwo = movePlayerY(entity.PlayerTwo, False)
                        # print("Player 2: UP ", entity.PlayerTwo.y)
                    elif event.key == K_DOWN:
                        entity.PlayerTwo = movePlayerY(entity.PlayerTwo, True)
                        # print("Player 2: Down ", entity.PlayerTwo.y)

            moveBall(entity.Ball, entity.PlayerOne, entity.PlayerTwo)

            pygame.draw.rect(window, entity.PlayerOne.color, pygame.Rect((entity.PlayerOne.x, entity.PlayerOne.y, entity.PlayerOne.width, entity.PlayerOne.height)))
            pygame.draw.rect(window, entity.PlayerTwo.color, pygame.Rect((entity.PlayerTwo.x, entity.PlayerTwo.y, entity.PlayerTwo.width, entity.PlayerTwo.height)))
            pygame.draw.circle(window, entity.Ball.color, [entity.Ball.x, entity.Ball.y], entity.Ball.width)
            pygame.display.flip()
    return -1