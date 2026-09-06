from parse import parseLook
from pathFinding import getPath
from random import random, seed
from enumDirection import EnumDir

def handlingTakeObject(self, obj, inst):
    if inst[2] == 0:
        print("rescue during the path")
        self.takeObject(obj)
    else:
        node = inst[2]
        quantity = node[obj]
        while quantity != 0:
            self.takeObject(obj)
            quantity -= 1
        #takeObject loop
        #l'utile à l'agreable
        list = self.incant.getListMissingResource()
        print("list = ", list)
        match = next((key for key, value in list.items() if node[key] != 0), None)
        # print(match)
        if match != None:
            ret = self.takeObject(match)
            print("takeObject match = ", match)
            if ret == "ok":
                print("add obj = ", obj)
            #call incantation method

def move(self, inst):
    # print("instruction = {}".format(inst[1]))
    if inst[1] == "takeObject":
        self.handlingTakeObject(self.survive.getWantedObject(), inst)
    if inst[1] == "Left":
        self.action.turnLeft()
    if inst[1] == "Right":
        self.action.turnRight()
    if inst[1] == "Up":
        self.action.moveUp()

def followInstruction(self):
    # ici qu'on suit les instruction du graph
    while not self.interpreter.isDead():
        inst = self.survive.getInstruction(self.action.getDir())
        if inst == None:
            break
        self.move(inst)
    while self.interpreter.getNbSendMessages() != 0 and not self.interpreter.isDead():
        print(self.interpreter.getNbSendMessages())
        self.interpreter.getAnswer()

def fetch(self):
    print("enter in rescue way")
    while not self.interpreter.isDead():
        inst = self.survive.getInstruction(self.action.getDir())
        if inst == None:
            break
        self.move(inst)
        self.messageTreater()
        if self.survive.checkIfWeCanChange(self.look(), self.incant.getLevel()) == True:
            return self.followInstruction()

def goToIncantationRdv(self):
    while not self.interpreter.isDead():
        inst = self.incant.getInstruction(self.action.getDir())
        if inst == None:
            break
        self.move(inst)
    while self.interpreter.getNbSendMessages() != 0 and not self.interpreter.isDead():
        print(self.interpreter.getNbSendMessages())
        self.interpreter.getAnswer()
    if not self.incant.isOrganizer():
        #send broadcast
        message = [self.teamName, "incantation", self.incant.getUuid(), "arrived"]
        self.broadcast(" ".join(message))
        return self.messageTreater()

def handleNeed(self):
    if self.incant.hasPath():
        self.goToIncantationRdv()
    if self.incant.inProcess() and self.incant.isOrganizer() and self.incant.isAllArrived():
        message = [self.teamName, "incantation", self.incant.getUuid(), "start"]
        self.broadcast(" ".join(message))
        if self.incantation() != "ok":
            return True
        self.incant.resetIncantationData()
    if self.incant.inProcess() and not self.incant.isOrganizer():
        #do nothing and wait
        return
    # if not self.survive.hasTarget():
    #if self.survive.checkHungry() == False and self.incant.checkEnoughResource() and self.incant.getLevel() == 1:
    if not self.survive.checkHungry() and self.incant.checkEnoughResource():
        self.checkEnoughPlayer()
    if self.survive.checkHungry() and self.survive.getWantedObject() != "food" or not self.survive.hasTarget():
        print("new path")
        tmp = self.look()
        print("tmp = ", tmp)
        ret = self.survive.setNewPath(tmp, "food", self.action.getPos(), self.action.getPosMax(), self.incant.getLevel())
        if ret == False:
            self.fetch()
        else:
            self.followInstruction()