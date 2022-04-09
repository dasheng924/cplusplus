#include <stdio.h>

typedef struct SS
{
    int *p;
    char a;

} SS;

int main(void)
{

    int *p = NULL;
    double *pp = NULL;
    char *ppp = NULL;
    SS *q = NULL;

    printf("sizeof(p)=%lu\n",sizeof p);
    printf("sizeof(pp)=%lu\n",sizeof pp);
    printf("sizeof(ppp)=%lu\n",sizeof pp);
    printf("sizeof(q)=%lu\n",sizeof q);


    return 0;
}
