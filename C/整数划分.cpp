#include <stdio.h>

int Divinteger(int n,int m);

int main()
{
	int n;
	printf("�������軮�ֵ�����n��n=");
	scanf("%d",&n);
	if(n<1)
		printf("�����������\n");
	else
		printf("������������ĿΪ%d\n",Divinteger(n,n));
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