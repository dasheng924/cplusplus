#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



int main(void)
{
	//socket
	int cfd = socket(AF_INET,SOCK_STREAM,0);
	if(cfd ==-1)
	{
		perror("socker error!");
		return -1;
	}

	struct sockaddr_in caddr;
	caddr.sin_family = AF_INET;
	caddr.sin_port = htons(8888);
	inet_pton(cfd,"10.211.55.11",&caddr.sin_addr.s_addr);
	int ret = connect(cfd,(struct sockaddr*)&caddr,sizeof(caddr));
	if(ret == -1)
	{
		perror("connect error!");
		return -1;
	}

	char recv_buf[1024] ;
	char send_buf[1024];
	while(1)
	{
		bzero(send_buf,sizeof(send_buf));
		bzero(recv_buf,sizeof(recv_buf));
		fgets(send_buf,sizeof(send_buf),stdin);
		int len = send(cfd,send_buf,sizeof(send_buf),0);
		if(len > 0)
		{
			int ret = recv(cfd,recv_buf,len,0);
			if(ret > 0)
				fputs(recv_buf,stdout);
		}
		else if(len == 0)
		{
			perror("server connect error!");
			break;
		}
		else{
			perror("error!");
			break;

		}
	}
	close(cfd);

	return 0;
}