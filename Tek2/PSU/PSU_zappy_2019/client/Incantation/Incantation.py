import uuid
from Chrono import Chrono

class Incantation:
    from Incantation.path import setRdvPath, hasPath, getInstruction

    def __init__(self):
        self.level = 1
        # self.incantationHelp = {}
        self.incantationData = {}
        self.timeForRelaunch = None
        self.inventory = {
            "linemate": 0,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0,
        }
        self.incantationResource = {
            "1": {
                "players": 0,
                "linemate": 1,
                "deraumere": 0,
                "sibur": 0,
                "mendiane": 0,
                "phiras": 0,
                "thystame": 0,
            },
            "2": {
                "players": 1,
                "linemate": 1,
                "deraumere": 1,
                "sibur": 1,
                "mendiane": 0,
                "phiras": 0,
                "thystame": 0,
            },
            "3": {
                "players": 1,
                "linemate": 2,
                "deraumere": 0,
                "sibur": 1,
                "mendiane": 0,
                "phiras": 2,
                "thystame": 0,
            },
            "4": {
                "players": 3,
                "linemate": 1,
                "deraumere": 1,
                "sibur": 2,
                "mendiane": 0,
                "phiras": 1,
                "thystame": 0,
            },
            "5": {
                "players": 3,
                "linemate": 1,
                "deraumere": 2,
                "sibur": 1,
                "mendiane": 3,
                "phiras": 0,
                "thystame": 0,
            },
            "6": {
                "players": 5,
                "linemate": 1,
                "deraumere": 2,
                "sibur": 3,
                "mendiane": 0,
                "phiras": 1,
                "thystame": 0,
            },
            "7": {
                "players": 5,
                "linemate": 2,
                "deraumere": 2,
                "sibur": 2,
                "mendiane": 2,
                "phiras": 2,
                "thystame": 1,
            }
        }

    def getLevel(self):
        return self.level

    def addObj(self, obj):
        if obj in self.inventory:
            self.inventory[obj] += 1
            return True
        return False

    def subObj(self, obj):
        if obj in self.inventory and self.inventory[obj] > 0:
            self.inventory[obj] -= 1
            return True
        return False

    def levelUp(self):
        self.level += 1

    def checkEnoughResource(self):
        for key, value in self.incantationResource[str(self.level)].items():
            if key != "players" and value > self.inventory[key]:
                return False
        return True

    def useMaterial(self):
        print("useMaterial  ======== ", self.inventory)
        for key, value in self.incantationResource[str(self.level)].items():
            if key != "players":
                self.inventory[key] -= value

    def getListMissingResource(self):
        needed = {}
        for key, value in self.incantationResource[str(self.level)].items():
            if key != "players" and value > self.inventory[key] :
                needed[key] = value - self.inventory[key]
        # if needed is None and timeCount < 800:
        #     if (800 - timeCount) / 126 == (800 - timeCount) // 126:
        #         needed["food"] = (800 - timeCount) // 126
        #     else:
        #         needed["food"] = (800 - timeCount) // 126 + 1
        return needed

    def updateInventory(self, inventory):
        actual = inventory.replace('[', '').replace(']', '').split(',')
        for material in actual:
            arr = material.split()
            if arr[0] != "food" and arr[0] in self.inventory and arr[1].isdigit() and self.inventory[arr[0]] != int(arr[1]):
                self.inventory[arr[0]] = int(arr[1])
        print("TRUE INVENTORY = ", self.inventory)
        print("command inventory = ", inventory)
        return self.checkEnoughResource()

    
    def setTimeForRelaunch(self, timeUnit):
        deltaT = timeUnit * 500
        self.timeForRelaunch = Chrono(deltaT)
        return True
    
    def timeForIncantation(self):
        if self.timeForRelaunch != None and not self.timeForRelaunch.done():
            return False
        if self.checkEnoughResource() == False:
            return False
        return True

    def getUuid(self):
        if self.incantationData == {}:
            None
        else:
            return self.incantation["uuid"]
    
    def getStatusIncantation(self):
        if "status" in self.incantationData:
            return self.incantationData["status"]
        return None

    def setIncantationStatus(self, str):
        #come, wait, start
        self.incantationData["status"] = str

    def setIncantationUuid(self, str):
        self.incantationData["uuid"] = str
    
    def resetIncantationData(self):
        self.incantationData = {}
   
    def setOrganizer(self):
        self.incantationData["isOrganizer"] = True
        self.incantationData["nb_arrived"] = self.incantationResource[str(self.level)]["players"]

    def isOrganizer(self):
        if self.incantationData["isOrganizer"]:
            return True
        return False

    def oneArrivedToRdv(self):
        self.incantationData["nb_arrived"] -= 1

    def isAllArrived(self):
        if "nb_arrived" in self.incantationData and self.incantationData["nb_arrived"] == 0:
            return True
        else:
            return False
    
    def inProcess(self):
        if "status" in self.incantationData and self.incantationData["status"] == "come":
            return True
        else:
            return False
    
    def getPlayerNbForIncantation(self):
        return self.incantationResource[str(self.level)]["players"]
    # def getIncantationUuid()

    # def initVariable(self):

    # def initIncantationVariable(self):
    #     self.incantationData["uuid"] = str(uuid.uuid4())

    # def getIncantionUuid(self):
    #     if incantationData == {}:
    #         return None 
    #     else:
    #         return incantation["uuid"]