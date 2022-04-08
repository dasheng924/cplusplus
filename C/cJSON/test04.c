// 解析 {\"name\":\"luffy\",\"sex\":\"man\",\"age\":19}

#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main(void)
{
    const char *s = "{\"name\":\"luffy\",\"sex\":\"man\",\"age\":19}";
    cJSON *root = cJSON_Parse(s);
    if(!root)
    {
        printf("get root fail!\n");
        cJSON_Delete(root);
    }
    cJSON *item = cJSON_GetObjectItem(root,"name");
    if(item->type == cJSON_String)
    {
        printf("name:%s\n",item->valuestring);
    }
    item = cJSON_GetObjectItem(root,"sex");
    if(item->type == cJSON_String)
    {
        printf("sex:%s\n",item->valuestring);
    }
    item = cJSON_GetObjectItem(root,"age");
    if(item->type == cJSON_Number)
    {
        printf("age:%d\n",item->valueint);
    }

    cJSON_Delete(root);

    return  0;
}