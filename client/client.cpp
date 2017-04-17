#include"client.h"
#include<stdio.h>
#include<string>
#include<cstring>
using std::string;
Client::Client(const char *hostname, const char *port) :Common(hostname, port)
{
	_client_fd= socket(AF_INET, SOCK_STREAM, 0);
	connect(_client_fd, (SA*)&_addr, sizeof(_addr));
}
void Client::str_cli(std::istream &is)
{
   string input;
   while(is>>input)
   {
      char buff[max_buffer];
      write(_client_fd,input.c_str(),input.size());
      if(read(_client_fd,buff,max_buffer)==0)
      {   std::cout<<"read from server error!\n";
          break;
      }
//      puts(buff);
      write(STDOUT_FILENO,buff,input.size());
      std::cout<<std::endl;
   }

}
                   
void testClient()
{
	Client  c("192.168.182.128", "2222");
	std::cout << c.sock_ntop() << std::endl;
    c.str_cli(std::cin);
}

