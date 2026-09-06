from enumDirection import EnumDir
from parse import parseLook
from random import random, seed
from pathFinding import getPath

def resetNeed(self):
    self.need = {
        "randomPath": None,
        "path": None,
        "graph": None
    }

def setNewPath(self, lookArray, wantedObject, pos, posMax, lvl):
    self.resetNeed()
    self.wantedObject = wantedObject
    graph, path = parseLook(lookArray, self.wantedObject, lvl)
    if path == None:
        dest = {"x": int(random() * posMax["x"]), "y": int(random() * posMax["y"])}
        self.need["randomPath"] = getPath(pos, dest, posMax)
        return False
    else:
        self.need["path"] = path
        self.need["graph"] = graph
        return True

def isHere(self, lookArray, wantedObject = "other"):
    if wantedObject == "other":
        wantedObject = self.wantedObject
    graph, path = parseLook(lookArray, self.wantedObject)
    if path == []:
        return True
    return False

def reorientation(mapDir, currentDir):
    if currentDir == EnumDir.UP:
        if mapDir == "Down":
            return "Left"
        elif mapDir == "Left":
            return "Left"
        elif mapDir == "Right":
            return "Right"
    if currentDir == EnumDir.DOWN:
        if mapDir == "Up":
            return "Right"
        if mapDir == "Left":
            return "Right"
        if mapDir == "Right":
            return "Left"
    if currentDir == EnumDir.LEFT:
        if mapDir == "Up":
            return "Right"
        if mapDir == "Down":
            return "Left"
        if mapDir == "Right":
            return "Right"
    if currentDir == EnumDir.RIGHT:
        if mapDir == "Up":
            return "Right"
        if mapDir == "Down":
            return "Left"
        if mapDir == "Left":
            return "Right"

def checkIfWeCanChange(self, lookArray, lvl):
    graph, path = parseLook(lookArray, self.wantedObject, lvl)
    if path != None:
        self.resetNeed()
        self.need["path"] = path
        self.need["graph"] = graph
        return True
    return False

def randomMove(self, currentDir):
    associativeArray = {"Up": EnumDir.UP, "Down": EnumDir.DOWN, "Left": EnumDir.LEFT, "Right": EnumDir.RIGHT}
    print(self.need["randomPath"])
    print(currentDir)
    for key, value in self.need["randomPath"].items():
        if value != 0:
            if associativeArray[key] != currentDir:
                inst = reorientation(key, currentDir)
                return inst
            else:
                self.need["randomPath"][key] -= 1
                return "Up"
    return None

def getInstruction(self, currentDir):
    if self.need["path"] == []:
        node = self.need["graph"]
        self.resetNeed()
        return (True, "takeObject", node)
    if self.need["path"]:
        dir = self.need["path"].pop(0)
        return (True, dir, 0)
    elif self.need["randomPath"]:
        inst = self.randomMove(currentDir)
        if inst == None:
            self.need["randomPath"] = None
            return None
        return (False, inst)
    return None

def hasTarget(self):
    if self.need["randomPath"] == None and self.need["graph"] == None:
        return False
    else:
        return True