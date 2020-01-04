#include <stdio.h>

int main()
{
	int dis,k,oil,k;
	dis=500;
	k=1;
	oil=500;
	do
	{
		printf("storepoint",k,"distance",1000-dis,"oilquantity",oil);
		k++;
		dis=dis+500/(2*k-1);
		oil=500*k;
	}
	while(dis<1000);
	oil=500*(k-1)+(1000-dis)*(2*k-1);
	printf("storepoint",k,"distance",0,"oilquantity",oil);
}
