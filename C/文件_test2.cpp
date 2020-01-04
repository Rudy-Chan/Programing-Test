#include <stdio.h>

int main()
{
	char c;
	char buff[100];
	FILE* fp;
	fp=fopen("xinxi.txt","wb+");
	if(fp==NULL)
		return -1;
	fprintf(fp,"学生");
	fputc('\n',fp);      //换行符位于行末
	fputs("张三\n",fp);
	fclose(fp);

	fp=fopen("xinxi.txt","rb+");
	if(fp==NULL)
		return -1;
	fscanf(fp,"%s",buff);     //不包括换行符
	printf("%s",buff);
	c=fgetc(fp);
	printf("%c",c);
	fgets(buff,100,fp);   //包括换行符
	printf("%s",buff);
	c=fgetc(fp);
	
	fclose(fp);
	return 0;
}