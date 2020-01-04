#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EPS 10e-6

int Gauss(int n,double **arr,double *brr)
{
	int i,j,k,col;
	double max;
	//列选主元
	for(i=0;i<n-1;i++)
	{
		for(j=i+1,col=i+1,max=fabs(arr[i][i]);j<n;j++)
		{
			if(fabs(max)<=EPS)
				return -1;
			if(fabs(arr[j][i])>max)
			{
				max=fabs(arr[j][i]);
				col=j;
			}
		}
		//交换两行
		if(arr[i][i]<max)
		{
			double *t,b;
			t=arr[i];
			arr[i]=arr[col];
			arr[col]=t;
			b=brr[i];
			brr[i]=brr[col];
			brr[col]=b;
		}
		//高斯消元
		for(j=i+1;j<n;j++)
		{
			double a;
			a=-arr[j][i]/arr[i][i];
			brr[j]+=brr[i]*a;
			for(k=i;k<n;k++)
				arr[j][k]+=arr[i][k]*a;
		}
	}
	//回代
	arr[n-1][n]=brr[n-1]/arr[n-1][n-1];
	for(i=n-2;i>=0;i--)
	{
		arr[i][n]=brr[i];
		for(j=i+1;j<n;j++)
			arr[i][n]-=arr[i][j]*arr[j][n];
		arr[i][n]/=arr[i][i];
	}
	return 0;
}

int main()
{
	int n,i,j;
	double **arr,*brr;
	int tag;
	printf("请输入方程组维数：\n");
	scanf("%d",&n);

	//动态创建二维数组arr
	arr=(double **)malloc(sizeof(double *)*n);
	if(arr==NULL)
		return (-1);
	for(i=0;i<n;i++)
	{
		arr[i]=(double *)malloc(sizeof(double)*(n+1));
		if(arr[i]==NULL)
			return (-1);
		for(j=0;j<n+1;j++)
			arr[i][j]=0;  //初始化
	}
	printf("请输入A矩阵的值（%d行，%d列）：\n",n,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf",&arr[i][j]);
		}
	}

	//动态创建一维数组b
	brr=(double *)malloc(sizeof(double)*n);
	printf("请输入B矩阵的值（%d行，1列）：\n",n);
	for(i=0;i<n;i++)
		scanf("%lf",&brr[i]);
	tag=Gauss(3,arr,brr);
	if(tag==0)
	{
		printf("该线性方程的解为（%d行，1列）：\n",n);
		for(i=0;i<n;i++)
			printf("x%d =%lf\n",i+1,arr[i][n]);
	}
	else if(tag==-1)
		printf("该矩阵存在小主元，方程组无近似解!\n");
	else
		perror("Failure");

	free(brr);
	for(i=0;i<n;i++)
		free(arr[i]);
	free(arr);

	return 0;
}




/*
1    2    3    1
5    4   10    0
3  -0.1   1    2

1.0  2.0  -1.4
*/


