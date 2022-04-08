#include "library.h"
#include <stdio.h>



int main(void)
{
    int cfd = createSocket();
    connectToHost(cfd,"127.0.0.1",8888);

    sleep(2);
    char * str = "hello world";
   
   
    int ret = send(cfd,str,strlen(str),0);
    printf("发送成功的字节数:%d\n",ret);

    sleep(2);
    ret = sendMsg(cfd,str,strlen(str));
    printf("发送成功的字节数:%d\n",ret);



    closeSocket(cfd);





    exit(0);
}
