// ListeningSocket.cpp
#include "ListeningSocket.hpp"

// Constructor for the ListeningSocket class. 
// It initializes the base class (BindingSocket) with 
// the provided parameters and sets the backlog member variable.
RUSHDY::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int backlog)
    : BindingSocket(domain, service, protocol, port, interface)
{
    this->backlog = backlog;
    start_listening();
    test_connection(listening);
}

// This function starts listening for incoming connections on the socket.
// It uses the listen() system call to mark the socket as a passive socket 
// that will be used to accept incoming connection requests.
void RUSHDY::ListeningSocket::start_listening()
{
    listening = listen(get_connection(), backlog);
}