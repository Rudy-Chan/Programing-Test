#include <stdio.h>

int main()
{
	char c;
	char buff[100];
	FILE* fp;
	fp=fopen("xinxi.txt","wb+");
	if(fp==NULL)
		return -1;
	fprintf(fp,"���  ����  �Ա�  ����   רҵ  \n");
	fprintf(fp,"1111  ����   ��    18   ����� \n");
	fprintf(fp,"1112  ����   Ů    18    ����  \n");
	fclose(fp);

	fp=fopen("xinxi.txt","rb+");
	if(fp==NULL)
		return -1;
	fgets(buff,100,fp);   //�������з�
	printf("%s",buff);
	fgets(buff,100,fp);
	printf("%s",buff);
	fgets(buff,100,fp);
	printf("%s",buff);	
	fclose(fp);

	return 0;
}