#pragma once
#include<sys/socket.h>
#include<netinet/in.h>
#include<string>
#include<cstring>

class Common
{
	
protected:
	struct sockaddr_in _addr;

public:
	typedef struct sockaddr SA;
	Common(const char *hostname, const char *port);
	std::string	 sock_ntop();
	virtual ~Common()
	{
		bzero(&_addr, sizeof(_addr));
	}
};
void testCommon();