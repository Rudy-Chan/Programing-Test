#include <stdio.h>
#include <malloc.h>

int max_sum3(int a[],int n);
int max_sub_sum(int a[],int left,int right);

int max_sum3(int a[],int n)
{
	return (max_sub_sum(a,1,n));
}

int max_sub_sum(int a[],int left,int right)
{
	int center,i,j,left_sum,right_sum,s1,s2,lefts,rights;
	if(left==right)
	{
		if(a[left]>0)
			return a[left];
		else
			return 0;
	}
	else
	{
		center=(left+right)/2;
		left_sum=max_sub_sum(a,left,center);
		right_sum=max_sub_sum(a,center+1,right);
		s1=lefts=0;
		for(i=center;i>=left;i--)
		{
			lefts+=a[i];
			if(lefts>s1)
				s1=lefts;
		}
		s2=rights=0;
		for(j=center+1;j<=right;j++)
		{
			rights+=a[j];
			if(rights>s2)
				s2=rights;
		}
		if((s1+s2<left_sum)&&(right_sum<left_sum))
			return(left_sum);
		if(s1+s2<right_sum)
			return(right_sum);
		return s1+s2;
	}
}
int main()
{
	int n,*a,sum;
	printf("请输入数列中整数个数：\n");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("请输入%d个整数:\n",n);
	for(int m=0;m<n;m++)
		scanf("%d",&a[m]);
	sum=max_sum3(a,n);
	printf("该整数列最大子段和为%d\n",sum);
	free(a);
	return 0;
}