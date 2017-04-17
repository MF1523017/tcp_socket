#include"server.h"
#include<iostream>
#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<signal.h>

Server::Server(const char *port) :Common("", port) {
	_addr.sin_addr.s_addr = htonl(INADDR_ANY);//INADDR_ANY
	_server_fd = socket(AF_INET, SOCK_STREAM, 0);
	bind(_server_fd,(SA*)&_addr, sizeof(_addr));
	_listen(_server_fd, 10);
    signal(SIGCHLD,sig_child);
}
void Server::_listen(int fd, int backlog)
{
	char *ptr = getenv("LISTENQ");
	if (ptr != NULL)
		backlog = atoi(ptr);
	std::cout <<"backlog="<< backlog << std::endl;
	if (listen(fd, backlog) < 0)
		std::cout<<"listen error"<<std::endl;
}

void Server::str_echo(int sockfd)
{
    char buff[max_buffer];
    while(read(sockfd,buff,max_buffer)>0)
            write(sockfd,buff,max_buffer);
}
void Server::server_test()
{
	char buff[max_buffer];
	struct sockaddr_in cliaddr;
	for (;;)
	{
		socklen_t len = sizeof(cliaddr);
		_connfd = accept(_server_fd, (SA*)&cliaddr, &len);
		std::cout << "connection from "
			<< inet_ntop(AF_INET, &cliaddr, buff, sizeof(buff))
			<< ",port " << ntohs(cliaddr.sin_port) << std::endl;
        pid_t childpid;
        if((childpid=fork())==0)
        {
            close(_server_fd);
            str_echo(_connfd);
            exit(0);
        }
		close(_connfd);
	}
}


void testServer()
{
	Server test("2222");
	std::cout << test.sock_ntop() << std::endl;
	test.server_test();
}
void sig_child(int signo)
{
    pid_t pid;
    int stat;
    while((pid=waitpid(-1,&stat,WNOHANG))>0)
        printf("child %d terminated\n",pid);
    return;
}
