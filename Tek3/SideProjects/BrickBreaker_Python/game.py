import pygame
from pygame.locals import *
from entities import *


movingValue = 35
dmgValue = 1
FPS = 60

def checkWin(listBrick):
    for el in listBrick:
        if (el.get("hp") > 0):
            return False
    return True

def movePlayer(Player, IsUp):
    if (IsUp):
        Player.x += movingValue
        if (Player.x + Player.width > 550):
            Player.x = 550 - Player.width
    else:
        Player.x -= movingValue
        if (Player.x < 0):
            Player.x = 0
    return Player

def handleBricks(listBrick, Ball):
    # x1 > _x && x1 < (_x + _width) && y1 - 30 > _y && y1 - 30 < (_y + _height);
    for el in listBrick:
        if (el.get("hp") > 0 and (Ball.x - Ball.width) > el.get("x") and (Ball.x - Ball.width) < (el.get("x") + el.get("width")) and
            (Ball.y - Ball.height) > el.get("y") and (Ball.y - Ball.height) < (el.get("y") + el.get("height"))):
            el["hp"] = el.get("hp") - dmgValue

    for el in listBrick:
        if (el.get("hp") <= 1):
            el["color"] = (159, 252, 72);
        elif (el.get("hp") <= 2):
            el["color"] = (252, 192, 72);
        elif (el.get("hp") <= 4):
            el["color"] = (252, 118, 72);
        elif (el.get("hp") <= 6):
            el["color"] = (255, 00, 00);

def moveBall(Ball, PlayerOne, listBrick):
    Ball.x += Ball.vector[0]
    Ball.y += Ball.vector[1]

    if (Ball.y + Ball.vector[1] <= 0):
        Ball.vector[1] = -Ball.vector[1]
    if (Ball.x + Ball.vector[0] <= 0):
        Ball.vector[0] = -Ball.vector[0]
    if (Ball.x + Ball.vector[0] >= 550):
        Ball.vector[0] = -Ball.vector[0]

    if (Ball.y + Ball.vector[1] >= 590 and Ball.y <= 600):
        if (Ball.x >= PlayerOne.x and Ball.x <= PlayerOne.x + PlayerOne.width):
            Ball.vector[1] = -Ball.vector[1]

    for el in listBrick:
        if (el.get("hp") > 0 and (Ball.x - Ball.width) > el.get("x") and (Ball.x - Ball.width) < (el.get("x") + el.get("width")) and
            (Ball.y - Ball.height) > el.get("y") and (Ball.y - Ball.height) < (el.get("y") + el.get("height"))):
            if (Ball.x < el.get("x")):
                Ball.vector[1] = -Ball.vector[1]
            if (Ball.x > el.get("x")):
                Ball.vector[1] = -Ball.vector[1]
            elif (Ball.y < el.get("y")):
                Ball.vector[0] = -Ball.vector[0]
            elif (Ball.y > el.get("y")):
                Ball.vector[0] = -Ball.vector[0]
            else:
                Ball.vector[1] = -Ball.vector[1]
                Ball.vector[0] = -Ball.vector[0]

    if (Ball.vector[0] <= 0):
        Ball.vector[0] -= 0.001
    else:
        Ball.vector[0] += 0.001
    if (Ball.vector[1] <= 0):
        Ball.vector[1] -= 0.001
    else:
        Ball.vector[1] += 0.001
    # movingValue = movingValue + 0.002

def gameLoop(window, loopMain):
    loop_game = True
    while loop_game and loopMain:
        window = pygame.display.set_mode((550, 600))
        entity = Entities()

        while loop_game and loopMain:
            if (entity.Ball.y >= 600):
                return (0)
            if (checkWin(entity.listBrick)):
                return (1)
            pygame.time.Clock().tick(FPS)
            window.fill((0, 0, 0))

            for event in pygame.event.get():
                if event.type == QUIT or event.type == KEYDOWN and event.key == K_ESCAPE:
                    loopMain = False
                    return -1

                elif event.type == pygame.KEYDOWN:
                    if event.key == K_q or event.key == K_LEFT:
                        entity.PlayerOne = movePlayer(entity.PlayerOne, False)
                    elif event.key == K_d or event.key == K_RIGHT:
                        entity.PlayerOne = movePlayer(entity.PlayerOne, True)

            handleBricks(entity.listBrick, entity.Ball)
            moveBall(entity.Ball, entity.PlayerOne, entity.listBrick)

            for el in entity.listBrick:
                if (el.get("hp") > 0):
                    pygame.draw.rect(window, el.get("color"), pygame.Rect((el.get("x"), el.get("y"), el.get("width"), el.get("height"))))
            pygame.draw.rect(window, entity.PlayerOne.color, pygame.Rect((entity.PlayerOne.x, entity.PlayerOne.y, entity.PlayerOne.width, entity.PlayerOne.height)))
            pygame.draw.circle(window, entity.Ball.color, [entity.Ball.x, entity.Ball.y], entity.Ball.width)
            pygame.display.flip()
    return -1