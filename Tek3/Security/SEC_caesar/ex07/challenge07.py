#!/bin/env python3
import sys
import os
from Crypto.Cipher import AES
from base64 import b64encode, b64decode

def pad_block(block_size, data):
    char = block_size % len(data)

    if char == 0:
        char = block_size
    try:
        data += chr(char) * char
    except:
        data += bytes(chr(char) * char, 'utf-8')
    return data


def unpad_block(data):
    try:
        char = ord(data[len(data) - 1])
    except:
        char = data[len(data) - 1]

    return data[:-char]


def main(av):
    # print("Rijndael")
    # print(bytes("Rijndael", 'utf-8').hex())
    # print(pad_block(10, "Rijndael"))
    # print(bytes(pad_block(10, "Rijndael"), 'utf-8').hex())
    # print(unpad_block(pad_block(10, "Rijndael")))
    # print(bytes(unpad_block(pad_block(10, "Rijndael")), 'utf-8').hex())
    file = open(av[1], "r")
    lines = file.read().split("\n")
    file.close()
    if len(lines) != 3:
        sys.exit(84)

    key = bytes.fromhex(lines[0])
    data = b64decode(lines[1])
    cipher = AES.new(key, AES.MODE_ECB)
    data = unpad_block(cipher.decrypt(data))

    print(b64encode(data).decode())

if __name__ == '__main__':
    try:
        if len(sys.argv) != 2 or os.stat(sys.argv[1]).st_size == 0:
            sys.exit (84)
        main(sys.argv)
    except:
        sys.exit(84)
