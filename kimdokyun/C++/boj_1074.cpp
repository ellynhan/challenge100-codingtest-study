#include<stdio.h>
#include<math.h>

int choose(int N, int r, int c) {
	if(N==0) return 0;
	else {
		int cutLine = pow(2,N-1);
		if(r<cutLine && c<cutLine) {
			return choose(N-1,r,c);
		}
		else if(r<cutLine && c>=cutLine) {
			return pow(cutLine,2) + choose(N-1,r,c-cutLine);
		}
		else if(r>=cutLine && c<cutLine) {
			return 2*pow(cutLine,2) + choose(N-1,r-cutLine,c);
		}
		else {
			return 3*pow(cutLine,2) + choose(N-1,r-cutLine,c-cutLine);
		}
	}
}

int main() {
	int N,r,c;
	scanf("%d %d %d",&N,&r,&c);
	printf("%d",choose(N,r,c));
}
