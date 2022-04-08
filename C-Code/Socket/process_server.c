#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <unistd.h>


#define PORT 8888
#define IP "127.0.0.1"

int main()
{
	int lfd,cfd;
	pid_t pid;
	socklen_t client_addr_len;
	char buf[BUFSIZ];

	lfd = socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in server_addr,client_addr;

	bzero(&server_addr,sizeof(server_addr));
	server_addr.sin_port = htons(PORT);
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	//inet_pton(AF_INET,"127.0.0.1",&server_addr.sin_addr.s_addr);

	bind(lfd,(struct sockaddr*)&server_addr,sizeof(server_addr));

	listen(lfd,128);

	while(1){
		client_addr_len = sizeof(client_addr);
		cfd = accept(lfd,(struct sockaddr*)&client_addr,&client_addr_len);


		pid = fork();
		if(pid == -1){
			perror("fork error");
			exit(1);
		}
		else if(pid == 0){
			close(lfd);
			break;	
		}
		else{
			close(cfd);
		}

	}

	if(pid == 0){
		while(1){
			int n  = read(cfd,buf,sizeof(buf));
			if (n == 0){
				close(cfd);
				return 0;
			}
			else if( n == -1){
				perror("read err");
				exit(1);
			}
			else{
				for(int i = 0;i<n;i++){
					buf[i] = toupper(buf[i]);
				}
				write(cfd,buf,n);
			}
		}
	}

	return 0;
}



