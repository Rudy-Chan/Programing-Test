#include <stdio.h>
#include <stdlib.h>

//定义插值点结构
typedef struct Point
{
    double x;
    double y;
}Point;


double Ercheng(Point *p, int n, double x)
{
	int i;
	double l1=0,l2=0,l3=0,l4=0;
	double a=0,b=0,y=0;
	for(i=0;i<n;i++)
    {
	   l1+=p[i].x;
	   l2+=p[i].y;
	   l3+=p[i].x*p[i].y;
	   l4+=p[i].x*p[i].x;
    }
	a=(n*l3-l1*l2)/(n*l4-l1*l1);
	b=(l4*l2-l1*l3)/(n*l4-l1*l1);
	y=a*x+b;
	printf("一次拟合函数:y=%.3lfx+%.3lf\n",a,b);
	return y;
}

int main()
{
    int i,n;
    Point *points;    //插值点集合 
    double x;    
	double y;//f（x）是要计算的插值点，tmp是拉格朗日基函数，larange是根据拉格朗日函数得出f(x)的值
    printf("请输入插值点个数:");
    scanf("%d",&n);
    points=(Point *)calloc(n,sizeof(Point));

	if(points==NULL)
		return (-1);
   //输入插值点的x值和y值
	printf("请输入%d个插值点的x值和y值：\n",n);
	for(i=0;i<n;i++)
		scanf("%lf%lf",&points[i].x,&points[i].y);
	
		//输入计算多项式的x值
		printf("\n请输入待计算的一次拟合的x值:");
		scanf("%lf",&x);
    //计算函数x值的对应f(x)
		y=Ercheng(points,n,x);
    //计算完毕，代入所求函数x的值求解
		printf("y(%.3lf)=%.6lf\n",x,y);

	free(points);
    return 0;
}