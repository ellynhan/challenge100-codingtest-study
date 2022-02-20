#include<stdio.h>

int main() {
	int N,cnt2=0,cnt5=0;
	scanf("%d",&N);
	for(int i=1;i<=N;i++) {
		int n=i;
		while(n%2==0) {
			cnt2++;
			n/=2;
		}
		while(n%5==0) {
			cnt5++;
			n/=5;
		}
	}
	printf("%d",cnt2>cnt5?cnt5:cnt2);
}
