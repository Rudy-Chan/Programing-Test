#include <stdio.h>

int main()
{
	int n,i,s1,s2,data;
	printf("���������˸���Ӧȡ�����ݸ���n��\nn=");
	scanf("%d",&n);
	s1=s2=0;
	printf("������%d�����ݣ�\n",2*n);
	for(i=1;i<=2*n;i++)
	{
		scanf("%d",&data);
		if(i%2==0)
			s2+=data;
		else
			s1+=data;
	}
	if(s1>s2)
		printf("First take left!\n");
	else
		printf("First take right!\n");
	return 0;
}