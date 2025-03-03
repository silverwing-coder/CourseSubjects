<h4>Update: Feb-2025, Sangmork Park at VMI</h4>
<h2>CIS463 Assignment-5: Networking Programming</h2>
<h3>TCP Chatroom Server</h3>

``` python

import socket
import threading
import time

SERVER_IP = 'localhost'
SERVER_PORT = 9999

stop_flag = threading.Event()

# manage client's hosts and chatroom users
clients = []            # client's connections list
nicknames = []          # chatroom users list

# remove terminating clients and users, return resources to O.S.
def clean(client):
    index = clients.index(client)
    clients.remove(client)
    nickname = nicknames[index]
    broadcast(f'{nickname} left the chat!'.encode())
    nicknames.remove(nickname)
    # client.send('qq'.encode())
    client.close()
    print(f'We have {len(clients)} guests')

# broad all messages and notifications to every client
def broadcast(message):
    ''' //FIX ME// '''
    
# handle servr connections
def server_handle(client):
    while not stop_flag.is_set():
        try:
            # if message is 'exit', terminate service of the client and user
            # else, broadcast the message
            ''' //FIX ME// '''
        except:
            clean(client)
            break


if __name__ == '__main__':
    finish = False
    # create a socket object for server and wait
    ''' // FIX ME// '''

        while True:
            # accept connections and provide service for each connection with multiple threads

            '''//FIX ME//''' 
              
            thread = threading.Thread(target=server_handle, args=(client_conn, ))
            thread.start()

```

<h3>TCP Chatroom Client</h3>

``` python

import socket
import threading
import time

SERVER_IP = 'localhost'
SERVER_PORT = 9999

stop_flag = threading.Event()

# if error() occurs, or 'exit' returns from server, disconnect server and exit
def receive():
    while not stop_flag.is_set():

        '''//FIX ME//'''


if __name__ == '__main__':

    nickname = input('Choose your nickname: ')

    # create a socket object for client service
    ''' //FIX ME//'''

        receive_thread = threading.Thread(target=receive)
        receive_thread.start()

        while True:
            time.sleep(0.05)
            message = input('>> ')
            if (message == 'exit'):
                client.send(message.encode())
                client.close()
                stop_flag.set()
                receive_thread.join()
                break
            else:
                client.send(f'{nickname} says: {message}'.encode())i

```