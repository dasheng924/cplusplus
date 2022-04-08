#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <strings.h>
#include <fcntl.h>

#define IP "127.0.0.1"
#define PORT 6666

void err_int(int ret,const char * str)
{
	if(ret == -1)
	{
		perror(str);
		exit(1);
	}

}
int  main() 
{
	int server_fd,client_fd;
	char buf[BUFSIZ];
	//创建套接字
	server_fd =socket(AF_INET,SOCK_STREAM,0);
	err_int(server_fd,"socket error");
	//绑定套接字
	struct sockaddr_in s_addr,c_addr;
	socklen_t s_len,c_len;
	bzero(&s_addr,sizeof(s_addr));
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(PORT);
	s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	s_len = sizeof(s_addr);

	int ret_bind = bind(server_fd,(struct sockaddr*)&s_addr,s_len);
	err_int(ret_bind,"bind err");
	//设置监听最大同时连接数
	int ret_listen = listen(server_fd,128);
	err_int(ret_listen,"listen error");
	//阻塞等待客户端连接
	c_len = sizeof(c_addr);
	client_fd = accept(server_fd,(struct sockaddr*)&c_addr,&c_len);
	err_int(client_fd,"accept error");
	
	//若连接之后，打印出连接的客户端IP和PORT
	char buf_cIP[32];
	printf("client ip:%s,port:%d\n",inet_ntop(AF_INET,&c_addr.sin_addr.s_addr,buf_cIP,sizeof(buf_cIP)),ntohs(c_addr.sin_port));


	//获取客户端发过来的内容，打印到屏幕上，并且把内容放到server_client文件中
	int fd_file = open("server_client",O_RDWR | O_CREAT ,0644);
	err_int(fd_file,"open new file error");
	

	while(1)
	{
		int len = read(client_fd,buf,sizeof(buf));
		write(fd_file,buf,len);
		printf("客户端：\n");
		write(STDOUT_FILENO,buf,len);
		for(int i = 0;i<len;i++)
		{
			buf[i] = toupper(buf[i]);
		}
		write(client_fd,buf,len);
	}

	close(server_fd);
	close(client_fd);
	close(fd_file);




	return 0;
}
