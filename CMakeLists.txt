cmake_minimum_required(VERSION 3.10)
project(ClientServer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Server src/server/mainServer.cpp src/server/headers/server.h src/server/cpp/server.cpp)
add_executable(Client src/client/mainClient.cpp src/client/headers/client.h src/client/cpp/client.cpp src/tcp/TCP.h src/structures/User.h)

find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
    target_compile_options(Client PUBLIC "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
    target_link_libraries(Client "${CMAKE_THREAD_LIBS_INIT}")
endif()

find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
    target_compile_options(Server PUBLIC "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
    target_link_libraries(Server "${CMAKE_THREAD_LIBS_INIT}")
endif()