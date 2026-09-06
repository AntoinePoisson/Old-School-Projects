#!/bin/env python3                                                              

from Crypto.Cipher import AES
import base64
import sys
import os

# key = bytes.fromhex("45504954454348464F5254484557494E")
# IV  = bytes.fromhex("00000000000000000000000000000000")

# first_line = base64.b64decode("KGhWjZtE3OzS7sPuHmr622tVBVvPiPR74BrccguSs1DFlgeKii2mY82yg/FgJ6510S/P2F/6axZWHbU6")

def decipher(cphrd_text, key, iv):
    key_to_xor = iv
    cipher = AES.new(key, AES.MODE_ECB)
    arr = bytearray()

    for i in range(0, len(cphrd_text), 16):
        tmp = cphrd_text[i:i+16]

        res = cipher.decrypt(tmp)

        res = bytearray([res[i] ^ key_to_xor[i] for i in range(0, 16)])

        key_to_xor = tmp
        arr += res
    return arr

def remove_padding(arr):
    padding_value = arr[-1]
    if padding_value > 16:
        return arr
    # print(f"padding_value = {padding_value}")
    return arr[:len(arr) - padding_value]

def main(filename):
    f_obj = open(filename, "r")
    l1 = f_obj.readline()
    l2 = f_obj.readline()

    cphrd_txt = bytearray(base64.b64decode(f_obj.read()))

    # if len(cphrd_txt) % 16:
    #     raise Exception("wrong input length")
    
    # cphrd_txt = cphrd_txt[:len(cphrd_txt)//16]

    key = bytes.fromhex(l1)
    IV = bytes.fromhex(l2)
    
    # print(len(cphrd_txt))
    r = decipher(bytes(cphrd_txt), key, IV)
    
    r = remove_padding(r)
    
    print(base64.b64encode(bytes(r)).decode("ascii"))

if __name__ == '__main__':
    try:
        if len(sys.argv) != 2 or os.stat(sys.argv[1]).st_size == 0:
            sys.exit(84)
        main(sys.argv[1])
    except:
        sys.exit(84)
