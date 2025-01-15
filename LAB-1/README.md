Multi-threaded Echo Server and Client in C
Overview
This project implements a multi-threaded echo server and a client using socket programming in C. The server listens for connections from clients and creates a dedicated thread for each client to handle their requests. The client sends a message to the server, and the server responds by echoing back the message with a prefix "Thank you".

This implementation works on the same machine using the loopback address (127.0.0.1).

Files
1. tserver1.c
Implements the multi-threaded echo server.
Listens for incoming client connections.
Creates a new thread to handle each client request.
Echoes back the client's message with a prefix.
2. tclient1.c
Implements the client.
Connects to the server using the loopback address.
Sends a message to the server and waits for the server's response.
Displays the server's response.
Requirements
Linux operating system.
GCC (GNU Compiler Collection).
Knowledge of socket programming and threads in C.
Compilation and Execution
Step 1: Compile the Server Code
bash
Copy code
cc tserver1.c -lpthread -o server
Step 2: Run the Server
bash
Copy code
./server
You will see the following output:

Copy code
server waiting....
The server is now listening for incoming client connections.

Step 3: Compile the Client Code
bash
Copy code
cc tclient1.c -o client
Step 4: Run the Client
bash
Copy code
./client
You will be prompted to enter a string. For example:

arduino
Copy code
/nenter string: Hello, Server!
Step 5: Interaction
The server will respond with the following:

arduino
Copy code
Received data from server
Thank you Hello, Server!
Explanation of Code
Server (tserver1.c)
Socket Creation:

A socket is created using socket().
Binding:

The server binds the socket to the loopback address (127.0.0.1) and port 9129.
Listening:

The server listens for incoming connections using listen().
Accepting Connections:

When a client connects, accept() returns a new socket descriptor for communication with that client.
Thread Creation:

For each client, a new thread is created using pthread_create().
The thread handles communication with the client.
Echo Functionality:

The server reads the client's message, adds a prefix ("Thank you"), and sends it back.
Thread Termination:

After responding to the client, the thread terminates.
Client (tclient1.c)
Socket Creation:

A socket is created using socket().
Connecting to Server:

The client connects to the server using the loopback address (127.0.0.1) and port 9129.
Sending a Message:

The user inputs a message, which is sent to the server.
Receiving the Response:

The client receives the modified message from the server and displays it.
Closing the Connection:

The connection is closed after the message exchange.
Output Example
Server Output
When the server is running and a client connects, you might see:

arduino
Copy code
server waiting....
created new client thread 4
input from client Hello, Server!
Client Output
The client displays:

arduino
Copy code
/nenter string: Hello, Server!
received data from server
Thank you Hello, Server!
Key Features
Multi-threading:

Each client is handled by a separate thread, enabling simultaneous handling of multiple clients.
Loopback Address:

Uses the 127.0.0.1 address for communication on the same machine.
Dynamic Interaction:

Allows users to send custom messages to the server and receive a modified response.
Use Cases
Learning Socket Programming:

A great resource for understanding sockets, threads, and basic client-server communication.
Lab Practical Reference:

Suitable as a reference for socket programming exercises.
Debugging Network Programs:

Can serve as a tool to debug simple client-server interactions.
Customization
Change the Address:

To use the server on a network, replace 127.0.0.1 with the server's actual IP address.
Modify the Port:

Change the server_address.sin_port and address.sin_port fields in both files to use a different port.
Extend Functionality:

Add more features like broadcasting messages to multiple clients or handling different types of requests.
Known Issues and Limitations
Single Machine:

Currently designed for communication on the same machine. For network communication, additional setup is required.
Limited Buffer Size:

The buffer size is 80 characters. Larger messages may be truncated.
Screenshots
Refer to the screenshots in the repository for an example of the output.

Author
This implementation was done as part of a practical/lab exercise to demonstrate multi-threaded socket programming.

Feel free to use it for learning or reference purposes.

License
This project is open-source and available under the MIT License.
