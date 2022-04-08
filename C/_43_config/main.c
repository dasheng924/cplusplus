#include "configFile.h"



void test()
{

    char ** fileDate = NULL;
    int lines = 0;
    int ret = loadFile_config("./config.ini",&fileDate,&lines) ;
    if(ret == -1)
        return ;
    printf("lines = %d\n",lines) ;

    struct ConfigInfo * CI  = NULL ;

    parseFile_config(fileDate,lines,&CI) ;

    for(int i = 0;i<lines;++i)
    {
        printf("key:%s value:%s\n",CI[i].key,CI[i].value) ;
    }


    printf("%s\n",getConfig("ip",CI,lines)) ;
    printf("%s\n",getConfig("port",CI,lines));


    destory_config(CI) ;
}

int main(void)
{


    test() ;
    return 0;
}