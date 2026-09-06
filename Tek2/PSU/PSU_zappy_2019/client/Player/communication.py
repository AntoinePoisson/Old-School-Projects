import sys
import datetime


def handleIncantationMessage(self, arr_message):
    if len(arr_message) == 7 and arr_message[3] == "ask" and int(arr_message[4]) == self.incant.getLevel():
        return self.helpIncantation(arr_message[2], {"x": int(arr_message[4]), "y": int(arr_message[5])})
    if self.incant.getStatusIncantation() == None:
        return
    uuid = self.incant.getUuid()
    if arr_message[2] != uuid:
        return
    # finalpos, pos, arrived, start, done, cancelled
    if arr_message[3] == "cancelled":
        return self.incant.resetIncantationData()
    if arr_message[3] == "done":
        return self.incant.resetIncantationData()
    if arr_message[3] == "come":
        #have to send coo
        pos = self.action.getPos()
        message = [self.teamName, "incantation", uuid, "pos", str(pos["x"]), str(pos["y"])]
        self.broadcast(' '.join(message))
        # self.incant.setIncantationStatus("come")
    if arr_message[3] == "start":
        #reset time for relaunch
        self.incant.setIncantationStatus("start")
        if not self.incantation():
            print("INCANTATION HELP FAILED", file=sys.stderr)
        self.incant.resetIncantationData()
    if arr_message[3] == "finalpos":
        print("setPath")
        pos = {"x": int(arr_message[4]), "y": int(arr_message[5])}
        self.incant.setIncantationStatus("come")
        self.incant.setRdvPath(self.action.getPos(), pos, self.action.getPosMax())
    if arr_message[3] == "arrived"  and self.incant.isOrganizer():
        #check
        self.incant.oneArrivedToRdv()



def checkNewMessage(self):
    while not self.interpreter.noNotif():
        message, pos = self.interpreter.getBroadcastMessage()
        arr_message = message.split()
        if arr_message[0] != self.teamName:
            continue
        if len(arr_message) == 3 and arr_message[1] == "child" and self.childHatched == False and arr_message[2].isdigit():
            if self.supposedNbSlotTeamMember != int(arr_message[2]):
                message = [self.teamName, "DIE"]
                self.broadcast(" ".join(message))
                self.supposedNbSlotTeamMember -= 1
            else:
                if self.respParent(pos, self.action.getDir()) == "ok":
                    self.childHatched = True
        if len(arr_message) > 2 and arr_message[1] == "incantation":
            self.handleIncantationMessage(arr_message)
    return False

def messageTreater(self, waitServerAnswer = True):
    answer = ""
    while answer == "" and not self.interpreter.isDead():
        messages = self.interpreter.getAnswer()
        for i, message in enumerate(messages):
            if "eject" in message:
                messages.pop(i)
                self.handleEjection(int(message.split(",")[1]))
            else:
                if answer != "":
                    print("error 2 reply server received")
                    raise Exception()
                answer = message
        if waitServerAnswer == False:
            break
    # if answer == "" and waitServerAnswer:
        # print("no server's reply")
        # return self.messageTreater()
    return answer