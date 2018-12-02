//
// Created by yuriy on 10/17/18.
//

#ifndef CLIENTSERVER_TCP_H
#define CLIENTSERVER_TCP_H

#include <iostream>
#include <string>

class TCP {
    protected:
        virtual void Connect() = 0;
        virtual void Send(std::string) = 0;
        virtual void Receive(int) = 0;
        virtual void Close() = 0;
};


#endif //CLIENTSERVER_TCP_H
