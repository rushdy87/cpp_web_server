// BindingSocket.hpp
// This header file defines the BindingSocket class, which is a 
// derived class of SimpleSocket.

#include "SimpleSocket.hpp"
namespace RUSHDY
{
    class BindingSocket : public SimpleSocket
    {
    public:
        // Constructor for the BindingSocket class. It takes the same parameters 
        // as the SimpleSocket constructor and initializes the base class with those 
        // parameters.
        BindingSocket(int domain, int service, int protocol, int port, u_long interface);
        
        // Virtual function to establish a network connection for the BindingSocket 
        // class. This function binds the socket to the specified address and port 
        // using the bind() system call.
        int connect_to_network(int sock, struct sockaddr_in address);
    };
}