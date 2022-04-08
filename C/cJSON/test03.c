
//解析 {\"names\":[\"luffy\",\"robin\"]}

#include <stdlib.h>
#include <stdio.h>
#include "cJSON.h"


int main()
{
    const char *s = "{\"names\":[\"luffy\",\"robin\"]}";

    cJSON *root = cJSON_Parse(s);
    if(!root)
    {
        printf("get root fail!\n");
        return -1;
    }
    cJSON *list = cJSON_GetObjectItem(root,"names");
    if(!list)
    {
        printf("no list!\n");
        return -1;
    }

    int array_size = cJSON_GetArraySize(list);
    printf("json数组的大小为:%d\n",array_size);
    for(int i = 0;i<array_size;++i)
    {
        cJSON *item = cJSON_GetArrayItem(list,i);
        if(item->type == cJSON_String)
        {
            printf("item type is %d\n",item->type);
            printf("#define cJSON_String 4\n");
            printf("%s\n",item->valuestring);
        }
    }

    if(root)
    {
        cJSON_Delete(root);
    }

    return 0 ;
}