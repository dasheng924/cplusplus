#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <ctype.h>
#include <arpa/inet.h>

#define PORT 6666
#define IP "127.0.0.1"

int main()
{
	int lfd,cfd;
	socklen_t c_len;
	char buf[BUFSIZ];//BUFSIZ 4k/8k
	int count;
	struct sockaddr_in s_addr,c_addr;
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(6666); 
	s_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
	//创建套接字
	lfd = socket(AF_INET,SOCK_STREAM,0);
	//绑定套接字
	bind(lfd,(struct sockaddr*)&s_addr,sizeof(s_addr));

	listen(lfd,128);

	c_len = sizeof(c_addr);
	cfd = accept(lfd,(struct sockaddr*)&c_addr,&c_len);
	
	
	char buf_cIP[32];
	socklen_t cIPlen;
	printf("client ip:%s,port:%d\n",inet_ntop(AF_INET,&c_addr.sin_addr.s_addr,buf_cIP,sizeof(buf_cIP)),ntohs(c_addr.sin_port));

	while(1){
	count = read(cfd,buf,sizeof(buf));
	write(STDOUT_FILENO,buf,count);	
	for(int i = 0;i<count;i++)
	{
		buf[i] = toupper(buf[i]);
	}

	write(cfd,buf,count);
	}
	close(lfd);
	close(cfd);
	
	return 0;
}