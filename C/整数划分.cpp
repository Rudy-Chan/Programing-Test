#include <stdio.h>

int Divinteger(int n,int m);

int main()
{
	int n;
	printf("请输入需划分的整数n：n=");
	scanf("%d",&n);
	if(n<1)
		printf("输入参数错误\n");
	else
		printf("该整数划分数目为%d\n",Divinteger(n,n));
	return 0;
}

int Divinteger(int n,int m)
{
	if(n==1||m==1)
		return 1;
	else if (n<m)
		return Divinteger(n,n);
	else if (n==m)
		return 1+Divinteger(n,n-1);
	else
		return Divinteger(n,m-1)+Divinteger(n-m,m);
}