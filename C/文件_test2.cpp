#include <stdio.h>

int main()
{
	char c;
	char buff[100];
	FILE* fp;
	fp=fopen("xinxi.txt","wb+");
	if(fp==NULL)
		return -1;
	fprintf(fp,"ѧ��");
	fputc('\n',fp);      //���з�λ����ĩ
	fputs("����\n",fp);
	fclose(fp);

	fp=fopen("xinxi.txt","rb+");
	if(fp==NULL)
		return -1;
	fscanf(fp,"%s",buff);     //���������з�
	printf("%s",buff);
	c=fgetc(fp);
	printf("%c",c);
	fgets(buff,100,fp);   //�������з�
	printf("%s",buff);
	c=fgetc(fp);
	
	fclose(fp);
	return 0;
}