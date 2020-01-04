#include<stdio.h>
#include<math.h>

double answer(double (*pfunc)(double),double e,double a,double b)
{
	double m;
	if(pfunc(a)==0.0)
		return a;
	else if(pfunc(b)==0.0)
		return b;
	else if(pfunc(a)*pfunc(b)>0.0)
	{
		printf("�����䲻����");
		return -1;
	}
	else
	{
		while(1)
		{
			if (fabs(b-a)<=e)
			{
				return (a+b)/2;
			}
			else
			{
				m=(a+b)/2;
				if (pfunc(a)*pfunc(m)>0)
					a=m;
				else if (pfunc(m)*pfunc(b)>0)
					b=m;
				else
					return m;
			}
		}
	}
}

double function(double x)
{
	double a;
	a=((x*x*x)-(3*x)+1);
	return a;
}

int main()
{ 
	double a,b,e;
	double (* func)(double);
	double result;
	printf("�����������Сֵa���ϴ�ֵb������e��\n");
	scanf("%lf%lf%lf",&a,&b,&e);
	func=function;
	while(fabs(answer(func,e,a,b)-(-1))<10e-6)
	{
		printf("����������a,b:\n");
		scanf("%lf%lf",&a,&b);
	}
	result=answer(func,e,a,b);
	printf("�ú���������ֵΪx=%.6lf\n",result);

	return 0;
}
