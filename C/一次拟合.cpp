#include <stdio.h>
#include <stdlib.h>

//�����ֵ��ṹ
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
	printf("һ����Ϻ���:y=%.3lfx+%.3lf\n",a,b);
	return y;
}

int main()
{
    int i,n;
    Point *points;    //��ֵ�㼯�� 
    double x;    
	double y;//f��x����Ҫ����Ĳ�ֵ�㣬tmp���������ջ�������larange�Ǹ����������պ����ó�f(x)��ֵ
    printf("�������ֵ�����:");
    scanf("%d",&n);
    points=(Point *)calloc(n,sizeof(Point));

	if(points==NULL)
		return (-1);
   //�����ֵ���xֵ��yֵ
	printf("������%d����ֵ���xֵ��yֵ��\n",n);
	for(i=0;i<n;i++)
		scanf("%lf%lf",&points[i].x,&points[i].y);
	
		//����������ʽ��xֵ
		printf("\n������������һ����ϵ�xֵ:");
		scanf("%lf",&x);
    //���㺯��xֵ�Ķ�Ӧf(x)
		y=Ercheng(points,n,x);
    //������ϣ�����������x��ֵ���
		printf("y(%.3lf)=%.6lf\n",x,y);

	free(points);
    return 0;
}