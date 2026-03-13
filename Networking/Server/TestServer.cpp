#include "TestServer.hpp"

RUSHDY::TestServer::TestServer()
    : SimpleServer(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 3)
{
    launch();
}


void RUSHDY::TestServer::accepter()
{
    ListeningSocket *sock = getSocket();
    struct sockaddr_in address = sock->get_address();
    int addrlen = sizeof(address);
    new_socket = accept(sock->get_socket(), (struct sockaddr *)&address, (socklen_t*)&addrlen);

    read(new_socket, buffer, 30000);
}

void RUSHDY::TestServer::handler()
{
    std::cout << buffer << std::endl;
}

void RUSHDY::TestServer::responder()
{
    char *hello = "Hello from the server";
    write(new_socket, hello, strlen(hello));
    std::cout << "Hello message sent" << std::endl;
    close(new_socket);
}

void RUSHDY::TestServer::launch()
{
    while (true)
    {
        std::cout << "Waiting for a connection..." << std::endl;
        accepter();
        handler();
        responder();
        std::cout << "Connection closed" << std::endl;
    }
}