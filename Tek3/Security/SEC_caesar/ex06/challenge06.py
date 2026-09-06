#!/bin/env python3

import sys
import os
from base64 import b64encode, b64decode
sys.path.insert(0, './ex03/')
from challenge03 import cmp_freq

def handleFile(name):
    stream = open(name, "r")
    data = stream.read()
    if data.find('\n') != -1 or len(data) < 16:
        print("The file is invalid.")
        sys.exit(84)
    data = bytes.fromhex(data).upper()
    stream.close()
    return data

def calcHammingDistance(first, second):
    if len(first) != len(second) or len(second) == 0:
        print("Error")
        return -1
    binFirst = bin(int.from_bytes(first, byteorder='big'))
    binSecond = bin(int.from_bytes(second, byteorder='big'))
    res = 0
    count = int(binFirst, 2) ^ int(binSecond, 2)
    while count:
        res += 1
        count &= count - 1
    return res

def findKeySize(data):
    listHammingDistance = []
    hammingDistance = 0
    for size in range(2, 43):
        ################# Hamming Distance sur tout les Blocks
        listDistance = []
        for i in range(0, int(len(data) / size) - 1):
            oneBlock = data[(size * i) : (size * (i + 1))]
            twoBlock = data[(size * (i + 1)) : (size * (i + 2))]
            listDistance.append(float(calcHammingDistance(oneBlock, twoBlock) / size))
        listHammingDistance.append({"distance": (sum(listDistance) / len(listDistance)), "size": size})
        ##################################

        ################# Hamming Distance sur les 2 Blocks
        # firstBlock = data[: size]
        # secondBlock = data[size: (size * 2)]
        # hammingDistance = float(float(calcHammingDistance(firstBlock, secondBlock)) / size)
        # listHammingDistance.append({"distance": hammingDistance, "size": size})
        ##################################

        ################# Hamming Distance sur les 4 Blocks
        # firstBlock = data[: size]
        # secondBlock = data[size : (size * 2)]
        # thirdBlock = data[(size * 2) : ((size * 2) + size)]
        # fourthBlock = data[((size * 2) + size) : ((size * 2) + (size * 2))]
        # hammingDistance = float(float((calcHammingDistance(firstBlock, secondBlock) + calcHammingDistance(thirdBlock, fourthBlock)) / size) / 2)
        # listHammingDistance.append({"distance": hammingDistance, "size": size})
        ##################################

    small = listHammingDistance[0].get("distance")
    indexSmall = 0
    for index, element in enumerate(listHammingDistance):
        # print(element)
        if (element.get("distance") < small and element.get("distance") >= 0):
            indexSmall = index
            small = element.get("distance")
    # print("res =", listHammingDistance[indexSmall])
    return listHammingDistance[indexSmall]

def find_charac(line):
    rightCharacter = ''
    highrate = 0
    etaoinshrdlu = 'ETAOIN SHRDLU'
    valueCharacter = 0

    while valueCharacter <= 127:
        rate = 0
        for el in str(bytes([valueCharacter ^ the_bytes for the_bytes in line]), 'ASCII').upper():
            if el in etaoinshrdlu:
                rate += 1

        if rate > highrate:
            highrate = rate
            rightCharacter = chr(valueCharacter)
        valueCharacter += 1
    return rightCharacter


def solve(listBlock):
    res = ''

    for line in listBlock:
        res += find_charac(listBlock[line])
    return res

################# avec l'exo3
def breakRepeatingKeyXOR(data):
    buffer = bytearray((data))
    return cmp_freq(buffer)

def findKey(keysize, data):
    listBlockTranpose = dict.fromkeys(range(keysize))
    indexCols = 0

    for i in range(len(data)):
        if (listBlockTranpose[indexCols] == None):
            listBlockTranpose[indexCols] = []
        listBlockTranpose[indexCols].append(hex(data[i:i + 1][0])[2:].upper())
        i += 1
        indexCols += 1
        if indexCols == keysize:
            indexCols = 0

    for block in listBlockTranpose:
        for i in range(len(listBlockTranpose[block])):
            listBlockTranpose[block][i] = (int(listBlockTranpose[block][i], 16))
        listBlockTranpose[block] = bytes(listBlockTranpose[block])

    res = ""
    for el in listBlockTranpose:
        msg, charac = (breakRepeatingKeyXOR(listBlockTranpose[el]))
        res += hex(charac).upper()[2:]
    if (len(res) % 2 == 0 and keysize % 2 == 0 and res[0 : int(len(res) / 2)] == res[int(len(res) / 2) : len(res)]):
        return findKey(int(keysize / 2), data)
    print(res)
    pass
##################################

################# sans l'exo3
# def findKey(keysize, data):
#     listBlockTranpose = dict.fromkeys(range(keysize))

#     indexCols = 0
#     for i in range(len(data)):
#         if (listBlockTranpose[indexCols] == None):
#             listBlockTranpose[indexCols] = []
#         listBlockTranpose[indexCols].append(hex(data[i:i + 1][0])[2:].upper())
#         i += 1
#         indexCols += 1
#         if indexCols == keysize:
#             indexCols = 0

#     for block in listBlockTranpose:
#         for i in range(len(listBlockTranpose[block])):
#             listBlockTranpose[block][i] = int(listBlockTranpose[block][i], 16)

#     res = solve(listBlockTranpose)
#     if (len(res) % 2 == 0 and keysize % 2 == 0 and res[0 : int(len(res) / 2)] == res[int(len(res) / 2) : len(res)]):
#         return findKey(int(keysize / 2), data)
#     return res
##################################

    ## Solution: "R1ch4Rd 57411m4N" | "523163683452642035373431316D344E"

def main(av):
    data = handleFile(av[1])
    res = findKeySize(data)
    res = findKey(res.get("size"), data)
    if res:
        print(res.encode('utf-8').hex().upper())


if __name__ == '__main__':
    try:
        if len(sys.argv) != 2 or os.stat(sys.argv[1]).st_size == 0:
            print("No file in argument.")
            sys.exit(84)
        main(sys.argv)
    except:
        print("Throw Error.")
        sys.exit(84)
