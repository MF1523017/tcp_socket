#pragma once
#include<sys/socket.h>
#include<netinet/in.h>
#include<string>

class Common
{
	
protected:
	struct sockaddr_in _addr;

public:
	typedef struct sockaddr SA;
	Common(char *hostname, const char *port);
	std::string	 sock_ntop();

};
void testCommon();