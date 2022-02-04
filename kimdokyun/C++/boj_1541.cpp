#include<stdio.h>

int main() {
	 char input[100];
	 scanf("%s",input);
	 int sum = 0,num=0;
	 int minus = 1;
	 for(int i=0;input[i]!='\0';i++) {
	 	if(input[i]=='+' || input[i]=='-') {
	 		sum+=num*minus;
	 		num=0;
	 		if(input[i]=='-') minus=-1;
		 }
		 else {
		 	num*=10;
		 	num+=input[i]-'0';
		 }
	 }
	 sum+=num*minus;
	 printf("%d",sum);
}
