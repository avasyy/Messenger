#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <memory.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include "../../tcp/TCP.h"
#include "../../structures/User.h"


class Server : public TCP {
    /* private section for saving main variables */

    private:
        struct sockaddr_in server_addr;
        struct sockaddr_in client_addr;
        int server_sock;
        int client_sock;
        int port;
        int count;
        std::string ip;
        std::string buffer;
        std::vector<User> users;

    /* explicit and particular constructors */

    public:
        Server();
        Server(std::string, int);

    /* public section for prototypes of all functions */

    public:
        void    Connect() override;
        void    Send(std::string) override;
        void    Receive(int) override;
        void    Close() override;
        void    Accept();

    /* public method for getting value from private variable */

    public:
        int     getSocket();

};

#endif // SERVER_H
