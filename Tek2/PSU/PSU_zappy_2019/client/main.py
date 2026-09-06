from Client import Client
from Interpreter import Interpreter
from Player.Player import Player
import sys
import subprocess
import getopt

def disp_help():
    print("USAGE: ./zappy_ai -p port -n name -h machine")
    print("\tport\tis the port number")
    print("\tname\tis the name of the team")
    print("machine is the name of the machine; localhost by default")

def parse_arg(port, name, machine, argv):
    args = []
    optlist, args = getopt.getopt(argv[1:], 'p:n:h:')
    for liste in optlist:
        if liste[0] == '-p':
            port = int(liste[1])
        elif liste[0] == '-n':
            name = liste[1]
        elif liste[0] == '-h':
            machine = liste[1]
        else:
            return []
    if (port <= 0 or len(name) <= 0 or len(machine) <= 0):
        return []
    return [port, name, machine]

def main(argv):
    #don't forget
    # ./zappy_ai -p port -n name -h machine
    port = -1
    name = ""
    machine = "127.0.0.1"
    if len(argv) < 5:
        raise Exception("Wrong number of arguments")
    tmp = parse_arg(port, name, machine, argv)
    if len(tmp) == 0:
        raise Exception("Wrong arguments")
    port = tmp[0]
    name = tmp[1]
    machine = tmp[2]
    if argv[4] == "GRAPHIC":
        print("graphic client")
        subprocess.run(["./graphic", str(port)])
    else:
        interp = Interpreter(Client(int(port)))
        # input() #WELCOME
        interp.read() #WELCOME
        #team name
        team_name = name
        interp.send(team_name)
        interp.decreaseSendMessages()
        arr = interp.read().split("\n")
        if arr[0] == "dead" or arr[0] == "ko":
            raise Exception("Fail to connect client, maybe wrong team name")
        nbClient = arr[0]
        mapDim = arr[1]
        #nb of clients
        nb_of_clients = int(nbClient)
        print("left client {}".format(nb_of_clients))
        #coo
        coo = mapDim.split(' ')
        #create class map
        player = Player(team_name, interp, int(coo[0]), int(coo[1]), nb_of_clients)
        player.mainLoop()

if __name__ == '__main__':
    try:
        if len(sys.argv) <= 2 or (sys.argv[1] == "-help" or sys.argv[1] == "--help" or (sys.argv[1] == "-h" and len(sys.argv) <= 2)):
            disp_help()
        else:
            main(sys.argv)
    except:
        print("Error")
        sys.exit(84)
    # except Exception as inst:
    #     print("Catch Exception: " + str(inst))
    #     sys.exit(84)
    # else
    #     print("Error")
    #     sys.exit(84)