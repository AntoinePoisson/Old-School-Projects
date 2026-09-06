#!/bin/env python3                                                              

import os
import sys

frequency = {
        'a': .08167, 'b': .01492, 'c': .02782, 'd': .04253, 'e': .12702, 'f': .02228, 'g': .02015, 'h': .06094,
        'i': .06094, 'j': .00153, 'k': .00772, 'l': .04025, 'm': .02406, 'n': .06749, 'o': .07507, 'p': .01929,
        'q': .00095, 'r': .05987, 's': .06327, 't': .09056, 'u': .02758, 'v': .00978, 'w': .02360, 'x': .00150,
        'y': .01974, 'z': .00074, ' ': .13000
    }

def get_score(input):
    score = 0
    for i in input.lower():
        if chr(i) in frequency.keys():
            score += frequency[chr(i)]
    return score

def cipher_xor(input, key):
    y = bytearray(input)
    for i in range(0, len(input)):
        y[i] ^= key
    return bytes(y)

def cmp_freq(input):

    arr = []
    idx = 0
    value = 0
    for k in range(0, 256):
        out = cipher_xor(input, k)
        score = get_score(out)
        if score > value:
            value = score
            idx = k
        elem = {"out": out, "score": score}
        arr.append(elem)

    return arr[idx]["out"], idx

def main(filename):
    f_obj = open(filename, "r")

    _str = f_obj.read()

    arr = _str.split("\n")
    if arr[0] == "":
        raise Exception("empty file")

    res = bytes.fromhex(arr[0])
    bytearr = bytearray(res)
    s, key = cmp_freq(res)

    print("%02X"%key)

# input04

if __name__ == '__main__':
    try:
        if len(sys.argv) != 2 or os.stat(sys.argv[1]).st_size == 0:
            print("Error file.")
            sys.exit (84)
        main(sys.argv[1])
    except:
        sys.exit(84)