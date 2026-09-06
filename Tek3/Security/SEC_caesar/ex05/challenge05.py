#!/bin/env python3
import sys
import os

def logical_xor(key, data):
    res = ""

    for i in range(len(data)):
        res += chr(data[i] ^ key[i % len(key)])
    return res

def main(av):
    file = open(av[1], "r")
    lines = file.read().split("\n")
    if lines[0] == "" or lines[1] == "":
        sys.exit(84)

    key = bytes.fromhex(lines[0])
    data = bytes.fromhex(lines[1])
    xored_data = logical_xor(key, data)

    print(bytes(xored_data, 'utf-8').hex().upper())
    # print(xored_data.encode().hex())              # same
    # print(xored_data.encode('utf-8').hex())       # same
    file.close()

if __name__ == '__main__':
    try:
        if len(sys.argv) != 2 or os.stat(sys.argv[1]).st_size == 0:
            sys.exit (84)
        main(sys.argv)
    except:
        sys.exit(84)
