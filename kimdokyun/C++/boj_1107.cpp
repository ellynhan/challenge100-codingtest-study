#include<stdio.h>

int brokens[10],M;

int check(int num) {
	int i=0;
	while(num >= 0) {
		if(num == 0 && i != 0) break;
		int n = num%10;
		for(int i=0;i<M;i++) {
			if(n == brokens[i]) {
				return 0;
			}
		}
		num/=10;
		i++;
	}
	return i;
}

int main() {
	 int N;
	 
	 scanf("%d %d",&N,&M);
	 for(int i=0;i<M;i++) scanf("%d",&brokens[i]);
	 
	 int result = N > 100?N-100:100-N;
	 for(int gap=0;gap<result;gap++) {
	 	int minus_result = check(N>gap?N-gap:0);
	 	int pluse_result = check(N+gap);
	 	if(minus_result != 0) {
	 		result = minus_result+gap < result ? minus_result+gap: result;
	 	}
	 	if(pluse_result != 0) {
	 		result = pluse_result+gap < result ? pluse_result+gap: result;
	 	}
	 }
	 
	 printf("%d",result);
}
