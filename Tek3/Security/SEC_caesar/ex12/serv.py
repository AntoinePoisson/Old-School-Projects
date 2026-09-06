import base64
import string
import random
from Crypto.Cipher import AES
import sys

map = {}

def generate_str(size=None):
    length = random.randint(3, 16)
    if size is not None:
       length = size
    letters = string.ascii_lowercase
    random_str = "".join([random.choice(letters) for i in range(0, length)])
    return random_str

def generate_pair():
    key = generate_str(16)
    unknown_str = generate_str()
    return key, unknown_str

def add_padding(input):
    rest = (len(input) % 16)
    padding = 16 - rest
    input += bytearray([ padding for i in range(0, padding)])
    
    print(f"padding len = {padding}")

    return input

def main(input, token=None):
    key, unknown_str = generate_pair()
    if token != None:
        key, unknown_str = map[token]
    else:
        new_token = generate_str(16)
        map[new_token] = (key, unknown_str)
    # key, unknown_str = ("--CRYPTOGRAPHY--", "CURVE")
    print(f"key = {key}, unknown_str = {unknown_str}")

    bkey = bytes(key, "ascii")
    bus = bytes(unknown_str, "ascii")
    print(input)
    bytearray(base64.b64decode(input))
    new_val = add_padding(bytes("lolol", "ascii") + bytearray(base64.b64decode(input)) + bus)
    # new_val = add_padding(bytearray(base64.b64decode(input)) + bus)

    cipher = AES.new(bkey, AES.MODE_ECB)

    enc = cipher.encrypt(bytes(new_val))

    # print(enc.hex())
    print(base64.b64encode(enc).decode("ascii"))

    return base64.b64encode(enc).decode("ascii")

# main(base64.b64encode(bytes("cocolelapin", "ascii")))

#network

from flask import Flask, request, make_response

app = Flask(__name__)

@app.route('/challenge12', methods=['POST'])
def result():
    print(f"message received {request.get_data()}")
    print(f"message received {base64.b64decode(request.get_data())}")


    _in = request.get_data()

    print(f"cookie {len(request.cookies)}")
    if len(request.cookies) == 0:
        new_token = generate_str(20)
        print(f"new token is {new_token}")
        map[new_token] = generate_pair()
        result = main(_in, new_token)
        resp = make_response(result, 200)
        resp.set_cookie("x-access-token", new_token)
        return resp

    else:
        (_, token) = next(i for i in request.cookies.items())
        print(f"cookie is: {token}")
        result = main(_in, token)
        resp = make_response(result, 200)
        resp.set_cookie("x-access-token", token)
        return resp

if __name__ == '__main__':
    app.run(port=5000, debug=True)


