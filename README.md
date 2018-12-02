# Messenger - Simple Console Messenger

[![version](https://badge.fury.io/gh/YuriySavchenko%2FMessenger.svg)](https://github.com/YuriySavchenko/Messenger/releases)

## Console Messenger

Messenger consists from Client and Server:
  * _Client_ - allows send and receive messages.
  * _Server_ - allows accept users and send or receive from them messages.
  
## Compile and Run

We can compile it only on OC Linux and similar OC.
Open terminal and follow one of next commands for downloading:

    1. clone https://github.com/YuriySavchenko/Messenger.git

    2. clone https://github.com/YuriySavchenko/Messenger.git
  
After it we can compile project. For this you need copy next commands:

    cd Messenger/
  
    cmake ./ && make
  
In case if all of this commands didn't show errors you will have got two executable files:
  * _Server_ - for running your Server.
  * _Client_ - for running your Clients.
  
## Execution

Both of executable files work similar.
  * _Server_ - running once and works to forced stop. For each User is creating standalone thread which will be receive and send
messages. Server can only print information about Users that are connected and their messages.
  * _Client_ - each User run program once and it works until forced stop. For receiving and sending messages creates two different threads. After start of Client, User need write own __nickname__ and him __collocutor__. If __collocutor__ already connected to Server so then we can start chatting.
