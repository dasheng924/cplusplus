#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include <hiredis/hiredis.h>

#define IP "127.0.0.1"
#define PORT 6379


int main()
{

    redisContext *c = redisConnect(IP,PORT);
    if(c->err)
    {
        redisFree(c);
        perror("connect redis server fail!");
        return -1;
    }
    puts("connect redis server ok!");
    printf("获得的IP和端口,ip == %s,port = %d\n",c->tcp.host,c->tcp.port);

    const char *cmd1 = "set age 12";
    redisReply *reply = (redisReply*)redisCommand(c,cmd1);
    if(reply == NULL)
    {
        redisFree(c);
        perror("command error!");
        return -1;
    }

    if(!(reply->type == REDIS_REPLY_STATUS && strcasecmp(reply->str,"ok") == 0))
    {
        printf("Failed to exec cmd[%s]\n",cmd1);
        freeReplyObject(reply);
        redisFree(c);
        return -1;
    }
    freeReplyObject(reply);


    return 0;
}

