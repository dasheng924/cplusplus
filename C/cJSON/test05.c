 // {\"list\":{\"name\":\"luffy\",\"age\":19},\"other\":{\"name\":\"ace\"}}

#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main()
{
    const char *s = "{\"list\":{\"name\":\"luffy\",\"age\":19},\"other\":{\"name\":\"ace\"}}";
    cJSON *root = cJSON_Parse(s);
    if(!root)
    {
        cJSON_Delete(root);
        return -1;
    }

    cJSON *item1 = cJSON_GetObjectItem(root,"list");
    if(item1->type == cJSON_Object)
    {
        cJSON *item11 = cJSON_GetObjectItem(item1,"name");
        if(item11->type == cJSON_String)
        {
            printf("name:%s\n",item11->valuestring);
        }
        item11 = cJSON_GetObjectItem(item1,"age");
        if(item11->type == cJSON_Number)
        {
            printf("age:%d\n",item11->valueint);
        }
    }

    cJSON *item2 = cJSON_GetObjectItem(root,"other");
    if(item2->type == cJSON_Object)
    {
        cJSON *item21 = cJSON_GetObjectItem(item2,"name");
        if(item21->type == cJSON_String)
        {
            printf("name:%s\n",item21->valuestring);
        }
      
    }
    if(root)
        cJSON_Delete(root);

    return  0;
}