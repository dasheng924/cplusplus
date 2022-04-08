#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct ConfigInfo
{
    char key[64];
    char value[128];
};


#ifdef __cpluscplus
extern "C"{
#endif

//获得文件有效行数
unsigned int getLines_config(const char * filepath) ;

//判断是否为有效行
int  isVaildLines(char * buf) ;

//加载配置文件
int  loadFile_config(const char * filepath/*in*/,char ***fileDate/*out*/,int *lines/*out*/) ;

//解析配置文件
void parseFile_config(char **fileDate/*in*/,int lines/*in*/,struct  ConfigInfo **info/*out*/) ;

//获得指定配置信息
char * getConfig(const char *key,struct ConfigInfo * info,const int lines) ;

//释放配置文件信息
void destory_config(struct ConfigInfo * info) ;


   // __declspec(dllexport)  //这个是windows下的动态库声明时要加入的 



#ifdef __cpluscplus
}
#endif