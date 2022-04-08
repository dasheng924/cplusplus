#include <stdio.h>
#include <string.h>

void selectSort(char *p[] ,int len)
{

    int min = 0;
    for(int i = 0;i<len-1;++i)
    {
        min = i ;
        for(int j = i+1;j<len;++j)
        {
            if(strcmp(p[j],p[min]) < 0 )
            {
                min = j ;
            }
        }
        if(min != i)
        {
            
           char * tmp = p[min] ;
           p[min] = p[i];
           p[i] = tmp;
        }
    }


}

void show(char *p[],int len)
{
    for(int i = 0;i<len;++i)
    {
        puts(p[i]);
    }
    puts("--------------------------") ;
}

int main(void)
{

    char * str[] = {
        "aaa",
        "fee",
        "dwedwd",
        "ovlr"
    };

    unsigned int len  = sizeof(str)/sizeof(char *) ;
    //printf("%zu\t%zu\n",sizeof(str),sizeof(char*)) ;

    show(str,len) ;

    selectSort(str,len) ;
    show(str,len) ;

    return 0 ;
}