#include "../headers/server.h"

/* implementation explicit constructor */

Server::Server() {
    this->server_sock = -1;
    this->client_sock = -1;
    this->port = 1234;
    this->ip = "127.0.0.1";
    this->count = 0;
}

/* implementation particular constructor */

Server::Server(std::string ip, int port) {
    this->server_sock = -1;
    this->client_sock = -1;
    this->port = port;
    this->ip = ip;
}

/* procedure for connecting to server */

void Server::Connect() {
    std::cout << "[+] Running server..." << std::endl;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sock == -1) {
        exit(EXIT_FAILURE);
        return;
    }

    int length_server_addr = sizeof(server_addr);
    int length_client_addr = sizeof(client_addr);

    memset(&server_addr, 0, (size_t) length_server_addr);
    memset(&client_addr, 0, (size_t) length_client_addr);

    server_addr.sin_family = PF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    bind(server_sock, (struct sockaddr*) &server_addr, (size_t) length_server_addr);
    listen(server_sock, 5);
    getsockname(server_sock, (struct sockaddr*) &server_addr, (socklen_t *) &length_server_addr);

    std::cout << "Server started on: " << inet_ntoa(server_addr.sin_addr) << ":" << ntohs(server_addr.sin_port) << std::endl;
    std::cout << "Listening port: " << port << "..." << std::endl;
}

/* procedure for sending messages */

void Server::Send(std::string message) {
    std::cout << "[+] Sending message..." << std::endl;

    std::string msg = "";
    std::string receiver = "";

    int index = 0;

    // cutting name of receiver

    for (index; this->buffer[index] != '|'; index++)
        receiver += this->buffer[index];

    index += 1;

    // cutting text of message

    for (index; this->buffer[index] != '\0'; index++)
        msg += this->buffer[index];

    // looking for receiver in list of Users and send to him message

    for (int i=0; i < users.size(); i++) {
        if (users[i].name == receiver)
            send(users[i].data, msg.c_str(), msg.length(), 0);
    }

    std::cout << "[-] Message was sending!" << std::endl;
}

/* procedure for receiving messages */

void Server::Receive(int socket) {
    char buff[1024] = {};

    memset(&buff, '\0', sizeof(buff));

    int receive = recv(socket, buff, 1024, 0);

    if (receive != 0) {
            std::string sender;
            std::string ip;

            // looking for name of sender

            for (int i=0; i < users.size(); i++) {
                if (users[i].data == socket) {
                    sender = users[i].name;
                    ip = users[i].ip;
                }
            }

            this->buffer = buff;

            std::cout << "Message from client: " << std::endl;
            std::cout << "NICKNAME: " << sender << " IP: " << ip << " MESSAGE: " << buff << std::endl;
    }

    else if (receive == -1) {
        std::cout << "[-] Receiving Error!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

/* procedure for closing both sockets */

void Server::Close() {
    std::cout << "Stop of listening!" << std::endl;
    std::cout << "[-] Stop of working server!" << std::endl;

    close(this->client_sock);
    close(this->server_sock);
}

/* function for receiving communication on the socket */

void Server::Accept() {
    // accepting connection of User

    int length_client_addr = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr*) &client_addr, (socklen_t *) &length_client_addr);
    getpeername(client_sock, (struct sockaddr*) &client_addr, (socklen_t *) &length_client_addr);

    // print info about connected user

    std::cout << "Client with IP: ";
    std::cout << inet_ntoa(client_addr.sin_addr);
    std::cout << ":" << ntohs(client_addr.sin_port);
    std::cout << " was connected.";
    std::cout << std::endl;

    char buff[1024] = {};
    memset(&buff, '\0', sizeof(buff));

    // receiving nickname of User

    int recv_nick = recv(client_sock, buff, 1024, 0);

    if (recv_nick != 0) {
        this->buffer = buff;

        // adding connected User to vector of Users

        if (this->buffer.length() > 0)
            users.push_back(User{count, client_sock, "127.0.0.1", buffer});

        else
            std::cout << "[-] Naming Error Nickname!";

        this->count++;
    }

    else if (recv_nick == -1) {
        std::cout << "[-] Receiving Error Nickname!";
        exit(EXIT_FAILURE);
    }
}

/* function for getting value from { client_sock } */

int Server::getSocket() {
    return this->client_sock;
}
