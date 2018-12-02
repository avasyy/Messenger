//
// Created by yuriy on 10/26/18.
//

#ifndef CLIENTSERVER_USER_H
#define CLIENTSERVER_USER_H

#include <iostream>
#include <string>

/* special simple structure for saving data of User on the Server */

struct User {
    int id;
    int data;
    std::string ip;
    std::string name;
};

#endif //CLIENTSERVER_USER_H
