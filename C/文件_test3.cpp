#include <stdio.h>

int main()
{
	char c;
	char buff[100];
	FILE* fp;
	fp=fopen("xinxi.txt","wb+");
	if(fp==NULL)
		return -1;
	fprintf(fp,"编号  姓名  性别  年龄   专业  \n");
	fprintf(fp,"1111  张三   男    18   计算机 \n");
	fprintf(fp,"1112  李四   女    18    网络  \n");
	fclose(fp);

	fp=fopen("xinxi.txt","rb+");
	if(fp==NULL)
		return -1;
	fgets(buff,100,fp);   //包括换行符
	printf("%s",buff);
	fgets(buff,100,fp);
	printf("%s",buff);
	fgets(buff,100,fp);
	printf("%s",buff);	
	fclose(fp);

	return 0;
}