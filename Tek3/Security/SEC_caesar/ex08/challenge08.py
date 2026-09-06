#!/bin/env python3                                                              

import base64
import sys
import os

# l = base64.b64decode("NXQMSbuXH11s301Nj/4jWZqW9lgeGNnUVyVig2TFTblZYNlC0ElHnue+xJmzYVvT")

def check_occurence(b, block_size):
    length = len(b) / block_size
    if round(length) != length:
        raise Exception("That line cannot be split of block_size of 16 bytes")
    length = len(b) // block_size
    
    # print(length)
    
    for i in range(0, block_size*length, block_size):
        for j in range(i + block_size, block_size*length, block_size):
            # print(f"i = {i}, i + block_size = {i+block_size}")
            if b[i:i + block_size] == b[j:j+block_size]:
                return True
    return False

def main(filename):
    with open(filename, "r") as f:
        lines = f.read().split("\n")
        for i in range(0, len(lines)):
            b = base64.b64decode(lines[i])
            if check_occurence(b, 16) == True:
                print(i + 1)
                break

if __name__ == '__main__':
    try:
        if len(sys.argv) != 2 or os.stat(sys.argv[1]).st_size == 0:
            sys.exit(84)
        main(sys.argv[1])
    except:
        sys.exit(84)

# byte_arr = base64.b64decode("h1VLmXXAbZ43CG0Bqn+kGodVS5l1wG2eNwhtAap/pBrE1kBC4kmaxN5VGr1d21wS")

# print(byte_arr[0:16])
# print(byte_arr[16:32])
# print(byte_arr[32:48])
