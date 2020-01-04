#include <stdio.h>
#include <assert.h>
#include <string.h>

#define N 26 //仿射变换默认模数为26
#define AL_MIN 'A'  //字母表首字母
#define AL_NUM 26   //Vigenere方阵行列数

char table[AL_NUM][AL_NUM];   //Vigenere方阵

char *F_encode(char *c_str, int a, int b, int n);  //仿射加密算法
char *F_decode(char *m_str, int a, int b, int n);  //仿射解密算法
bool Encode(char* key, char* source, char* dest);  //Vigenere加密算法
bool Dncode(char* key, char* source, char* dest);  //Vigenere解密算法

//设置数组coprime为存放与n互素的元素
void setCoprime(int coprime[], int n);

//获取v1,v2的最大公约数
int getGcd(int v1, int v2);

//在coprime中寻找a的模n可逆元_a
int get_a(int coprime[], int a, int n);

//Vigenere方阵初始化
bool Init();

int main()
{
	if(Init()==0)
    {
        printf("初始化错误!\n");
        return 1;
    }

	int a = 0;
	int b = 0;
	char str[128] = "";  //str存储明文
	char key[128];     //key存储密钥
    char str1[128];    //str1存储加密文
    char str2[128];    //str2存储解密文
    int op;

	while(1)
    {
        do
        {
             printf("-----     请选择操作     -----\n");
			 printf("1. 加密    2. 解密    -1. 退出\n");
			 printf("******************************\n操作：");
             scanf("%d",&op);
        }while(op != -1&& op != 1&& op != 2);
        if(op == -1)
             return 0;
        else if(op == 1)//加密
        {
	        printf("请输入a, b（a与%d互素）的值：\n",N);
			scanf("%d %d", &a, &b);     
			getchar(); //抵消换行符的干扰   

			printf( "请输入密钥：");
			gets(key);
			printf("请输入待加密明文：\n（明文）");
			gets(str); //请输入大写字母字符串
			
			F_encode(str, a, b, N);  //仿射一次加密
			//检验是否加密成功
			Encode(key, str, str1);  //vigenere二次加密
			printf("加密后的密文：\n（密文）%s\n", str1);
        }

		else if(op == 2)//解密
        {
			printf("请输入a, b（a与%d互素）的值：\n",N);
			scanf("%d %d", &a, &b);
			getchar(); //抵消换行符的干扰

            printf("请输入密钥：");
            gets(key);
            printf("请输入待解密密文：\n（密文）");
            gets(str);
            Dncode(key, str, str2);  //vigenere一次解密
			F_decode(str2, a, b, N);  //仿射二次解密
			//检验是否解密成功
            printf("解密后的明文：\n（明文）%s\n", str2);
        }
        printf("\n");
    }
    return 0;
}
 

//加密函数F_encode()
char *F_encode(char *c_str, int a, int b, int n)
{
	char *p_str = c_str; //明文字符串首地址
	assert (c_str);  //判断明文字符串c_str是否为NULL

	while (*c_str)
	{
		if (' '== *c_str) //遇到空格就跳过
		{
			c_str++;
			continue;
		}
		if ((*c_str < 'A') || (*c_str > 'Z')) //不是‘A’到‘Z’之间的就中断
			assert(0);

		*c_str -= 'A'; //将字符转化为对应数字
		*c_str = (a*(*c_str) + b)%n;//加密核心算法
		*c_str += 'A'; //将数字转化为字符
		c_str++;
	}
	return p_str;
}

//解密函数F_decode()
char *F_decode(char *m_str, int a, int b, int n)
{
	char *p_str = m_str;  //密文字符串首地址
	int coprime[32] = {0};  //存放小于n并且与n互素的元素
	int _a = 0; //存放a的模n可逆元
	int i = 0; //迭代因子
	assert (m_str);  //判断密文字符串m_str是否为NULL
	for (; i < 32; i++)  //将数组元素赋为0
		coprime[i] = 0;
	setCoprime(coprime, n);//设置数组coprime存放与n互素的元素
	_a = get_a(coprime, a, n);//在coprime中寻找a的逆元_a

	while (*m_str)
	{
		if (' ' == *m_str)  //遇到空格就跳过
		{
			m_str++;
			continue;
		}
		if ((*m_str < 'A') || (*m_str > 'Z')) //不是‘A’到‘Z’之间的就中断
			assert(0);
		*m_str -= 'A'; //将字符转化为对应数字
		*m_str = (_a*(*m_str - b + n))%n;//解密核心算法
		*m_str += 'A'; //将数字转化为字符
		m_str++;
	}
	return p_str;
}

//设置数组coprime存放与n互素的元素
void setCoprime(int coprime[], int n)
{
	int i = 1;
	for (; i < n; i++)
		if (1 == getGcd(n, i))//判断是否n,i是否互素
			*(coprime++) = i; //将i存入coprime中
}

//获取v1和v2的最大公约数getGcd()
int getGcd(int v1, int v2)
{
	int gcd = 0; //最大公约数
	int divisor = 0; //余数

	do //辗转相除法
	{ 
		divisor = v1 % v2;
		gcd = v2;
		v1 = v2;
		v2 = divisor;
	}while(divisor);
	return gcd;}

//在数组coprime中寻找a的模n可逆元_a
int get_a(int coprime[], int a, int n)
{
	int i = 0;
	for (; coprime[i] != 0; i++)
		if (1 == (a*coprime[i])%n)
			return coprime[i];
		return 0;
}

//初始化Vigenere方阵
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

// Vigenere加密
// key：密钥
// source：待加密的字符串
// dest：经过加密后的字符串

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

// Vigenere解密
// key：密钥
// source：待解密的字符串
// dest：经过解密后的字符串

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
