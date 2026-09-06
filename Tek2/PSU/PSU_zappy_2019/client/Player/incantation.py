import sys
import uuid
import time
from datetime import datetime, timedelta
from pathFinding import getPath
from enumDirection import EnumDir
from Chrono import Chrono

def incantation(self):
    if not self.checkFoodAndInventory():
        print("INCANT NOT ENOUGTH RESOURCE")
        return False
    self.interpreter.send("Incantation")
    ret = self.messageTreater() #elevation underway
    print("FIRST incant = ", ret)
    ret = self.messageTreater()
    print("SECOND incant = ", ret)
    if ret == "ko":
        return False
    else:
        self.incant.useMaterial()
        self.incant.levelUp()
        print(self.getInventory())
        print("SUCCESS", file=sys.stderr)
        return True

def checkEnoughPlayer(self):
    if self.incant.getLevel() == 1:
        print("level 1", file=sys.stderr)
        if not self.incantation():
            print("INCANTATION FAILED", file=sys.stderr)
    else:
        print("more than level 1", file=sys.stderr)
        if self.callTeamMates():
            self.waitForPlayer()

def helpIncantation(self, incantation_uuid, pos):
    if self.survive.checkHungry():
        return False
    if self.incant.getListMissingResource() != None:
        return False
    message = [self.teamName, "incantation", incantation_uuid, "ok"]
    if self.broadcast(" ".join(message)) == "ok":
        self.incant.setIncantationStatus("ok")
        self.incant.setIncantationUuid(incantation_uuid)
        return True
    return False

def getCoo(self, nbAnswer, uuid):
    chrono = Chrono(10 * self.survive.getOneTimeUnit())
    tabPos = []
    while len(tabPos) != nbAnswer and not chrono.done():
        self.messageTreater(False)
        if not self.interpreter.noNotif():
            message, pos = self.interpreter.getBroadcastMessage()
            arr_message = message.split()
            if len(arr_message) == 6 and arr_message[3] == "pos":
                pos = {"x": int(arr_message[4]), "y": int(arr_message[4])}
                tabPos.append(pos)
    if len(tabPos) == nbAnswer:
        x = 0
        y = 0
        for pos, value in tabPos.items():
            if pos == "x":
                x += value
            else:
                y += value
        midpoint = {"x": x / nbAnswer, "y": y / nbAnswer}
        return midpoint
    else:
        return None

def callTeamMates(self):
    incantUuid = str(uuid.uuid4())
    pos = self.action.getPos()

    message = [self.teamName,  "incantation", incantUuid, "ask", str(self.incant.getLevel()), str(pos["x"]), str(pos["y"])]
    self.broadcast(' '.join(message))
    
    nbAnswer = 0
    nbAnswerNeeded = self.incant.getPlayerNbForIncantation()
    # responses = []

    #time.sleep.timeUnit[value]
    chrono = Chrono(5)
    while nbAnswer != nbAnswerNeeded and not chrono.done():
        self.messageTreater(False)
        if not self.interpreter.noNotif():
            message, pos = self.interpreter.getBroadcastMessage()
            arr_message = message.split()
            if arr_message == [self.teamName, "incantation", incantUuid, "ok"]:
                nbAnswer += 1
                # if next((x for x in responses if x == answer[3]), None) is None:
                #     responses.append(answer[3])

    # if nbAnswerNeeded > len(responses):
    # have to clean potential other message that are late
    if nbAnswerNeeded > nbAnswer:
        message = [self.teamName, "incantation", incantUuid, "cancelled"]
        self.broadcast(' '.join(message))
        self.incant.setTimeForRelaunch(self.survive.getOneTimeUnit())
        return False
    else:
        message = [self.teamName, "incantation", incantUuid, "come"]
        self.broadcast(' '.join(message))
        #set coo
        coo = self.getCoo(nbAnswer, incantUuid)
        if coo == None:
            message = [self.teamName, "incantation", incantUuid, "cancelled"]
            self.broadcast(' '.join(message))
            return False

        #send finalpos
        message = [self.teamName, "incantation", incantUuid, "finalpos", str(coo["x"]), str(coo["y"])]
        self.broadcast(' '.join(message))        

        self.incant.setIncantationStatus("come")
        self.incant.setIncantationUuid(incantUuid)
        self.incant.setOrganizer()
        return True

# def waitForPlayer(self):
#     self.nbWrongMessage = 0
#     while not self.interpreter.isDead() and not self.checkTeamMatesArrived():
#         self.checkNewMessage()
#         if self.nbWrongMessage >= self.queueNotif.size():
#             return
#     self.nbWrongMessage = 0
#     if not self.incantation():
#         print("INCANTATION FAILED", file=sys.stderr)  # TODO rip y a un des check qui a pas marché

# def checkTeamMatesArrived(self):
#     self.incantationData["nbArrived"] = 0
#     self.incantationData["uuidArrived"] = None
#     nbArrivedNeeded = self.inventory[self.level]["players"]

#     self.getAnswer()
#     if self.incantationData["nbArrived"] != nbArrivedNeeded:
#         message, pos = self.getBroadcastMessage()
#         if message is not None:
#             answer = message.split()
#             if len(answer) == 5 and answer[0] == self.teamName and answer[1] == "incantation" and answer[2] == self.incantationData["uuid"] and answer[4] == "arrived":
#                 if answer[3] not in self.incantationData["uuidArrived"]:
#                     self.incantationData["uuidArrived"].append(answer[3])
#                     self.incantationData["nbArrived"] += 1
#                     self.nbWrongMessage = 0
#                 else:
#                     self.queueNotif.put("message " + str(pos) + "," + message)
#                     self.nbWrongMessage += 1
#         return False
#     else:
#         message = [self.teamName, "incantation", self.incantationData["uuid"], "start"]
#         self.broadcast(' '.join(message))
#         self.incantationData["start"] = True
#         self.incantationData["nbArrived"] = 0
#         self.incantationData["uuidArrived"] = None
#     return True

# def moveToEvolve(self):
#     if self.checkHungry():
#         self.searchFood()
#     if "Up" in self.incantationHelp["path"]:
#         if self.incantationHelp["path"]["Up"] > 0:
#             self.incantationHelp["path"]["Up"] -= 1
#             self.moveInDirection(EnumDir.UP)
#             return True
#     if "Down" in self.incantationHelp["path"]:
#         if self.incantationHelp["path"]["Down"] < 0:
#             self.incantationHelp["path"]["Down"] -= 1
#             self.moveInDirection(EnumDir.DOWN)
#             return True
#     if "Right" in self.incantationHelp["path"]:
#         if self.incantationHelp["path"]["Right"] > 0:
#             self.incantationHelp["path"]["Right"] -= 1
#             self.moveInDirection(EnumDir.RIGHT)
#             return True
#     if "Left" in self.incantationHelp["path"]:
#         if self.incantationHelp["path"]["Left"] < 0:
#             self.incantationHelp["path"]["Left"] -= 1
#             self.moveInDirection(EnumDir.LEFT)
#             return True
#     return False


