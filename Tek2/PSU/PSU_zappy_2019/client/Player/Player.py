import queue
import uuid
import sys
import re
import time
import datetime
from enumDirection import EnumDir
from Interpreter import Interpreter
from Survive.Survive import Survive
from Action import Action
from Incantation.Incantation import Incantation

class Player:
    from Player.survive import handleNeed, move, handlingTakeObject, followInstruction, fetch, goToIncantationRdv
    from Player.action import look, getInventory, checkFoodAndInventory, connectedNbr, fork, eject, takeObject, setObjectDown, broadcast, fork, askParent, respParent
    from Player.prologue import askDirection
    from Player.incantation import helpIncantation, callTeamMates, checkEnoughPlayer, incantation, getCoo
    from Player.communication import messageTreater, handleIncantationMessage, checkNewMessage

    def __init__(self, teamName, interpreter, xMax, yMax, nbSlotTeamMember):
        self.interpreter = interpreter
        self.survive = Survive()
        self.incant = Incantation()
        self.action = Action(xMax, yMax, self.interpreter)
        self.nbTeamMember = 0
        self.supposedNbSlotTeamMember = nbSlotTeamMember
        self.nbSlotTeamMember = nbSlotTeamMember
        self.teamName = teamName
        self.worldMap = []
        self.queueNotif = queue.Queue()
        self.uuid = str(uuid.uuid4())
        self.childHatched = False
        self.nbWrongMessage = 0
        self.need = {}
        self.die = False
        # ["start"] = datetime.datetime.now()
        # [""]

    def mainLoop(self):
        self.askDirection()
        print("enter")
        while self.interpreter.isDead() == False:
            if self.die:
                continue
            self.messageTreater(False)
            # if self.timeCount > 49:
            self.checkNewMessage()
            self.messageTreater(False)#to clean potential send broadcast message

            # if self.incantationHelp["status"] == 1:
            #     if self.moveToEvolve() is False:
            #         self.incantationHelp["status"] = 2
            #         message = [self.teamName, "incantation", self.incantationData["uuid"], self.uuid, "arrived"]
            #         self.broadcast(' '.join(message))
            
            self.handleNeed()
        if self.interpreter.isDead():
            print("dead")
        print("Closing bot", file=sys.stderr)

