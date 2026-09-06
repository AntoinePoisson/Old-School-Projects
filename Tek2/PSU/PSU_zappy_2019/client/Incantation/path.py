from pathFinding import getPath
from Survive.path import reorientation

def setRdvPath(self, currentPos, finalPos, posMax):
    self.incantationData["path"] = getPath(currentPos, finalPos, posMax)

def hasPath(self):
    if "path" in self.incantationData:
        return True
    else:
        return False

def getInstruction(self, currentDir):
    associativeArray = {"Up": EnumDir.UP, "Down": EnumDir.DOWN, "Left": EnumDir.LEFT, "Right": EnumDir.RIGHT}
    for key, value in self.incantationData["path"].items():
        if value != 0:
            if associativeArray[key] != currentDir:
                inst = reorientation(key, currentDir)
                return inst
            else:
                self.incantationData["path"][key] -= 1
                return "Up"
    return None

