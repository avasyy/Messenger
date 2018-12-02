# Messenger - Simple Console Messenger

[![version](https://badge.fury.io/gh/YuriySavchenko%2FMessenger.svg)](https://github.com/YuriySavchenko/Messenger/releases)

## Console Messenger

Messenger consists from Client and Server.
    ● Client - allows send and receive messages.
    ● Server - allows accept users and send or receive from them messages.

## Compile and Run

We can compile it only on OC Linux and similar OC.
Open terminal and follows next command for downloading:
    ```clone git@github.com:YuriySavchenko/Messenger.git``` or
    ```clone https://github.com/YuriySavchenko/Messenger.git```
After it we can compile project. For this you need copy next commands:
    ```cd Messenger/```
    ```cmake ./ && make ```
In case if all of this commands didn't show errors you will have got two
executable files:
    ● Server - for running your Server.
    ● Client - for running your Clients.

## Execution

Both of executable files work similar.
    ● Server - running once and works to forced stop.
For each User is creating standalone thread which will be receive and send
messages. Server can only print information about Users that connected and
their messages.
    ● Client - each User run program once and it works until forced stop.
For receiving and sending messages creates two different threads. After
start of Client, User need write own ```nickname``` and him ```collocutor```.
If ```collocutor``` already connected to Server so then we can start chatting.