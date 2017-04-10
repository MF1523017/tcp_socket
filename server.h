#pragma once
#include"common.h"
#include<unistd.h>
class Server:public Common
{
	
private:
	int _server_fd;
	int _connfd;
	void _listen(int fd, int backlog);
public:
	Server(const char *port);// : Commont("", port){}
	void server_test();
};

void testServer();