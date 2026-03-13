#include "ListeningSocket.hpp"

int main()
{
    std::cout << "Starting server..." << std::endl;

    // std::cout << "Simple Socket Server" << std::endl;
    // RUSHDY::SimpleSocket ss = RUSHDY::SimpleSocket(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY);

    std::cout << "Binding socket..." << std::endl;
    RUSHDY::BindingSocket bs = RUSHDY::BindingSocket(AF_INET, SOCK_STREAM, 0, 81, INADDR_ANY);

    std::cout << "Listening for connections..." << std::endl;
    RUSHDY::ListeningSocket ls = RUSHDY::ListeningSocket(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 5);

    std::cout << "Server is listening on port 80..." << std::endl;

}