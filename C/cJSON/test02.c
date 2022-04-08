/*

//构建下面的json对象
{
    "person":[{
        "name":"luffy",
        "age":19
    }],
  	"work":[{
      "type":"coding",
      "nums":9900
    }]
}
*/

#include <stdio.h>
#include "cJSON.h"
#include <stdlib.h>

int main(void)
{
    cJSON *root,*body1,*body2,*list1,*list2;

    root = cJSON_CreateObject();
    cJSON_AddItemToObject(root,"person",body1 = cJSON_CreateArray());
    cJSON_AddItemToObject(root,"work",body2 = cJSON_CreateArray());

    cJSON_AddItemToArray(body1,list1 = cJSON_CreateObject());
    cJSON_AddItemToObject(list1,"name",cJSON_CreateString("luffy"));
    cJSON_AddItemToObject(list1,"age",cJSON_CreateNumber(19));

    cJSON_AddItemToArray(body2,list2 = cJSON_CreateObject());
    cJSON_AddItemToObject(list2,"type",cJSON_CreateString("coding"));
    cJSON_AddItemToObject(list2,"nums",cJSON_CreateNumber(9900));

    char *s = cJSON_Print(root);
    if(s)
    {
        printf("%s\n",s);
        free(s);
    }
    cJSON_Delete(root);
    
    return 0;
}



