import socket

HOST = ''                # Symbolic name meaning all available interfaces
PORT = 4242              # Arbitrary non-privileged port

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    s.bind((HOST, PORT))
    s.listen(1)
    conn, addr = s.accept()
    with conn:
        print('Connected by', addr)
        while True:
            data = conn.recv(1024).decode()
            if not data: continue
            if data == "QUIT": break
            # conn.sendall(data)
            if data:
                print("get %s" % data)
                conn.send(b"coucou")
