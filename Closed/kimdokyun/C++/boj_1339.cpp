#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

bool compare(int a, int b) {return b < a;}

int main() {
	int alpaDic[26] = {},N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) {
		char word[9];
		int digit = 1;
		scanf("%s",word);
		for(int j=strlen(word)-1;j>=0;j--) {
			alpaDic[word[j]-'A'] += digit;
			digit *= 10;
		}
	}
	sort(alpaDic,alpaDic+26, compare);
	int result=0,value=9;
	for(int i=0;i<26 && value > 0 && alpaDic[i] > 0;i++) {
		result += alpaDic[i] * value--;
	}
	printf("%d",result);
}
