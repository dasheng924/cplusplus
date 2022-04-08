#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 6666
#define IP "127.0.0.1"



int main()
{
	int cfd;
	char buf[BUFSIZ];
	int n;
	socklen_t s_len;
	struct sockaddr_in s_addr;

	memset(&s_addr,0,sizeof(s_addr));

	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(PORT);
	inet_pton(AF_INET,IP,&s_addr.sin_addr.s_addr);

	s_len = sizeof(s_addr);
	cfd = socket(AF_INET,SOCK_STREAM,0);

	connect(cfd,(struct sockaddr*)&s_addr,s_len);

	while(1){
	fgets(buf,sizeof(buf),stdin);
	write(cfd,buf,strlen(buf));
	n = read(cfd,buf,sizeof(buf));
	write(STDOUT_FILENO,buf,n);
	}


	close(cfd);



	return 0;
}