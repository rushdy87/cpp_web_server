#include "SimpleServer.hpp"
#include <unistd.h>

namespace RUSHDY
{
    class TestServer : public SimpleServer
    {
    private:
        char buffer[30000] = {0};
        int new_socket;
        void accepter() override;
        void handler() override;
        void responder() override;
    public:
        TestServer();        
        void launch() override;
    };
}