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

    return [arr[idx]["out"], arr[idx]["score"], idx]

def compare_lines(arr):
    lines = []
    for i in range(0, len(arr)):
        if arr[i] == "":
            continue
        trpl = cmp_freq(bytes.fromhex(arr[i]))
        lines.append(trpl)

    max_value = lines[0]
    line_idx = 0
    for i in range(1, len(lines)):
        if lines[i][1] > max_value[1]:
            max_value = lines[i]
            line_idx = i
    print('%d %02X' % (line_idx + 1, max_value[2]))

def main(filename):
    f_obj = open(filename, "r")

    _str = f_obj.read()

    arr = _str.split("\n")

    compare_lines(arr)
    # compare_lines(array_bytes)

if __name__ == '__main__':
    try:
        if len(sys.argv) != 2 or os.stat(sys.argv[1]).st_size == 0:
            sys.exit (84)
        main(sys.argv[1])
    except:
        sys.exit(84)
