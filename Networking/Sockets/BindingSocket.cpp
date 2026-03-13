#include "BindingSocket.hpp"


// Constructor for the BindingSocket class. It takes the same parameters as the SimpleSocket constructor and initializes the base class with those parameters.
RUSHDY::BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long interface) : SimpleSocket(domain, service, protocol, port, interface)
{
    set_connection(connect_to_network(get_socket(), get_address())); // Call the connect_to_network function to bind the socket to the specified address and port.
    test_connection(get_connection()); // Test the result of the bind operation using the test_connection member function.
}

// Override the pure virtual function to establish a network connection for the BindingSocket class. This function binds the socket to the specified address and port using the bind() system call.
int RUSHDY::BindingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
    // Bind the socket to the specified address and port using the bind() system call.
    return bind(sock, (struct sockaddr *)&address, sizeof(address)); // Bind the socket to the specified address and port and return the result of the bind operation.
}