#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

#define MAXMUM 100

char alphabet[26]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
                    'o','p','q','r','s','t','u','v','w','x','y','z'
                   };

bool initString(char stra[],char strb[]) {
	scanf("%s%s",stra,strb);
	if(stra[0]=='0' && strb[0]=='0')
		return false;
	return true;
}

void initComp(char *str , int *c) {
	int i;
	for(i=0; i<26; i++) {
		c[i]=0;
	}
	for(i=0; str[i]!='\0' && i<MAXMUM; i++) {
		if(abs(str[i]-'a')<26) {
			c[str[i]-'a']++;
		}
	}
}

int getMin(int a,int b) {
	return a<=b?a:b;
}

int* compare(int ca[],int cb[]) {
	int i;
	int *count=(int *)malloc(sizeof(int)*26);
	for(i=0; i<26; i++) {
		int min;
		min=getMin(ca[i],cb[i]);
		count[i]=min;
	}
	return count;
}

void getResult(int *count) {
	for(int i=0; i<26; i++) {
		for(int j=0; j<count[i]; j++) {
			printf("%c",alphabet[i]);
		}
	}
	printf("\n");
}

int main() {
	char stra[MAXMUM],strb[MAXMUM];
	int ca[26],cb[26];
	int *count;
	bool tag;
	while(1) {
		tag=initString(stra,strb);
		if(!tag)
			break;
		initComp(stra,ca);
		initComp(strb,cb);
		count=compare(ca,cb);
		getResult(count);
	}
	getch();
	return 0;
}
