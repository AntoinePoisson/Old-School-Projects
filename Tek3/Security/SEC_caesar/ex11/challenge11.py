#!/bin/env python3
import sys
import os
import base64
import requests

def connection(cookie, url, data):
    if cookie == "":
        res = requests.post(url, data=data)
        # cookie = res.cookies.get("x-access-token")
        # print(res.cookies)
        # print(res.cookies[0])
        if len(res.cookies.items()) == 0:
            return "", res.text
        else:
            (_, token) = next(i for i in res.cookies.items())
            return token, res.text
    else:
        res = requests.post(url, data=data, cookies={"x-access-token": cookie})
        # cookie = res.cookies.get("x-access-token")
        if len(res.cookies.items()) == 0:
            return "", res.text
        else:
            (_, token) = next(i for i in res.cookies.items())
            return token, res.text

def decrypter_():
    
    #craft first block
    name = 'A' * 13
    b = bytes(name, "ascii")
    b64name = base64.b64encode(b)
    # res = profile_for(b64name.decode("ascii")) ##change here
    cooki, res = connection("", "http://127.0.0.1:5000/challenge11/new_profile", b64name.decode("ascii"))
    res1 = base64.b64decode(res)
    block = res1[0:32]

    #craft second block
    new_name = bytearray('A'*10 + "admin", "ascii") + bytearray([11]*11)
    
    b64new_name = base64.b64encode(new_name)
    # res2 = profile_for(b64new_name.decode("ascii")) ###change here
    cooki, res2 = connection(cooki, "http://127.0.0.1:5000/challenge11/new_profile", b64new_name.decode("ascii"))

    res2 = base64.b64decode(res2)
    block2 = res2[16:32]

    #concat first with second block
    response = bytearray(block) + bytearray(block2)

    # res = validate(base64.b64encode(response).decode("ascii"))
    cooki, res = connection(cooki, "http://127.0.0.1:5000/challenge11/validate", base64.b64encode(response).decode("ascii"))

    # print(f"res = {base64.b64decode(res)}")
    print(res)

    return res

def main(av):
    decrypter_()

if __name__ == '__main__':
    # try:
    #     if len(sys.argv) != 1:
    #         sys.exit (84)
    main(sys.argv)
    # except:
    #     sys.exit(84)
