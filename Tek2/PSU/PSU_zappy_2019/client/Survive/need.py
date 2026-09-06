def enoughTimeUnit(self, value):
    if value > self.getTimeUnitLeft():
        return False
    return True

def checkHungry(self):
    if self.startCollect:
        if self.enoughTimeUnit(5000) == True:
            self.startCollect = False
            return False
        else:
            return True
    if self.startCollect == False:
        if self.enoughTimeUnit(4000):
            return False
        else:
            self.startCollect = True
            return True
    # return self.enoughTimeUnit(200)

