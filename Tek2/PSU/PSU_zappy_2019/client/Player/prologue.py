import datetime
from enumDirection import EnumDir
from Chrono import Chrono

def askDirection(self):
    self.survive.startChrono() #catch time
    message = self.askParent()
    self.survive.stopChrono(7)

    chrono = Chrono(200 * self.survive.getOneTimeUnit()) #wait 300 timeUnit
    while not chrono.done():
        self.messageTreater(False)
        if not self.interpreter.noNotif():
            message, pos = self.interpreter.getBroadcastMessage()
            answer = message.split()
            if len(answer) == 3 and answer[0] == self.teamName and answer[1] == "father" and answer[2].isdigit() and 0 < int(answer[2]) < 9:
                supposedPos = int(answer[2])
                if supposedPos > pos:
                    diff = supposedPos - pos
                else:
                    diff = pos - supposedPos
                self.action.setDirAtBirth(diff)
                #fork
                self.fork()
                self.messageTreater()
                return True
            elif len(answer) == 2 and answer[0] == self.teamName and answer[1] == "DIE":
                self.die = True
                return True
    self.fork()
    self.messageTreater()
    return False
