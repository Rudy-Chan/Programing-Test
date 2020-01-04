#include<stdio.h>
int main()
{
	int a[100],b[100],c[100];
	int n,i,j,max,p;
	printf("请输入整数n的值:");
	scanf("%d",&n);
	printf("请输入数列:");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=1;
		c[i]=0;
	}
	for(i=n-1;i>=1;i--)
	{
		max=0;
		p=0;
		for(j=i+1;j<=n;j++)
			if(a[i]<a[j]&&b[j]>max)
			{
				max=b[j];
				p=j;
			}
			if(p!=0)
			{
				b[i]=b[p]+1;
				c[i]=p;
			}
	}
	max=0;
	p=0;
	for(i=1;i<=n;i++)
		if(b[i]>max)
		{
			max=b[i];
			p=i;
		}
        printf("maxlong=%d\n",max);
		printf("result is:");
		while(p!=0)
		{
			printf("%4d",a[p]);
			p=c[p];
		}
		return 0;6
}
