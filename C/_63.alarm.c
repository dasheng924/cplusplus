#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(void)
{
    alarm(1);
    int i = 0;
    while(1)
    {
        printf("%d\n",i);
        i++;
    }

    exit(0);
}