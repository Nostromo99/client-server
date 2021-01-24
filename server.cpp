#include <iostream>
#include <asio.hpp>
using namespace asio;
using ip::tcp;

class Server{
    protected:
    asio::io_service service;
    std::thread asio_thread;
    tcp::acceptor s_acceptor;
    tcp::socket socket{service};

   public:
    Server(uint16_t port_num)
    :s_acceptor(service,tcp::endpoint(tcp::v4(),port_num))
    {
    }
   
    void run(){
            std::cout<<"running";
            s_acceptor.listen();
            s_acceptor.async_accept([this](std::error_code e,tcp::socket sock){
                if(!e){
                    std::cout<<"connection success";
                    run();
                }
            });
            service.run();
    }
  
    void stop(){

    }
    protected:
    void send(){

    }
    

};
int main() {
    
    Server serv(2000);
    serv.run();
}