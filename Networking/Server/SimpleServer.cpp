#include "SimpleServer.hpp"

RUSHDY::SimpleServer::SimpleServer(int domain, int service, int protocol, int port, u_long interface, int backlog)
{
    socket = new ListeningSocket(domain, service, protocol, port, interface, backlog);

}

RUSHDY::ListeningSocket* RUSHDY::SimpleServer::getSocket()
{
    return socket;
}