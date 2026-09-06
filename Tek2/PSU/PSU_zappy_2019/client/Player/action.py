from enumDirection import EnumDir

def look(self):
    self.interpreter.send("Look")
    return self.messageTreater()

def getInventory(self):
    self.interpreter.send("Inventory")
    # self.inventory = self.messageTreater()
    return self.messageTreater()

def checkFoodAndInventory(self):
    inventory = self.getInventory()
    if inventory.split()[0] == "[food":
        if int(inventory.split()[1].split(",")[0]) > 8:
            self.incant.updateInventory(inventory)
            return True
    return False

def connectedNbr(self):
    self.interpreter.send("Connect_nbr")
    self.nbSlotTeamMember = self.messageTreater()

def fork(self):
    self.interpreter.send("Fork")

def eject(self):
    self.interpreter.send("Eject")
    return self.messageTreater()

def takeObject(self, obj):  # obj = linemate, deraumere, sibur, mendiane, phiras, thystame
    print("takeObject OBJ = ", obj)
    self.interpreter.send("Take {}".format(obj))
    if obj == "food":
        self.survive.addFood()
    else:
        self.incant.addObj(obj)
    # if self.messageTreater() == "ok":
    #     if obj != "food":
    #         self.incant.addObj(obj)
    #     return "ok"
    # else:
    #     return "ko"


def setObjectDown(self, obj):  # obj = linemate, deraumere, sibur, mendiane, phiras, thystame
    self.interpreter.send("Set ", obj)
    if self.messageTreater() == "ok":
        self.inventory[obj] -= 1
        return "ok"
    else:
        return "ko"

def broadcast(self, text):
    message = '{} {}'.format("Broadcast", text)
    self.interpreter.send(message)
    return self.messageTreater()

def askParent(self):
    message = [self.teamName, "child", self.uuid]
    return self.broadcast(" ".join(message))

def respParent(self, pos, currentDir):
    tmp = (pos + 4) % 8
    supposedPos = 1
    if currentDir == EnumDir.LEFT:
        supposedPos = (tmp + 2) % 8
    elif currentDir == EnumDir.DOWN:
        supposedPos = (tmp + 4) % 8
    elif currentDir == EnumDir.RIGHT:
        supposedPos = (tmp + 6) % 8
    else:
        suposedPos = tmp
    message = [self.teamName, "father", str(supposedPos)]
    return self.broadcast(" ".join(message))
