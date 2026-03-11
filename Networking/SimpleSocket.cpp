#include "SimpleSocket.hpp"

// Constructor for the SimpleSocket class. It takes three parameters: domain, service, and protocol.
RUSHDY::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface)
{
    // Initialize the address structure with the provided parameters.
    address.sin_family = domain; // Set the address family (e.g., AF_INET for IPv4).
    address.sin_port = htons(port); // 1)Set the port number. 2)htons() converts the port number from host byte order to network byte order.
    address.sin_addr.s_addr = htonl(interface); // Set the IP address to accept connections from any interface.
    
    // Create a socket using the provided parameters and store the connection descriptor in the member variable 'sock'.
    sock = socket(domain, service, protocol); // Create a socket using the provided parameters.
    test_connection(sock); // Test the socket connection using the test_connection member function.
    
    // Call the pure virtual function connect_to_network to establish a network connection and store the result in the member variable 'connection'.
    connection = connect_to_network(sock, address); // Call the pure virtual function to establish a network connection and store the result in the member variable 'connection'.
    test_connection(connection); // Test the network connection using the test_connection member function.
}

// Implementation of the test_connection member function. It takes an integer parameter 'item_to_test' and checks if it is less than 0, indicating a failed connection.
void RUSHDY::SimpleSocket::test_connection(int item_to_test)
{
    if(item_to_test < 0){
        perror("Connection failed"); // Print an error message if the connection test fails.
        exit(EXIT_FAILURE); // Exit the program with a failure status.
    }
}

// Implementation of the get_address member function. It returns the address structure of the SimpleSocket instance.
struct sockaddr_in RUSHDY::SimpleSocket::get_address()
{
    return address; // Return the address structure.
}
// Implementation of the get_socket member function. It returns the socket descriptor of the SimpleSocket instance.
int RUSHDY::SimpleSocket::get_socket()
{
    return sock; // Return the socket descriptor.
}
// Implementation of the get_connection member function. It returns the connection descriptor of the SimpleSocket instance.
int RUSHDY::SimpleSocket::get_connection()
{
    return connection; // Return the connection descriptor.
}