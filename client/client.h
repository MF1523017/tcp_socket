#pragma once
#include"common.h"
#include<unistd.h>
#include<iostream>

class Client:public Common
{
private:
	int _client_fd;
public:
	Client(const char *hostname, const char *port);
    void str_cli(std::istream &is);
	~Client() {
		close(_client_fd);
	}
};

void testClient();
