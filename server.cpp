#include"server.h"
#include<iostream>
#include<arpa/inet.h>
Server::Server(const char *port) :Common("", port) {
	
	_server_fd = socket(AF_INET, SOCK_STREAM, 0);
	bind(_server_fd,(SA*)&_addr, sizeof(_addr));
	_listen(_server_fd, 10);
}
void Server::_listen(int fd, int backlog)
{
	char *ptr = getenv("LISTENQ");
	if (ptr != nullptr)
		backlog = atoi(ptr);
	std::cout <<"backlog="<< backlog << std::endl;
	if (listen(fd, backlog) < 0)
		std::cout<<"listen error"<<std::endl;
}
void Server::server_test()
{
	char buff[1024];
	struct sockaddr_in cliaddr;
	for (;;)
	{
		socklen_t len = sizeof(cliaddr);
		_connfd = accept(_server_fd, (SA*)&cliaddr, &len);
		std::cout << "connection from "
			<< inet_ntop(AF_INET, &cliaddr, buff, sizeof(buff))
			<< ",port " << ntohs(cliaddr.sin_port) << std::endl;
		close(_connfd);
	}
}


void testServer()
{
	Server test("2222");
	std::cout << test.sock_ntop() << std::endl;
	test.server_test();
}