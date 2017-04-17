#include"common.h"
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<arpa/inet.h>
using std::string;
Common::Common(const char *hostname,const char *port)
{
	bzero(&_addr, sizeof(_addr));
	_addr.sin_family = AF_INET;
//	_addr.sin_addr.s_addr = htonl(INADDR_ANY);//INADDR_ANY
	//std::cout << "_addr.sin_addr.s_addr="<<_addr.sin_addr.s_addr << std::endl;
	_addr.sin_port = htons(static_cast<short>(atoi(port)));
	std::cout << "_addr.sin_port=" << _addr.sin_port << std::endl;

}
string Common::sock_ntop()
{
	char str[128];
	if (inet_ntop(AF_INET, &_addr.sin_addr, str, sizeof(str)) == NULL)
		return string("");
	return string(str);
}

void testCommon()
{
	Common test("127.0.0.1", "22222");
	std::cout << test.sock_ntop() << std::endl;
}
