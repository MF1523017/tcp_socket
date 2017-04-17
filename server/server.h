#pragma once
#include"common.h"
#include<unistd.h>
class Server:public Common
{
	
private:
	int _server_fd;
	int _connfd;
    const int max_buffer=1024;
	void _listen(int fd, int backlog);
public:
	Server(const char *port);// : Commont("", port){}
	void server_test();
    void str_echo(int sockfd);
	~Server()
	{
		close(_server_fd);
		close(_connfd);
	}
};

    void sig_child(int signo);
void testServer();
