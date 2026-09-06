import datetime
import time


class Survive:
    from Survive.need import enoughTimeUnit, checkHungry
    from Survive.path import setNewPath, isHere, randomMove, getInstruction, hasTarget, checkIfWeCanChange, resetNeed

    def __init__(self):
        self.oneUnitTime = {}
        self.nbTimeUnit = 1260
        self.startingTime = datetime.datetime.now()
        self.wantedObject = "food"
        self.need = {
            "randomPath": None,
            "path": None,
            "graph": None
        }
        self.startCollect = True

    def getOneTimeUnit(self):
        print(self.oneUnitTime["value"])
        return self.oneUnitTime["value"]

    def startChrono(self): #for oneUnitTime
        self.oneUnitTime["start"] = datetime.datetime.now()

    def stopChrono(self, value, fail = False):
        if fail:
            return False
        now = datetime.datetime.now()
        self.oneUnitTime["value"] = (now - self.oneUnitTime["start"]).total_seconds() / value
        self.oneUnitTime["value"] /= 10
        return True

    def getTimeUnitLeft(self):
        print((datetime.datetime.now() - self.startingTime).total_seconds())
        left = self.nbTimeUnit - (datetime.datetime.now() - self.startingTime).total_seconds() // self.oneUnitTime["value"]
        print("time unit left {}".format(left))
        return left

    def getWantedObject(self):
        return self.wantedObject

    def addFood(self):
        self.nbTimeUnit += 126