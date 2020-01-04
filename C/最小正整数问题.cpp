#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

void Delete(char n[],int b,int k)
{
	int i;
	for(i=b;i<=(int)strlen(n)-k;i++)
		n[i]=n[i+k];
}

int main()
{
	char n[100];
	int s,i,j,j1,c,data[100],len;
	printf("请输入一个高精度正整数：\n");
	scanf("%s",n);
	printf("请输入删除数字的个数：\n");
	scanf("%d",&s);
	len=strlen(n);
	if(s>len)
	{
		printf("data error\n");
		return 0;
	}
	j1=0;
	for(i=1;i<=s;i++)
	{
		for(j=1;j<strlen(n);j++)
			if(n[j]>n[j+1])
			{
				Delete(n,j,1);
				if(j>j1)
					data[i]=j+i;
				else
					data[i]=data[i-1]-1;
				j1=j;
				break;
			}
			if(j>strlen(n))
				break;
	}

	for(i=i;i<=s;i++)
	{
		j=len-i+1;
		Delete(n,j,1);
		data[i]=j;
	}
	while((n[1]='0') && (strlen(n)>1))
		Delete(n,1,1);
//	for(i=0;i<(int)strlen(n);i++)
       printf("重组的整数为：%s\n", n);
//	printf("\n");
	for(i=1;i<=s;i++)
		printf("%3d",data[i]);
	return 0;
}

