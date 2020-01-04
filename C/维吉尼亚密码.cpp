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

        printf("��ʼ������\n");

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

             printf("��ѡ��һ��������1. ���ܣ�2. ���ܣ�-1. �˳�\n");

             scanf("%d",&operation);

        }while(operation != -1&& operation != 1&& operation != 2);

 

        if(operation == -1)

             return 0;

        else if(operation == 1)//����

        {

             printf( "��������Կ��");

             scanf("%s",key);

             printf( "������������ַ�����");

             scanf("%s",str1);

 

             Encode(key, str1, str2);

              printf("���ܺ���ַ�����%s\n", str2);

        }

        else if(operation == 2)//����

        {

             printf("��������Կ��");

             scanf("%s",key);

             printf("������������ַ�����");

             scanf("%s", str1);

 

             Dncode(key, str1, str2);

             printf("���ܺ���ַ�����%s\n", str2);

        }

 

        printf("\n");

    }

    return 0;

}

 

// ��ʼ��ά�����Ƿ���

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

// ����

// key����Կ

// source�������ܵ��ַ���

// dest���������ܺ���ַ���

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

// ����

// key����Կ

// source�������ܵ��ַ���

// dest���������ܺ���ַ���

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
