#include <stdio.h>
#include "cJSON.h"
#include <stdlib.h>


void test_jsonArray()
{
    cJSON *root; //创建一个根节点
    root= cJSON_CreateArray();//创建JSON数组
    cJSON_AddItemToArray(root,cJSON_CreateString("Hello world"));
    cJSON_AddItemToArray(root,cJSON_CreateNumber(999));
    cJSON_AddItemToArray(root,cJSON_CreateFalse());
    cJSON_AddItemToArray(root,cJSON_CreateTrue());
    cJSON_AddItemToArray(root,cJSON_CreateNull());
    cJSON_AddItemToArray(root,cJSON_CreateString("Apple"));



    char *s = cJSON_PrintUnformatted(root);
    if(s)
    {
        printf("%s\n",s);
        free(s);
    }

    cJSON_Delete(root);
}




int main(void)
{

    cJSON *root = cJSON_CreateObject();//创建根节点

    //添加元素
    cJSON_AddItemToObject(root,"name",cJSON_CreateString("sungs"));
    cJSON_AddItemToObject(root,"sex",cJSON_CreateString("man"));
    cJSON_AddItemToObject(root,"age",cJSON_CreateNumber(24));
    cJSON_AddItemToObject(root,"score",cJSON_CreateNumber(100));

    //转化为json字符串
    char *s = cJSON_Print(root);
    if(s)
    {
        printf("%s\n",s);
        free(s);//cJSON_PrintUnformatted 调用了malloc
    }

    cJSON_Delete(root);

    return 0;
}