
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

def main():

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server:
        server.bind(('127.0.0.1', 9999))
        server.listen(5)
        print('tcp server waiting ....')

        client_connection, client_address = server.accept()
        print(f'connection accepted from {client_address}')

        while True:
            
            recv_data = client_connection.recv(1024).decode()
            if not recv_data:
                break
            print(f'received: {recv_data}')

            client_connection.sendall(recv_data.encode())
            print(f'sent: {recv_data}')

        client_connection.close()
        server.close()

            
if __name__ == '__main__':
    main()

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

def main():

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client:
        client.connect(('127.0.0.1', 9999))
        # client.sendall(b'Hello, Server!')
        client.sendall('Hello, Server!'.encode())
        data = client.recv(1024)
        print(f'received back: {data}')

        client.close()

if __name__ == '__main__':
    main()

```


<h3>2. Server/Client on Connectionless (UDP Socket</h3>
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

# BUFER_SIZE = 65535
BUFER_SIZE = 1024

def main():

    # with statement automatically close the socket at the end of the block 
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as server:
        server.bind(('127.0.0.1', 9999))
        print('UDP server is up and waiting ..... ')
        
        recv_data, client_address = server.recvfrom(BUFER_SIZE)
        print(f'Connected from: {client_address}')
        print(f'Received data: {recv_data}')
        server.close()
                
        # while True:
        #     recv_data, client_address = server.recvfrom(BUFER_SIZE)
        #     print(f'Connected from: {client_address}')
        #     print(f'Received data: {recv_data}')

        #     if (recv_data.decode().lower() == 'quit'):
        #         break

        #     server.sendto(recv_data, client_address)
        #     print(f'Data returned to {client_address[0]}')


if __name__ == '__main__':
    main()

```

<h3>2-2. UDP Client (Single Processing ....)s</h3>

``` python

# 1. import socket module
# 2. create a socket object:    AF_INET(ip-v4 addressing system)
#                               SOCK_STREAM(TCP protocol)
#                               SOCK_DGRAM(UDP protocol)
# 3. send message to (ip-address, port-number) and disconnect

import socket

def main():

    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client:

        client.sendto(b'Hello Server... ', ('127.0.0.1', 9999))

        ## process wait for  to receiv
        # data = client.recv(1024)
        # print(f'Message returned: {data}')
        
        client.close()

      
        # while True:
        #     message = input('Message?, to exit QUIT ')
        #     if message == 'QUIT':
        #         client.sendto(b'quit', ('127.0.0.1', 9999))
        #         break

        #     message = message.encode('utf-8')
        #     client.sendto(message, ('127.0.0.1', 9999))
            
        #     data = client.recv(1024)
        #     print(f'Message returned: {data}')

        #     client.close()

if __name__ == '__main__':
    main()

```
