#!/bin/env python3
import sys
import os
from base64 import b64encode, b64decode

def main(av):
    file = open(av[1], "r")
    lines = file.read().split("\n")

    for (i, line) in enumerate(lines):
        if i == len(lines) - 1 and line == "":
            break
        base64 = b64encode(bytes.fromhex(line)).decode()
        print(base64)
    file.close()

if __name__ == '__main__':
    try:
        if len(sys.argv) != 2 or os.stat(sys.argv[1]).st_size == 0:
            sys.exit (84)
        main(sys.argv)
    except:
        sys.exit(84)
