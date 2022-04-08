#include "configFile.h"

//判断是否为有效行
int isVaildLines(char * buf) 
{
    if(buf == NULL)
        return 0;
    if(buf[0] == '#' || buf[0] == '\n' || strchr(buf,':') == NULL)
        return 0;
    return 1;

}
//获得文件有效行数
unsigned int getLines_config(const char * filepath)
{
    if(filepath == NULL)
        return -1;
    FILE * fp = fopen(filepath,"r") ;
    if(fp == NULL)
        perror("open file fail!") ;
        int lines = 0;
        char buf[1024] = {0} ;

    while((fgets(buf,sizeof(buf),fp)) != NULL)
    {
        if(!isVaildLines(buf))
            continue;
        lines++;
    }
    fseek(fp,0,SEEK_SET) ;
    return lines ;
}

//加载配置文件
int  loadFile_config(const char * filepath/*in*/,char ***fileDate/*out*/,int *lines/*out*/) 
{
    if(filepath == NULL || fileDate == NULL || lines == NULL)
        return -1;
    
    unsigned int config_lines = getLines_config(filepath) ;
    if(config_lines == 0)
    {
        printf("%s:%d:%s\n",__FUNCTION__,__LINE__,"文件行数获取失败！" ) ;
        return -1;
    }

    //这里的tmp相当于把整个文件以行为单位存储 ，作为输出
    char **tmp = malloc(sizeof(char *) * config_lines ) ;
    if(tmp == NULL)
        return -1 ;
    
    FILE * fp = fopen(filepath,"r") ;
    if(fp == NULL)
        return -1;
    int i = 0 ;
    char buf[1024] = {0} ;
    while( NULL != (fgets(buf,sizeof(buf),fp)))
    {
        if(!isVaildLines(buf))
            continue;

        tmp[i] = malloc(strlen(buf) +1 );
        strcpy(tmp[i],buf) ;
        memset(buf,0,sizeof(buf));
        i++;
    }
    *fileDate = tmp;
    *lines = config_lines;

    fclose(fp) ;

    return 0 ;
}

//解析配置文件
void parseFile_config(char **fileDate/*in*/,int lines/*in*/,struct  ConfigInfo **info/*out*/) 
{
    if(fileDate == NULL || info == NULL || lines == 0)
        return ;
    //这里的分配内存是形成为一个结构体数组，作为传出参数
    struct ConfigInfo *tmp = malloc(sizeof(struct  ConfigInfo) * lines ) ;
    memset(tmp,0,sizeof(struct ConfigInfo) * lines ) ;
    if(tmp == NULL)
        return ;

    for(int i = 0;i<lines;++i)
    {
        char * pos  = strchr(fileDate[i],':') ;
        strncpy(tmp[i].key,fileDate[i],pos-fileDate[i]);
        strncpy(tmp[i].value,pos+1,strlen(pos+1) -1) ;

        //printf("key:%s value:%s\n",tmp[i].key,tmp[i].value) ;   
    }
    *info = tmp ;

    for(int i = 0;i<lines;++i)
    {
        if(fileDate[i] != NULL)
        {
            free(fileDate[i]);
            fileDate[i] = NULL ;
        }
    }
}

//获得指定配置信息
char * getConfig(const char *key/*in*/,struct ConfigInfo * info/*in*/,const int lines/*in*/) 
{

    if(key == NULL || info == NULL)
        return NULL ;
    for(int i = 0;i<lines;++i)
    {
        if(strcasecmp(key,info[i].key) == 0)
            return info[i].value ;
    } 
    return NULL;
}

//释放配置文件信息
void destory_config(struct ConfigInfo * info) 
{
    if(info != NULL)
    {
        free(info);
        info = NULL ;
    }
}




