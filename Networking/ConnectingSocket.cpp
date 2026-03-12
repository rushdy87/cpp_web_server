#include "ConnectingSocket.hpp"

// Constructor for the ConnectingSocket class. It takes the same parameters as the SimpleSocket constructor and initializes the base class with those parameters.
RUSHDY::ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, u_long interface) : SimpleSocket(domain, service, protocol, port, interface)
{
    set_connection(connect_to_network(get_socket(), get_address())); // Call the connect_to_network function to connect the socket to the specified address and port.
    test_connection(get_connection()); // Test the result of the connect operation using the test_connection member function.
}

// Definition of the connect_to_network function for the ConnectingSocket class. This function connects the socket to the specified address and port using the connect() system call.
int RUSHDY::ConnectingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
    // Connect the socket to the specified address and port using the connect() system call.
    return connect(sock, (struct sockaddr *)&address, sizeof(address)); // Connect the socket to the specified address and port and return the result of the connect operation.
}
