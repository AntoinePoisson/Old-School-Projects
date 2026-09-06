import queue
from Client import Client

class Interpreter:
    def __init__(self, client):
        self.client = client
        self.queueNotif = queue.Queue()
        self.messages = queue.Queue()
        self.sendMessages = 0
        self.dead = False

    def isDead(self):
        return self.dead

    def getNotif(self): #None ou element de la queue
        if self.queueNotif.empty():
            return None
        return self.queueNotif.get()

    def noNotif(self):
        return self.queueNotif.empty()

    def getNbSendMessages(self):
        return self.sendMessages

    def decreaseSendMessages(self):
        if self.sendMessages > 0:
            self.sendMessages -= 1
            return True
        else:
            return False


    def send(self, message):
        message += '\n'
        if self.sendMessages < 10:
            self.sendMessages += 1
            self.client.send(message)
            return True
        else:
            self.messages.put(message)
    def sendWaitingMessage(self):
        if not self.messages.empty():
            self.sendMessages += 1
            self.client.send(self.messages.get())
            return True
        else:
            return False

    def getAnswer(self):
        messages = []
        arr_message = []
        answer = self.client.non_block_read()
        if len(answer):
            arr_message = answer.split("\n")
        for message in arr_message:
            if message == "":
                continue
            if "message" in message:
                self.queueNotif.put(message)
            elif "dead" in message:
                self.dead = True
            else:
                # print("receive {}".format(message))
                if not "eject" in message:
                    self.decreaseSendMessages()
                    if not self.messages.empty():
                        self.sendWaitingMessage()
                messages.append(message)
        # print(arr_message)
        return messages

    def read(self):
        value = self.client.read()
        # self.sendMessages -= 1
        return value

    def getBroadcastMessage(self):
        message = None
        pos = 0
        answer = self.getNotif().split(",")

        if len(answer) == 2 and answer[0].split()[1].isdigit() and 0 < int(answer[0].split()[1]) < 9:
            message = answer[1]
            pos = int(answer[0].split()[1])
        return message, pos