/*************************************************************************
	> File Name: server.cpp
	> Author: fjl_57
	> Mail: 799619622@qq..com 
	> Created Time: Sun 20 Mar 2016 04:49:44 PM CST
 ************************************************************************/

#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<arpa/inet.h>

void print_log(std::string str)
{
#ifndef _DEBUG_
	std::cout<<str<<std::endl;
#endif
}

class server{

public:
	server()
	{
		sock_fd = -1;
		port =8000;
		ip ="127.0.0.1";
	}
	int server_init()
	{
		sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
		if(sock_fd == -1){
			return 2;
		}
		print_log("create sock success");
		struct sockaddr_in local_addr;
		bzero(&local_addr,sizeof(local_addr));
		local_addr.sin_family =AF_INET;
		local_addr.sin_port = htons(port);
		local_addr.sin_addr.s_addr = inet_addr(ip.c_str());
		socklen_t len = sizeof(struct sockaddr_in);
		if( bind(sock_fd,(struct sockaddr*)&local_addr,len) == -1){
			print_log("bind socket fail");
			return 2;
		}
		print_log("bind socket success");
		return 0;

	}

	void get_msg(std::string &msg)
	{
		char buf[1024];
		memset(buf, '\0',sizeof(buf));
		struct sockaddr_in cli;
		socklen_t len = sizeof(struct sockaddr_in);
		int ret = recvfrom(sock_fd, buf, sizeof(buf)-1, 0, (struct sockaddr*)&cli, &len);
		if(ret != -1){
			print_log("get msg success");
			msg = buf;
			std::cout<<"client ip is : "<<inet_ntoa(cli.sin_addr)<<std::endl;

		}else{
			msg="";
		}
	}

	void send_msg(std::string msg)
	{
	
	}
	~server()
	{
		close(sock_fd);
	}
private:
	int sock_fd;
	std::string ip;
	short int port;
};


int main()
{
	server ser;
	ser.server_init();
	std::string msg;
	while(1)
	{
		ser.get_msg( msg );
		std::cout<<msg<<std::endl;
	}
	return 0;
}


