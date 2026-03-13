// ListeningSocket.hpp

#include "BindingSocket.hpp"

namespace RUSHDY {
    class ListeningSocket : public BindingSocket
    {
    private:
        // Private member variables can be declared here if needed.
        int backlog; // The maximum length of the queue of pending connections.
        int listening; // The file descriptor for the listening socket.
    public:
        // Constructor that initializes the listening socket with the specified parameters.
        // Parameters:
        // - domain: The communication domain (e.g., AF_INET for IPv4).
        // - service: The type of service (e.g., SOCK_STREAM for TCP).
        // - protocol: The protocol to be used (e.g., IPPROTO_TCP).
        // - port: The port number on which the socket will listen for incoming connections.
        // - backlog: The maximum length of the queue of pending connections.
        ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int backlog);
        void start_listening();
    };
}