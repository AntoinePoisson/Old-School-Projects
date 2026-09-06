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

def validate(input):
    res = bytearray(base64.b64decode(input))

    keystr = "qyhnrqawxxsgiudm"
    key = bytes(keystr, "ascii")
    cipher = AES.new(key, AES.MODE_ECB)

    output = cipher.decrypt(bytes(res))
    padding = output[-1]
    return output[:len(output) - padding]


def profile_for(inpb64):
    name = bytearray(base64.b64decode(inpb64))
    em = bytearray("email=", "ascii")
    profile = em + name + bytearray("&uid=10&role=user", "ascii")
    

    ## add padding
    profile = add_padding(profile)
    
    keystr = "qyhnrqawxxsgiudm"
    key = bytes(keystr, "ascii")
    cipher = AES.new(key, AES.MODE_ECB)

    print(f"second block = {profile[16:32]}")

    res = cipher.encrypt(bytes(profile))
    
    return base64.b64encode(res).decode("ascii")

#network
from flask import Flask, request, make_response

app = Flask(__name__)

@app.route('/challenge11/new_profile', methods=['POST'])
def result():
    print(f"message received {request.get_data()}")
    print(f"message received {base64.b64decode(request.get_data())}")

    _in = request.get_data()

    if len(request.cookies) == 0:
        new_token = generate_str(20)
        print(new_token)
        res = profile_for(_in)
        resp = make_response(res, 200)
        resp.set_cookie("x-access-token", new_token)
        return resp
    else:
        (_, token) = next(i for i in request.cookies.items())
        res = profile_for(_in)
        resp = make_response(res, 200)
        resp.set_cookie("x-access-token", token)
        return resp




    


    # print(f"cookie {len(request.cookies)}")
    # if len(request.cookies) == 0:
    #     new_token = generate_str(20)
    #     print(f"new token is {new_token}")
    #     map[new_token] = generate_pair()
    #     result = main(_in, new_token)
    #     resp = make_response(result, 200)
    #     resp.set_cookie("x-access-token", new_token)
    #     return resp

    # else:
    #     (_, token) = next(i for i in request.cookies.items())
    #     print(f"cookie is: {token}")
    #     result = main(_in, token)
    #     resp = make_response(result, 200)
    #     resp.set_cookie("x-access-token", token)
    #     return resp


@app.route('/challenge11/validate', methods=['POST'])
def result2():
    print(f"message received {request.get_data()}")
    print(f"message received {base64.b64decode(request.get_data())}")

    _in = request.get_data()

    if len(request.cookies) == 0:
        print("no cookies send in validate")
        resp = make_response("no cookies provided", 200)
        return resp
    
    res = validate(_in)
    (_, token) = next(i for i in request.cookies.items())
    resp = make_response(base64.b64encode(res).decode("ascii"), 200)
    print(f"cookie = {token}")
    
    resp.set_cookie("x-access-token", token)
    return resp
    # base64.b64encode(res).decode("ascii")

    # if len(request.cookies) == 0:
    #     new_token = generate_str(20)
    #     print(f"new token is {new_token}")
    #     map[new_token] = generate_pair()
    #     result = main(_in, new_token)
    #     resp = make_response(result, 200)
    #     resp.set_cookie("x-access-token", new_token)
    #     return resp

    # else:
    #     (_, token) = next(i for i in request.cookies.items())
    #     print(f"cookie is: {token}")
    #     result = main(_in, token)
    #     resp = make_response(result, 200)
    #     resp.set_cookie("x-access-token", token)
    #     return resp

if __name__ == '__main__':
    app.run(port=5000, debug=True)


