import datetime

class Chrono:
    def __init__(self, sec):
        self.duration = sec
        self.now = datetime.datetime.now()

    def done(self):
        if datetime.datetime.now() > (self.now + datetime.timedelta(seconds=self.duration)):
            return True
        else:
            return False

