#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <windows.h>

#define PASSWORD "1234567"

int verify(char* password)
{
	int authen;
	char buffer[7];
	authen=strcmp(password,PASSWORD);
	strcpy(buffer,password);
	return authen;
}

int main()
{
	int valid_flag=0;
	char password[100];

	FILE* shell;
	shell=fopen("password.txt","rb+");
	if(shell==NULL)
		perror("can't open");


	fscanf(shell,"%s",password);
	fclose(shell);
	valid_flag=verify(password);
	if(valid_flag)
	{
		printf("incorrect password!\n");
	}
	else
	{
		printf("Congratulation!You have passed the verification!\n");
	}

	return 0;
}
	
