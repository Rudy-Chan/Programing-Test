#include <stdio.h>
#include <string.h>


#define MINCHAR 'A'
#define CHARSUM 26

 

char table[CHARSUM][CHARSUM];

 

int Init();

int Encode(char* key, char* source, char* dest);

int Dncode(char* key, char* source, char* dest);

 

int main()

{

    if(Init()==0)

    {

        printf("初始化错误！\n");

        return 1;

    }

 

    char key[256];

    char str1[256];

    char str2[256];

    int operation;

 

    while(1)

    {

        do

        {

             printf("请选择一个操作：1. 加密；2. 解密；-1. 退出\n");

             scanf("%d",&operation);

        }while(operation != -1&& operation != 1&& operation != 2);

 

        if(operation == -1)

             return 0;

        else if(operation == 1)//加密

        {

             printf( "请输入密钥：");

             scanf("%s",key);

             printf( "请输入待加密字符串：");

             scanf("%s",str1);

 

             Encode(key, str1, str2);

              printf("加密后的字符串：%s\n", str2);

        }

        else if(operation == 2)//解密

        {

             printf("请输入密钥：");

             scanf("%s",key);

             printf("请输入待解密字符串：");

             scanf("%s", str1);

 

             Dncode(key, str1, str2);

             printf("解密后的字符串：%s\n", str2);

        }

 

        printf("\n");

    }

    return 0;

}

 

// 初始化维吉尼亚方阵

int Init()

{

    int i, j;

 

    for(i = 0; i< CHARSUM; i++)

    {

        for(j = 0; j< CHARSUM; j++)

        {

             table[i][j] = MINCHAR + (i + j) % CHARSUM;

        }

    }

 

    return 1;

}

// 加密

// key：密钥

// source：待加密的字符串

// dest：经过加密后的字符串

int Encode(char* key, char* source, char* dest)

{

    char* tempSource = source;

    char* tempKey = key;

    char* tempDest = dest;

 

    do

    {

        *tempDest = table[(*tempKey) - MINCHAR][(*tempSource) - MINCHAR];

        tempDest++;

 

        if(!(*(++tempKey)))

             tempKey = key;

    }while(*tempSource++);

 

    dest[strlen(source)] = 0;

 

    return 1;

}

// 解密

// key：密钥

// source：待解密的字符串

// dest：经过解密后的字符串

int Dncode(char* key, char* source, char* dest)

{

    char* tempSource = source;

    char* tempKey = key;

    char* tempDest = dest;

    char offset;

 

    do

    {

        offset = (*tempSource) - (*tempKey);

        offset = offset >= 0 ? offset : offset + CHARSUM;

        *tempDest = MINCHAR + offset;

        tempDest++;

 

        if(!(*(++tempKey)))

             tempKey = key;

    }while(*++tempSource);

 

    dest[strlen(source)] = 0;

 

    return 1;

}
