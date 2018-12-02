#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <memory.h>
#include "../../tcp/TCP.h"

class Client : public TCP {
    /* private section for saving main variables */

    private:
        struct sockaddr_in client_addr;
        struct sockaddr_in server_addr;
        int client_sock;
        int port;
        std::string name;
        std::string collocutor;
        std::string ip;

    /* prototypes of explicit and particular constructors */

    public:
        Client();
        Client(std::string, int);

    /* public section for prototypes of all function */

    public:
        void     Connect() override;
        void     Send(std::string) override;
        void     Receive(int) override;
        void     Close() override;

};

#endif // CLIENT_H
