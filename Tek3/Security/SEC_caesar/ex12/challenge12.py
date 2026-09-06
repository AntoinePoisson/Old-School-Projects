#!/bin/env python3
import sys
import os
import requests
from base64 import b64encode, b64decode
sys.path.insert(0, './ex08/')
from challenge08 import check_occurence

def connection(cookie, arg):
    if cookie == "":
        res = requests.post("http://127.0.0.1:5000/challenge12", data=arg)
    else:
        res = requests.post("http://127.0.0.1:5000/challenge12", data=arg, cookies={"x-access-token": cookie})
    for (_, token) in res.cookies.items():
        cookie = token
    # cookie = res.cookies.get("x-access-token")
    return cookie, res.text


def get_size_block(cookie):
    last_size = -1

    for size in range(1000):
        _, resp = connection(cookie, b64encode(bytes(size * 'A', 'utf-8')).decode())
        resp = b64decode(resp)
        if len(resp) != last_size and last_size != -1:
            return len(resp) - last_size
        last_size = len(resp)
    return 16


def get_unknown_string_size(cookie, block_size):
    # for size in range(1000):
    for size in range(16, 1000):
        _, resp = connection(cookie, b64encode(bytes(size * 'A', 'utf-8')).decode())
        resp = b64decode(resp)
        arr = [resp[i:i + block_size] for i in range(0, len(resp), block_size)]
        for i in range(len(arr)):
            for j in range(len(arr)):
                if arr[i] == arr[j] and i != j:
                    return size - (2 * block_size), len(resp) - ((j + 1) * block_size)
    return 16


def get_unknown_string(cookie, block_size):
    len_prefix, length = get_unknown_string_size(cookie, block_size)
    unknown_string = 'A' * length
    tmp = 'A' * (length - 1)
    last_size = -1
    pref = ""

    if len_prefix != 0:
        pref = 'A' * len_prefix
        len_prefix = (len_prefix // block_size + 1) * block_size

    for i in range(len(unknown_string)):
        unknown_string = unknown_string[1:] + 'A'

        # for nb in range(32, 127):
        for nb in range(255):
            _, resp = connection(cookie, b64encode(bytes(pref + unknown_string + tmp, 'utf-8')).decode())
            resp = b64decode(resp)
            unknown_r = resp[len_prefix : len_prefix + length]
            tmp_r = resp[len_prefix + length : len_prefix + length * 2]
            last = resp[len_prefix + length * 2:]

            if i == 0 and nb == 0:
                last_size = len(resp)
            if last_size != len(resp) and len(resp) == length * 2 + len_prefix:
                return unknown_string[length - i - 1: length - 1]
            if unknown_r == tmp_r:
                break
            unknown_string = unknown_string[:length - 1] + chr(nb) + unknown_string[length:]
        tmp = tmp[:-1]
    return unknown_string


def main(av):
    # cookie, resp = connection("", b64encode(bytes(11 * "A" + 15 * "A" + "C" + 15 * "A", 'utf-8')).decode())
    cookie, resp = connection("", "")
    # print("cookie:", cookie, "resp:", resp, file=sys.stderr)

    # print("detected block size = {}".format(get_size_block(cookie)), file=sys.stderr)
    # try:
    #     if check_occurence(b64decode(resp), 16) == True: # 16 because size_block == 16
    #         print("It is AES ECB", file=sys.stderr)
    #     else:
    #         print("It isn't AES ECB", file=sys.stderr)
    # except:
    #     print("RAISED: It isn't AES ECB", file=sys.stderr)

    unknown_str = get_unknown_string(cookie, 16)
    # print ("unknown_str:", unknown_str, file=sys.stderr)
    print (b64encode(bytes(unknown_str, 'utf-8')).decode())




if __name__ == '__main__':
    try:
        if len(sys.argv) != 1:
            sys.exit (84)
        main(sys.argv)
    except:
        sys.exit(84)
