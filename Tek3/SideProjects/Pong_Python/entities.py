import random

class Entities:
    def __init__(self):
        self.PlayerOne.x = 0
        self.PlayerOne.y = 250
        self.PlayerOne.width = 5
        self.PlayerOne.height = 50
        self.PlayerOne.color = (0, 0, 255)
        self.PlayerTwo.x = 1044
        self.PlayerTwo.y = 250
        self.PlayerTwo.width = 5
        self.PlayerTwo.height = 50
        self.PlayerTwo.color = (255, 0, 0)
        self.Ball.x = 520
        self.Ball.y = 250
        self.Ball.width = 5
        self.Ball.height = 5
        self.Ball.color = (255, 255, 255)
        self.Ball.vector = [random.randint(-5, 5), random.randint(-5, 5)]

    class PlayerOne:
        x = 0
        y = 0
        width = 5
        height = 50
        color = (0, 0, 255)

    class PlayerTwo:
        x = 1044
        y = 0
        width = 5
        height = 50
        color = (255, 0, 0)

    class Ball:
        x = 520
        y = 250
        width = 5
        height = 5
        color = (255, 255, 255)
        vector = [random.randint(-5, 5), random.randint(-5, 5)]
