#include "../headers/client.h"

/* implementation of explicit constructor */

Client::Client() {
    this->client_sock = 0;
    this->name = "Anonymous";
    this->ip = "127.0.0.1";
    this->port = 1234;
}

/* implementation of particular constructor */

Client::Client(std::string address, int port) {
    this->ip = address;
    this->port = port;

    std::cout << "[!] Write your nickname: ";
    std::getline(std::cin, this->name);
    std::cout << "[!] Choose your friend: ";
    std::getline(std::cin, this->collocutor);
}

/* procedure for connection to server */

void Client::Connect() {
    client_sock = socket(AF_INET, SOCK_STREAM, 0);

    if (client_sock == -1) {
        exit(EXIT_FAILURE);
        return;
    }

    int size_client_addr = sizeof(client_addr);
    int size_server_addr = sizeof(server_addr);

    memset(&client_addr, '\0', (size_t) size_client_addr);
    memset(&server_addr, '\0', (size_t) size_server_addr);

    server_addr.sin_family = PF_INET;
    server_addr.sin_addr.s_addr = inet_addr(this->ip.c_str());
    server_addr.sin_port = htons(this->port);

    connect(this->client_sock, (struct sockaddr*) &server_addr, size_server_addr);

    getsockname(client_sock, (struct sockaddr *) &client_addr, (socklen_t *) &size_client_addr);
    getpeername(client_sock, (struct sockaddr *) &server_addr, (socklen_t *) &size_server_addr);

    // sending nickname of User

    send(client_sock, this->name.c_str(), this->name.length(), 0);

    // print info about server

    std::cout << "Connected to server with IP: ";
    std::cout << inet_ntoa(server_addr.sin_addr);
    std::cout << ":" << ntohs(server_addr.sin_port);
    std::cout << std::endl;
}

/* procedure for sending message */

void Client::Send(std::string message) {
    std::string msg = this->collocutor + "|" + message;

    int __send__ = send(client_sock, msg.c_str(), msg.length(), 0);

    if (__send__ < 0) {
        throw "Error of sending!";
        std::cout << "[!] Message has not sent!" << std::endl;
        return;
    }
}

/* procedure for receiving message */

void Client::Receive(int socket) {
    char buff[1024];
    memset(&buff, '\0', sizeof(buff));

    int __receive__ = recv(client_sock, buff, 1024, 0);

    if (__receive__ < 0) {
        throw "Error of receiving!";
        std::cout << "[!] Message has not received!" << std::endl;
        return;
    }

    std::string msg = "";

    msg += this->collocutor;
    msg += "> ";
    msg += buff;

    std::cout << msg << std::endl;
}

/* procedure for close client socket */

void Client::Close() {
    close(client_sock);
}
