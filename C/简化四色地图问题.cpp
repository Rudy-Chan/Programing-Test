#include <stdio.h>

int data[7][7],n,color[7],total;

int main()
{
	int i,j;
	for(i=1;i<=7;i++)
		for(j=1;j<=7;j++)
			scanf("%d",&data[i][j]);
		for(j=1;j<=7;j++)
			color[j]=0;
		total=0;
		Tr(1);
		printf("\n,Total=",total);
}

Tr(int s);
{
	int i;
	if(s>7)
		ouput();
	else
		for(i=1;i<=4;i++)
		{
			color[s]=i;
			if(colorsame(s)==0)
				Tr(s+1);
		}
}

colorsame(int s)
{
	int i,flag;
	flag=0;
	for(i=1;i<=s-1;i++)
		if(data[i][s]==1&&color[i]==color[s])
			flag=1;
		return(flag);
}
ouput()
{
	int i;
	printf("\nserial number:%d",total);
	for(i=1;i<=n;i++)
	{
		printf("%d\n",color[i]);
		color=0;
	}
	total++;
}