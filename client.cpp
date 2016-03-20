/*************************************************************************
	> File Name: client.cpp
	> Author: fjl_57
	> Mail: 799619622@qq..com 
	> Created Time: Sun 20 Mar 2016 04:49:44 PM CST
 ************************************************************************/

#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<arpa/inet.h>

class client{

public:
	client()
	{
		sock_fd = -1;
		port =8000;
		ip ="127.0.0.1";
	}
	int client_init()
	{
		sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
		if(sock_fd == -1){
			return 1;
		}
		return 0;

	}

	void get_msg(std::string &msg)
	{
		
	}

	void send_msg(std::string msg)
	{
		struct sockaddr_in ser;
		bzero(&ser,sizeof(ser));
		ser.sin_family =AF_INET;
		ser.sin_port = htons(port);
		ser.sin_addr.s_addr = inet_addr(ip.c_str());
		socklen_t len = sizeof(struct sockaddr_in);
		sendto(sock_fd,msg.c_str(),msg.size(),0,(struct sockaddr *)&ser,len);
	
	}
	~client()
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
	client cli;
	cli.client_init();
	while(1)
	{
		sleep(1);
		cli.send_msg("this is a test ");
	}
	return 0;
}


