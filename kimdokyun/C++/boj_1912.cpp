#include<stdio.h>

int main() {
	int N,num,result,dp;
	result = dp = -1001;
	scanf("%d",&N);
	for(int i=0;i<N;i++) {
		scanf("%d",&num);
		dp = num > dp+num ?num :dp+num;
		result = result > dp ?result :dp;
	}
	printf("%d",result);
}
