// {\"list\":[{\"name\":\"luffy\",\"age\":19},{\"name\":\"sabo\",\"age\":21}]}

#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main()
{
    const char *s = "{\"list\":[{\"name\":\"luffy\",\"age\":19},{\"name\":\"sabo\",\"age\":21}]}";
    cJSON *root = cJSON_Parse(s);
    if(!root)
    {
        cJSON_Delete(root);
        return -1;
    }

    cJSON *item1 = cJSON_GetObjectItem(root,"list");
    if(item1->type == cJSON_Array)
    {
        int count = cJSON_GetArraySize(item1);
        for(int i = 0;i<count;++i)
        {
            cJSON *list = cJSON_GetArrayItem(item1,i);
            if(list->type == cJSON_Object)
            {
                cJSON *obj = cJSON_GetObjectItem(list,"name");
                if(obj->type == cJSON_String)
                {
                    printf("name:%s\n",obj->valuestring);
                }
                obj = cJSON_GetObjectItem(list,"age");
                if(obj->type == cJSON_Number)
                {
                    printf("age:%d\n",obj->valueint);
                }

            }
        }
        
    }

    if(root)
        cJSON_Delete(root);


    return 0;
}