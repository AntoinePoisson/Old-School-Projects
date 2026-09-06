import socket
import select

class Client:
    def __init__(self, port):
        domain = "localhost"
        # start conn or throw
        # domain etc...
        # self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM | socket.SOCK_NONBLOCK)
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.connect((domain, port))
        # self.sock.setblocking(0)

    def send(self, message):
        # select for write
        try:
            rds, wr, spec = select.select([], [self.sock], [], 0.5)
            if len(wr) > 0:
                self.sock.send(message.encode())
                return True
        except:
            # print("BROKEN PIPEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE")
            return False
        return False
        # self.sock.send(message)

    def non_block_read(self):
        data = ""
        while True:
            rds, wr, spec = select.select([self.sock], [], [], 0.5)
            if not len(rds) > 0:
                break
            tmp = self.sock.recv(1024).decode()
            if tmp:
                data += tmp
            else:
                break
        return data

    def read(self):
        data = ""
        (rds, wr, spec) = select.select([self.sock], [], [])
        tmp = self.sock.recv(1024).decode()
        return tmp