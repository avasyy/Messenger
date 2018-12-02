#include <iostream>
#include "headers/server.h"
#include <thread>

/* function which allows create thread for desired client */

void ClientHandler(Server **server, int socket) {
    while (true) {
        (*server)->Receive(socket);
        (*server)->Send("__null__");
    }
}

int main(int argc, char *argv[])
{
    Server *server = new Server("127.0.0.1", 5576);

    server->Connect();

    std::vector<std::thread> v_thr;
    
    while (true) {
        server->Accept();
        int socket = server->getSocket();
        v_thr.push_back(std::thread(ClientHandler, &server, socket));
    }

    std::vector<std::thread>::iterator it;

    for (it=v_thr.begin(); it != v_thr.end(); it++) {
        (*it).join();
    }

    server->Close();

    return 0;
}
