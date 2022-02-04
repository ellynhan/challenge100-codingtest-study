#include<stdio.h>

int main() {
	int N, dp[1001], num;
	scanf("%d",&N);
	for(int i=0;i<N;i++) {
		scanf("%d",&num);
		dp[i] = num;
		for(int j=0; j<i;j++) {
			dp[i] = dp[i] > dp[j]+dp[i-j-1] ?dp[i] :dp[j]+dp[i-j-1];
		}
	}
	printf("%d",dp[N-1]);
}
