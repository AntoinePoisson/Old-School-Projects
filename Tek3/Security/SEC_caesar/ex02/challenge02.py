#!/bin/env python3                                                              
import sys
import os

def openfile(filename):
    f_obj = open(filename, "r")

    # l1 = f_obj.readline()
    _str = f_obj.read()
    value = _str.split("\n")
    
    if len(value) < 2:
        raise Exception("There aren't two buffers")
    return value

def xor_gate(filename):
    value = openfile(filename)

    if len(value[0]) != len(value[1]):
        raise Exception("The two buffer have not the same size")
    if len(value[0]) % 2 != 0:
        raise Exception("length buffer not pair")

    linker = {str(10): "A", str(11): "B", str(12): "C", str(13): "D", str(14): "E", str(15): "F"}

    buffer = []
    output = ""

    for i in range(0, len(value[0])):
        res = int(value[0][i], 16) ^ int(value[1][i], 16)
        res = int(res)
        if res >= 10:
            output += linker[str(res)]
        else:
            output += str(res)
    print(output)
    
#xor_gate("./input02.txt")

if __name__ == '__main__':
    try:
        if len(sys.argv) != 2 or os.stat(sys.argv[1]).st_size == 0:
            sys.exit (84)
        xor_gate(sys.argv[1])
    except:
        sys.exit(84)