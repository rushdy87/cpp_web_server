// ConnectingSocket.hpp
// This header file defines the ConnectingSocket class, which is a
// derived class of SimpleSocket. The ConnectingSocket class is responsible 
// for establishing a network connection to a remote server. It implements the
// connect_to_network function to connect the socket to the specified 
// address and port using the connect() system call.

#include "SimpleSocket.hpp"

namespace RUSHDY
{
    class ConnectingSocket : public SimpleSocket
    {
    public:
        // Constructor for the ConnectingSocket class. It takes the same parameters as the SimpleSocket constructor and initializes the base class with those parameters.
        ConnectingSocket(int domain, int service, int protocol, int port, u_long interface);
        
        // Virtual function to establish a network connection for the ConnectingSocket class. This function connects the socket to the specified address and port using the connect() system call.
        int connect_to_network(int sock, struct sockaddr_in address);
        
    };
}