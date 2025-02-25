# Socket Programming in C

## Overview
This repository contains implementations of socket programming in C for both TCP/IP (Internet domain) and UNIX domain sockets. These programs demonstrate basic client-server communication.

## Contents

### 1. **TCP/IP Socket Programs**
- `tcp_client.c` - A simple TCP client that connects to a server and exchanges messages.
- `tcp_server.c` - A simple TCP server that listens for incoming connections and exchanges messages with clients.

### 2. **UNIX Domain Socket Programs**
- `unix_client.c` - A client that communicates using a UNIX domain socket.
- `unix_server.c` - A server that listens for UNIX domain socket connections and exchanges messages.

## Features
- Bidirectional communication between client and server.
- Uses standard C socket programming functions like `socket()`, `bind()`, `listen()`, `accept()`, `connect()`, `read()`, and `write()`.
- Supports message exchange in a loop until "exit" is sent.
- Implements both TCP/IP and UNIX domain sockets.

## Prerequisites
Ensure you have a Linux system with GCC installed. If not, install it using:
```sh
sudo apt update && sudo apt install gcc
```

## Compilation & Execution

### **TCP/IP Client-Server**
#### **Step 1: Compile the Server and Client**
```sh
gcc tcp_server.c -o tcp_server
gcc tcp_client.c -o tcp_client
```
#### **Step 2: Run the Server**
```sh
./tcp_server
```
#### **Step 3: Run the Client**
```sh
./tcp_client
```

### **UNIX Domain Socket Client-Server**
#### **Step 1: Compile the Server and Client**
```sh
gcc unix_server.c -o unix_server
gcc unix_client.c -o unix_client
```
#### **Step 2: Run the Server**
```sh
./unix_server
```
#### **Step 3: Run the Client**
```sh
./unix_client
```

## How It Works
1. The server starts and listens for incoming connections.
2. The client connects to the server.
3. The client and server exchange messages.
4. Typing "exit" terminates the communication.

## Notes
- The TCP server listens on port **3260**.
- The UNIX domain socket uses the path `/tmp/unix_socket_3260`.
- Ensure the server is running before starting the client.

## Author


