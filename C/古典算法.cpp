#include <stdio.h>
#include <assert.h>
#include <string.h>

#define N 26 //����任Ĭ��ģ��Ϊ26
#define AL_MIN 'A'  //��ĸ������ĸ
#define AL_NUM 26   //Vigenere����������

char table[AL_NUM][AL_NUM];   //Vigenere����

char *F_encode(char *c_str, int a, int b, int n);  //��������㷨
char *F_decode(char *m_str, int a, int b, int n);  //��������㷨
bool Encode(char* key, char* source, char* dest);  //Vigenere�����㷨
bool Dncode(char* key, char* source, char* dest);  //Vigenere�����㷨

//��������coprimeΪ�����n���ص�Ԫ��
void setCoprime(int coprime[], int n);

//��ȡv1,v2�����Լ��
int getGcd(int v1, int v2);

//��coprime��Ѱ��a��ģn����Ԫ_a
int get_a(int coprime[], int a, int n);

//Vigenere�����ʼ��
bool Init();

int main()
{
	if(Init()==0)
    {
        printf("��ʼ������!\n");
        return 1;
    }

	int a = 0;
	int b = 0;
	char str[128] = "";  //str�洢����
	char key[128];     //key�洢��Կ
    char str1[128];    //str1�洢������
    char str2[128];    //str2�洢������
    int op;

	while(1)
    {
        do
        {
             printf("-----     ��ѡ�����     -----\n");
			 printf("1. ����    2. ����    -1. �˳�\n");
			 printf("******************************\n������");
             scanf("%d",&op);
        }while(op != -1&& op != 1&& op != 2);
        if(op == -1)
             return 0;
        else if(op == 1)//����
        {
	        printf("������a, b��a��%d���أ���ֵ��\n",N);
			scanf("%d %d", &a, &b);     
			getchar(); //�������з��ĸ���   

			printf( "��������Կ��");
			gets(key);
			printf("��������������ģ�\n�����ģ�");
			gets(str); //�������д��ĸ�ַ���
			
			F_encode(str, a, b, N);  //����һ�μ���
			//�����Ƿ���ܳɹ�
			Encode(key, str, str1);  //vigenere���μ���
			printf("���ܺ�����ģ�\n�����ģ�%s\n", str1);
        }

		else if(op == 2)//����
        {
			printf("������a, b��a��%d���أ���ֵ��\n",N);
			scanf("%d %d", &a, &b);
			getchar(); //�������з��ĸ���

            printf("��������Կ��");
            gets(key);
            printf("��������������ģ�\n�����ģ�");
            gets(str);
            Dncode(key, str, str2);  //vigenereһ�ν���
			F_decode(str2, a, b, N);  //������ν���
			//�����Ƿ���ܳɹ�
            printf("���ܺ�����ģ�\n�����ģ�%s\n", str2);
        }
        printf("\n");
    }
    return 0;
}
 

//���ܺ���F_encode()
char *F_encode(char *c_str, int a, int b, int n)
{
	char *p_str = c_str; //�����ַ����׵�ַ
	assert (c_str);  //�ж������ַ���c_str�Ƿ�ΪNULL

	while (*c_str)
	{
		if (' '== *c_str) //�����ո������
		{
			c_str++;
			continue;
		}
		if ((*c_str < 'A') || (*c_str > 'Z')) //���ǡ�A������Z��֮��ľ��ж�
			assert(0);

		*c_str -= 'A'; //���ַ�ת��Ϊ��Ӧ����
		*c_str = (a*(*c_str) + b)%n;//���ܺ����㷨
		*c_str += 'A'; //������ת��Ϊ�ַ�
		c_str++;
	}
	return p_str;
}

//���ܺ���F_decode()
char *F_decode(char *m_str, int a, int b, int n)
{
	char *p_str = m_str;  //�����ַ����׵�ַ
	int coprime[32] = {0};  //���С��n������n���ص�Ԫ��
	int _a = 0; //���a��ģn����Ԫ
	int i = 0; //��������
	assert (m_str);  //�ж������ַ���m_str�Ƿ�ΪNULL
	for (; i < 32; i++)  //������Ԫ�ظ�Ϊ0
		coprime[i] = 0;
	setCoprime(coprime, n);//��������coprime�����n���ص�Ԫ��
	_a = get_a(coprime, a, n);//��coprime��Ѱ��a����Ԫ_a

	while (*m_str)
	{
		if (' ' == *m_str)  //�����ո������
		{
			m_str++;
			continue;
		}
		if ((*m_str < 'A') || (*m_str > 'Z')) //���ǡ�A������Z��֮��ľ��ж�
			assert(0);
		*m_str -= 'A'; //���ַ�ת��Ϊ��Ӧ����
		*m_str = (_a*(*m_str - b + n))%n;//���ܺ����㷨
		*m_str += 'A'; //������ת��Ϊ�ַ�
		m_str++;
	}
	return p_str;
}

//��������coprime�����n���ص�Ԫ��
void setCoprime(int coprime[], int n)
{
	int i = 1;
	for (; i < n; i++)
		if (1 == getGcd(n, i))//�ж��Ƿ�n,i�Ƿ���
			*(coprime++) = i; //��i����coprime��
}

//��ȡv1��v2�����Լ��getGcd()
int getGcd(int v1, int v2)
{
	int gcd = 0; //���Լ��
	int divisor = 0; //����

	do //շת�����
	{ 
		divisor = v1 % v2;
		gcd = v2;
		v1 = v2;
		v2 = divisor;
	}while(divisor);
	return gcd;}

//������coprime��Ѱ��a��ģn����Ԫ_a
int get_a(int coprime[], int a, int n)
{
	int i = 0;
	for (; coprime[i] != 0; i++)
		if (1 == (a*coprime[i])%n)
			return coprime[i];
		return 0;
}

//��ʼ��Vigenere����
bool Init()
{
    int i, j;
    for(i = 0; i< AL_NUM; i++)
    {
        for(j = 0; j< AL_NUM; j++)
        {
             table[i][j] = AL_MIN+(i+j)%AL_NUM;
        }
    }
    return true;
}

// Vigenere����
// key����Կ
// source�������ܵ��ַ���
// dest���������ܺ���ַ���

bool Encode(char* key, char* source, char* dest)
{
    char* tempSource = source;
    char* tempKey = key;
    char* tempDest = dest;

    do
    {
        *tempDest = table[(*tempKey) - AL_MIN][(*tempSource) - AL_MIN];
        tempDest++;
        if(!(*(++tempKey)))
			tempKey = key;
    }while(*tempSource++);
    dest[strlen(source)] = 0;
    return true;
}

// Vigenere����
// key����Կ
// source�������ܵ��ַ���
// dest���������ܺ���ַ���

bool Dncode(char* key, char* source, char* dest)
{
    char* tempSource = source;
    char* tempKey = key;
    char* tempDest = dest;
    char offset;

    do
    {
        offset = (*tempSource) - (*tempKey);
        offset = offset >= 0 ? offset : offset + AL_NUM;
        *tempDest = AL_MIN + offset;
        tempDest++;
        if(!(*(++tempKey)))
             tempKey = key;
    }while(*++tempSource);
    dest[strlen(source)] = 0;
    return true;
}
