import random

def newBrick(x, y, width, height, hp, color):
    return {"x": x, "y": y, "width": width, "height": height, "hp": hp, "color": color}


class Entities:
    def __init__(self):
        self.PlayerOne.x = 0
        self.PlayerOne.y = 590
        self.PlayerOne.width = 80
        self.PlayerOne.height = 5
        self.PlayerOne.color = (0, 0, 255)
        self.Ball.x = 270
        self.Ball.y = 510
        self.Ball.width = 5
        self.Ball.height = 5
        self.Ball.color = (255, 255, 255)
        self.Ball.vector = [random.randint(-5, 5), random.randint(-5, -1)]
        self.listBrick = [
            newBrick(50, 50, 50, 50, 1, (0, 0, 255)),
            newBrick(150, 50, 50, 50, 2, (20, 100, 255)),
            newBrick(250, 50, 50, 50, 2, (20, 100, 255)),
            newBrick(350, 50, 50, 50, 2, (20, 100, 255)),
            newBrick(450, 50, 50, 50, 1, (20, 100, 255)),

            newBrick(50, 150, 50, 50, 2, (20, 100, 255)),
            newBrick(150, 150, 50, 50, 3, (20, 100, 255)),
            newBrick(250, 150, 50, 50, 3, (20, 100, 255)),
            newBrick(350, 150, 50, 50, 3, (20, 100, 255)),
            newBrick(450, 150, 50, 50, 2, (20, 100, 255)),


            newBrick(50, 250, 50, 50, 1, (20, 100, 255)),
            newBrick(150, 250, 50, 50, 2, (20, 100, 255)),
            newBrick(250, 250, 50, 50, 2, (20, 100, 255)),
            newBrick(350, 250, 50, 50, 2, (20, 100, 255)),
            newBrick(450, 250, 50, 50, 1, (20, 100, 255)),
        ]

    class PlayerOne:
        x = 0
        y = 0
        width = 80
        height = 5
        color = (0, 0, 255)

    class Ball:
        x = 270
        y = 510
        width = 5
        height = 5
        color = (255, 255, 255)
        vector = [random.randint(-5, 5), random.randint(-5, -1)]

    listBrick = []
