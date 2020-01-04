#include <stdio.h>

int main()
{
	int a,d;
	long e,f;
	printf("ABCAB*A=DDDDDD形式的数字谜有：\n");
	for (a=3;a<=9;a++)
	{
		for (d=1;d<=9;d++)
		{
			e=d*100000+d*10000+d*1000+d*100+d*10+d;
			if(e%a==0)
			{
				f=e/a;
				if((f/10000==a)&&((f%100)/10==a))
					if(f/1000%10==f%10)
						printf("%d*%d=%d\n",f,a,e);
			}
		}
	}
	return 0;
}