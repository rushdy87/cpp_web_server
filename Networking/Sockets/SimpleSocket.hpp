// SimpleSocket.hpp
// This header file defines the SimpleSocket class, which serves as a 
// base class for creating and managing socket connections in a network 
// application. The SimpleSocket class provides basic functionality for 
// initializing a socket, testing connections, and retrieving socket 
// information. It also declares a pure virtual function connect_to_network 
// that must be implemented by derived classes to establish a network 
// connection using the provided socket and address.

#include <iostream> // For input/output operations
#include <sys/socket.h> // socket library
#include <netinet/in.h> // sockaddr_in structure

namespace RUSHDY
{
    class SimpleSocket
    {
    private:
    struct sockaddr_in address;
     // This member variable will hold the socket connection descriptor.
    int sock;
     // This member variable will hold the connection descriptor for accepted connections.
    int connection;
        
    public:
        // Constructor declaration for the SimpleSocket class. It takes parameters for domain, service, protocol, port, and interface.
        // The constructor will initialize the socket and establish a network connection using the provided parameters.
        SimpleSocket(int domain, int service, int protocol, int port, u_long interface); // Constructor declaration for the SimpleSocket class.
        
        // Declaration of a pure virtual function connect_to_network. This function will be implemented by derived classes to establish a network connection using the provided socket and address.
        virtual int connect_to_network(int sock, struct sockaddr_in address) = 0; // Pure virtual function to establish a network connection. This makes SimpleSocket an abstract class.
        
        // Declaration of the test_connection member function. This function will be used to test the validity of a connection by checking if the provided item (e.g., socket or connection descriptor) is valid.
        void test_connection(int); // A member function to test the connection. The implementation of this function is not provided in the header file.
        
        // Getter functions to retrieve the address structure, socket descriptor, and connection descriptor of the SimpleSocket instance.
        struct sockaddr_in get_address(); // Getter function to retrieve the address structure.
        int get_socket(); // Getter function to retrieve the socket descriptor.
        int get_connection(); // Getter function to retrieve the connection descriptor.

        // Setters
        void set_connection(int connection); // Setter function to set the connection descriptor.
    };
}