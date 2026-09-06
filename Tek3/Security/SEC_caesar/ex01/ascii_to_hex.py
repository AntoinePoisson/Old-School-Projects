#!/bin/env python3
import sys
import os

def main(av):
    file = open(av[1], "r")
    lines = file.read().split("\n")
    res = ""

    for (i, line) in enumerate(lines):
        if i == len(lines) - 1 and line == "":
            break
        hexa = bytes(line, 'utf-8').hex()
        res += hexa
    file.close()

    file2 = open(av[2], "w")
    file2.write(res)
    file2.close()


if __name__ == '__main__':
    try:
        if len(sys.argv) != 3 or os.stat(sys.argv[1]).st_size == 0:
            print("python3 ascii_to_hex 'ascii file' 'hex file'")
            sys.exit (84)
        main(sys.argv)
    except:
        sys.exit(84)
