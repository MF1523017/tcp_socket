#include"client.h"
Client::Client(const char *hostname, const char *port) :Common(hostname, port)
{
	_client_fd= socket(AF_INET, SOCK_STREAM, 0);
	connect(_client_fd, (SA*)&_addr, sizeof(_addr));
}
void testClient()
{
	Client  c("127.0.0.1", "2222");
	std::cout << c.sock_ntop() << std::endl;
}