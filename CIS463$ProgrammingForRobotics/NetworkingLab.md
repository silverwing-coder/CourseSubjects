
<h2> (Python) Network Programming - 1:  
<h3>1. Server/Client on Connection-Oriented (TCP) Socket</h3>
<h3>1-1. TCP Echo Server (Single Processing ....)</h3>
<ol>
    <li>
    Refer to  ....  <a href="https://realpython.com/python-sockets/">Real Python Tutorial</a>
    </li><li>
    Refer to  ....  <a href="https://docs.python.org/3/howto/sockets.html#binary-data">Python Documentation</a>
    </li>
    <br/>
</ol>

``` python
## CIS 463 Demo, Feburary-2025
## Edited by Sangmork Park at VMI

# 1. import socket module
# 2. create a socket object:    AF_INET(ip-v4 addressing system)
#                               SOCK_STREAM(TCP protocol)
#                               SOCK_DGRAM(UDP protocol)
# 3. Binds socket to a network device: ip-address, port-number
# 4. listen to connections
# 5. when connected, get client_connection_socket and client_address
# 6. Receive data from the client until disconnected. 

import socket

# SERVER_IP = 'localhost'
SERVER_IP = '127.0.0.1'
SERVER_PORT = 8888

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server:

    server.bind((SERVER_IP, SERVER_PORT))
    server.listen(5)
    print('TCP Echo server is listening .... ')

    client_conn, client_addr = server.accept()
    print(f'conneted to {client_addr}')

    while True:
        data = client_conn.recv(1024)
        print(f'received: {data}')

        if(data.decode() == 'qq'):
            server.close()
            break
        elif(data.decode() == ''):
            server.close()
            break
        else:
            client_conn.send(data)

```

<h3>1-2. TCP Client (Single Processing ....)s</h3>

``` python

# 1. import socket module
# 2. create a socket object:    AF_INET(ip-v4 addressing system)
#                               SOCK_STREAM(TCP protocol)
#                               SOCK_DGRAM(UDP protocol)
# 3. Establish connection to a server: ip-address, port-number
# 4. Send and receive data from the server 

import socket
import time
import sys

SEVER_IP = 'localhost'
SERVER_PORT = 8888
BUFFER_SZ = 1024

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client:
    client.connect((SEVER_IP, SERVER_PORT))

    while True:

        message = input("")

        if(message == 'qq'):
            client.send(message.encode("utf-8"))
            print(f'message {message} sent.')
            time.sleep(0.5)
            client.close()
            # sys.exit()
            break
        elif(message == ''):
            continue
        else:
            client.send(message.encode("utf-8"))
            print(f'message {message} sent.')

            return_data = client.recv(BUFFER_SZ)
            print(f'{return_data} returned')

```


<h3>2. Server/Client on Connectionless (UDP Socket)</h3>
<h3>2-1. UDP Echo Server (Single Processing ....)</h3>

``` python

# 1. import socket module
# 2. create a socket object:    AF_INET(ip-v4 addressing system)
#                               SOCK_STREAM(TCP protocol)
#                               SOCK_DGRAM(UDP protocol)
# 3. Binds socket to a network device: ip-address, port-number
# 4. when connected, get client_connection_socket and client_address
# 5. Receive data from the client until disconnected. 

import socket

SERVER_IP = 'localhost'
SERVER_PORT = 8888
BUFFER_SZ = 1024

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as server:
    server.bind((SERVER_IP, SERVER_PORT))
    print('UDP server listening .... ')

    while True:
        message, client_addr = server.recvfrom(BUFFER_SZ)
        print(f'UDP connection from {client_addr}')
        print(f'{message} received')

        if (message.decode() == 'qq'):
            server.close()
            break
        elif (message.decode() == ''):
            server.close()
            break
        else:
            server.sendto(message, client_addr)
            print(f'{message} sent back')

```

<h3>2-2. UDP Client (Single Processing ....)s</h3>

``` python

# 1. import socket module
# 2. create a socket object:    AF_INET(ip-v4 addressing system)
#                               SOCK_STREAM(TCP protocol)
#                               SOCK_DGRAM(UDP protocol)
# 3. send message to (ip-address, port-number) and disconnect

import socket
import time

SERVER_IP = 'localhost'
SERVER_PORT = 8888
BUFFER_SZ = 1024

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client:

    while True:

        message = input('')
        if(message == 'qq'):
            client.sendto(message.encode(), (SERVER_IP, SERVER_PORT))
            time.sleep(0.5)
            client.close()
            break
        elif(message == ''):
            continue
        else:
            client.sendto(message.encode(), (SERVER_IP, SERVER_PORT))
            print(f'{message} sent')
            return_message, addr = client.recvfrom(BUFFER_SZ)
            print(f'{return_message} received back')

```
