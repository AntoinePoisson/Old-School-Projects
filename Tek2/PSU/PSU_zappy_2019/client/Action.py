from enumDirection import EnumDir

class Action:
    def __init__(self, xmax, ymax, interpreter):
        self.interpreter = interpreter
        self.dir = EnumDir.UP
        self.pos = {
            "x": 0,
            "y": 0
        }
        self.posMax = {
            "x": xmax,
            "y": ymax
        }

    def getPosMax(self):
        return self.posMax

    def getPos(self):
        return self.pos

    def getDir(self):
        return self.dir

    def setDir(self, dir):
        self.dir = dir

    def setDirAtBirth(self, diff):
        if diff == 6:
            self.dir = EnumDir.LEFT
        if diff == 4:
            self.dir = EnumDir.DOWN
        if diff == 2:
            self.dir = EnumDir.RIGHT

    def moveInDirection(self, dir):
        if self.dir == EnumDir.UP:
            if dir == EnumDir.UP:
                self.moveUp()
            elif dir == EnumDir.DOWN:
                self.turnLeft()
            elif dir == EnumDir.LEFT:
                self.turnRight()
            elif dir == EnumDir.RIGHT:
                self.turnLeft()
        elif self.dir == EnumDir.DOWN:
            if dir == EnumDir.UP:
                self.turnLeft()
            elif dir == EnumDir.DOWN:
                self.moveUp()
            elif dir == EnumDir.LEFT:
                self.turnLeft()
            elif dir == EnumDir.RIGHT:
                self.turnRight()
        elif self.dir == EnumDir.LEFT:
            if dir == EnumDir.UP:
                self.turnRight()
            elif dir == EnumDir.DOWN:
                self.turnLeft()
            elif dir == EnumDir.LEFT:
                self.moveUp()
            elif dir == EnumDir.RIGHT:
                self.turnLeft()
        elif self.dir == EnumDir.RIGHT:
            if dir == EnumDir.UP:
                self.turnLeft()
            elif dir == EnumDir.DOWN:
                self.turnRight()
            elif dir == EnumDir.LEFT:
                self.turnLeft()
            elif dir == EnumDir.RIGHT:
                self.moveUp()

    def moveUp(self):
        self.interpreter.send("Forward")
        if self.dir == EnumDir.UP:
            self.pos["y"] = (self.pos["y"] + 1) % self.posMax["y"]
        if self.dir == EnumDir.DOWN:
            self.pos["y"] = (self.pos["y"] - 1) % self.posMax["y"]
        if self.dir == EnumDir.RIGHT:
            self.pos["x"] = (self.pos["x"] + 1) % self.posMax["x"]
        if self.dir == EnumDir.LEFT:
            self.pos["x"] = (self.pos["x"] - 1) % self.posMax["x"]

    def turnLeft(self):
        self.interpreter.send("Left")
        if self.dir == EnumDir.UP:
            self.dir = EnumDir.LEFT
        elif self.dir == EnumDir.DOWN:
            self.dir = EnumDir.RIGHT
        elif self.dir == EnumDir.LEFT:
            self.dir = EnumDir.DOWN
        elif self.dir == EnumDir.RIGHT:
            self.dir = EnumDir.UP

    def turnRight(self):
        self.interpreter.send("Right")
        if self.dir == EnumDir.UP:
            self.dir = EnumDir.RIGHT
        elif self.dir == EnumDir.DOWN:
            self.dir = EnumDir.LEFT
        elif self.dir == EnumDir.LEFT:
            self.dir = EnumDir.UP
        elif self.dir == EnumDir.RIGHT:
            self.dir = EnumDir.DOWN

    def handleEjection(self, tileNumber): #action
        if tileNumber == 1:
            if self.dir == EnumDir.UP:
                self.pos["y"] = (self.pos["y"] - 1) % self.posMax["y"]
            if self.dir == EnumDir.DOWN:
                self.pos["y"] = (self.pos["y"] + 1) % self.posMax["y"]
            if self.dir == EnumDir.LEFT:
                self.pos["x"] = (self.pos["x"] + 1) % self.posMax["x"]
            if self.dir == EnumDir.RIGHT:
                self.pos["x"] = (self.pos["x"] - 1) % self.posMax["x"]
        if tileNumber == 2:
            if self.dir == EnumDir.UP:
                self.pos["y"] = (self.pos["y"] - 1) % self.posMax["y"]
                self.pos["x"] = (self.pos["x"] + 1) % self.posMax["x"]
            if self.dir == EnumDir.DOWN:
                self.pos["y"] = (self.pos["y"] + 1) % self.posMax["y"]
                self.pos["x"] = (self.pos["x"] - 1) % self.posMax["x"]
            if self.dir == EnumDir.LEFT:
                self.pos["y"] = (self.pos["y"] + 1) % self.posMax["y"]
                self.pos["x"] = (self.pos["x"] + 1) % self.posMax["x"]
            if self.dir == EnumDir.RIGHT:
                self.pos["y"] = (self.pos["y"] - 1) % self.posMax["y"]
                self.pos["x"] = (self.pos["x"] - 1) % self.posMax["x"]
        if tileNumber == 3:
            if self.dir == EnumDir.UP:
                self.pos["x"] = (self.pos["x"] + 1) % self.posMax["x"]
            if self.dir == EnumDir.DOWN:
                self.pos["x"] = (self.pos["x"] - 1) % self.posMax["x"]
            if self.dir == EnumDir.LEFT:
                self.pos["y"] = (self.pos["y"] + 1) % self.posMax["y"]
            if self.dir == EnumDir.RIGHT:
                self.pos["y"] = (self.pos["y"] - 1) % self.posMax["y"]
        if tileNumber == 4:
            if self.dir == EnumDir.UP:
                self.pos["y"] = (self.pos["y"] + 1) % self.posMax["y"]
                self.pos["x"] = (self.pos["x"] + 1) % self.posMax["x"]
            if self.dir == EnumDir.DOWN:
                self.pos["y"] = (self.pos["y"] - 1) % self.posMax["y"]
                self.pos["x"] = (self.pos["x"] - 1) % self.posMax["x"]
            if self.dir == EnumDir.LEFT:
                self.pos["y"] = (self.pos["y"] + 1) % self.posMax["y"]
                self.pos["x"] = (self.pos["x"] - 1) % self.posMax["x"]
            if self.dir == EnumDir.RIGHT:
                self.pos["y"] = (self.pos["y"] - 1) % self.posMax["y"]
                self.pos["x"] = (self.pos["x"] + 1) % self.posMax["x"]
        if tileNumber == 5:
            if self.dir == EnumDir.UP:
                self.pos["y"] = (self.pos["y"] + 1) % self.posMax["y"]
            if self.dir == EnumDir.DOWN:
                self.pos["y"] = (self.pos["y"] - 1) % self.posMax["y"]
            if self.dir == EnumDir.LEFT:
                self.pos["x"] = (self.pos["x"] - 1) % self.posMax["x"]
            if self.dir == EnumDir.RIGHT:
                self.pos["x"] = (self.pos["x"] + 1) % self.posMax["x"]
        if tileNumber == 6:
            if self.dir == EnumDir.UP:
                self.pos["y"] = (self.pos["y"] + 1) % self.posMax["y"]
                self.pos["x"] = (self.pos["x"] - 1) % self.posMax["x"]
            if self.dir == EnumDir.DOWN:
                self.pos["y"] = (self.pos["y"] - 1) % self.posMax["y"]
                self.pos["x"] = (self.pos["x"] + 1) % self.posMax["x"]
            if self.dir == EnumDir.LEFT:
                self.pos["y"] = (self.pos["y"] - 1) % self.posMax["y"]
                self.pos["x"] = (self.pos["x"] - 1) % self.posMax["x"]
            if self.dir == EnumDir.RIGHT:
                self.pos["y"] = (self.pos["y"] + 1) % self.posMax["y"]
                self.pos["x"] = (self.pos["x"] + 1) % self.posMax["x"]
        if tileNumber == 7:
            if self.dir == EnumDir.UP:
                self.pos["x"] = (self.pos["x"] - 1) % self.posMax["x"]
            if self.dir == EnumDir.DOWN:
                self.pos["x"] = (self.pos["x"] + 1) % self.posMax["x"]
            if self.dir == EnumDir.LEFT:
                self.pos["y"] = (self.pos["y"] - 1) % self.posMax["y"]
            if self.dir == EnumDir.RIGHT:
                self.pos["y"] = (self.pos["y"] + 1) % self.posMax["y"]
        if tileNumber == 8:
            if self.dir == EnumDir.UP:
                self.pos["y"] = (self.pos["y"] - 1) % self.posMax["y"]
                self.pos["x"] = (self.pos["x"] - 1) % self.posMax["x"]
            if self.dir == EnumDir.DOWN:
                self.pos["y"] = (self.pos["y"] + 1) % self.posMax["y"]
                self.pos["x"] = (self.pos["x"] + 1) % self.posMax["x"]
            if self.dir == EnumDir.LEFT:
                self.pos["y"] = (self.pos["y"] - 1) % self.posMax["y"]
                self.pos["x"] = (self.pos["x"] + 1) % self.posMax["x"]
            if self.dir == EnumDir.RIGHT:
                self.pos["y"] = (self.pos["y"] + 1) % self.posMax["y"]
                self.pos["x"] = (self.pos["x"] - 1) % self.posMax["x"]
