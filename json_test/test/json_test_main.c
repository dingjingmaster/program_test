/*************************************************************************
	> File Name: json_test_main.c
	> Author: DingJing
	> Mail: dingjing_ding@staff.easou.com
	> Created Time: 2017年06月21日 星期三 14时47分57秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include "../src/cJSON.h"

int create_json(cJSON** root);
int parse_json(char* root);

int main()
{
    cJSON*            root = NULL;
    char*             out = NULL;


    create_json(&root);

    //  打印
    out = cJSON_Print(root);
    printf("%s\n", out);

    parse_json(out);

    return 0;
}


int create_json(cJSON** root)
{
    if(NULL == root)
    {
        return -1;
    }

    const char*       hobby[] = {"篮球", "游泳"};


    *root = cJSON_CreateObject();

    //  cJSON_AddItemToObject(cJSON *object,const char *string,cJSON *item);
    cJSON_AddItemToObject(*root, "姓名", cJSON_CreateString("张3"));
    cJSON_AddItemToObject(*root, "年龄", cJSON_CreateNumber(20));

    //  extern void     cJSON_AddItemReferenceToObject(cJSON *object,const char *string,cJSON *item);
    cJSON_AddItemReferenceToObject(*root, "爱好", cJSON_CreateStringArray(hobby, 2));



    return 0;
}



int parse_json(char* root)
{
    if(NULL == root)
    {
        return -1;
    }

    cJSON*            hobby = NULL;
    cJSON*            child = NULL;

    //  cJSON_Parse(const char *value);
    cJSON*  pars = cJSON_Parse(root);

    //  两种输出方法
    //  cJSON_DetachItemFromObject(cJSON *object,const char *string);
    printf("姓名: %s\n", cJSON_Print(cJSON_DetachItemFromObject(pars, "姓名")));
    printf("年龄: %s\n", cJSON_Print(cJSON_DetachItemFromObject(pars, "年龄")));
    //printf("爱好: %s\n", cJSON_Print(cJSON_DetachItemFromObject(pars, "爱好")));
    hobby = cJSON_DetachItemFromObject(pars, "爱好");

    for(;hobby != NULL; hobby = hobby ->next)
    {
        printf("%s\n", hobby ->string);

        for(child = hobby ->child; child != NULL; child = child ->next)
        {
            printf("%s\n", child ->valuestring);
        }
    }

    return 0;
}










