#include <stdio.h>

int s1,s2;

int calculatemin(int a[],int n);
int calculatemax(int a[],int n);
void max2(int a[],int n);
void min2(int a[],int n);

int main()
{
	int j,n,a[100],b[100],max,min;
	printf("请输入数列中整数个数：");
	scanf("%d",&n);
	printf("请输入%d个整数：\n",n);
	for(j=1;j<=n;j++)
	{
		scanf("%d",&a[j]);
		b[j]=a[j];
	}
	min=calculatemin(a,n);
	max=calculatemax(b,n);
	printf("数列极差:max-min=%d\n",max-min);
	return 0;
}

int calculatemin(int a[],int n)
{
	while(n>2){
		max2(a,n);
		a[s1]=a[s1]*a[s2]+1;
		a[s2]=a[n];
		n--;
	}
	return a[1]*a[2]+1;
}

void max2(int a[],int n)
{
	int j;
	if(a[1]>=a[2])
	{
		s1=1;
		s2=2;
	}
	else
	{
		s1=2;
		s2=1;
	}
	for(j=3;j<=n;j++)
	{
		if(a[j]>a[s1])
		{
			s2=s1;
			s1=j;
		}
		else if(a[j]>a[s2])
			s2=j;
	}
}

int calculatemax(int a[],int n)
{
	while(n>2){
		min2(a,n);
		a[s1]=a[s1]*a[s2]+1;
		a[s2]=a[n];
		n--;
	}
	return a[1]*a[2]+1;
}

void min2(int a[],int n)
{
	int j;
	if(a[1]<=a[2])
	{
		s1=1;
		s2=2;
	}
	else
	{
		s1=2;
		s2=1;
	}
	for(j=3;j<=n;j++)
	{
		if(a[j]<a[s1])
		{
			s2=s1;
			s1=j;
		}
		else if(a[j]<a[s2])
			s2=j;
	}
} 
