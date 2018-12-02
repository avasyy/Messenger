#include <iostream>
#include <string>
#include <thread>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <memory.h>

/* invoke file with class Client */

#include "headers/client.h"

/* procedure which allows sending messages in alone tread */

void SendMsgHandler(Client **client) {
    while (true) {
        try {
            std::string message;
            std::getline(std::cin, message);
            (*client)->Send(message);
        }

        catch (std::string err) {
            std::cerr << "[?] " << err << std::endl;
        }
    }
}

/* procedure which allows receiving messages in alone thread */

void ReceiveMsgHandler(Client **client) {
    while (true) {
        try {
            (*client)->Receive(0);
        }
        catch (std::string err) {
            std::cout << "[?] " << err << std::endl;
        }
    }

    (*client)->Close();
}

int main(int argc, char *argv[])
{
    Client *client = new Client("127.0.0.1", 5576);
    client->Connect();

    std::thread thr_send = std::thread(SendMsgHandler, &client);
    std::thread thr_recv = std::thread(ReceiveMsgHandler, &client);

    thr_send.join();
    thr_recv.join();

    client->Close();

    return 0;
}
