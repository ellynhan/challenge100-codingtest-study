#include <cstdio>
#include <vector>

using namespace std;

// 일반적인 풀이
// dp[n] = dp[i-2] + arr[i]                // n-2번째 계단
// dp[n] = dp[i-3] + arr[i-1] + arr[i]     // n-1번째 계단이랑 n-3번째 계단,

// 내 풀이
// dpo는 바로 다음 계단 밟을 수 있는거
// dpx는 바로 다음 계단을 밟을 수 없는거
// dpo[i] = max(dpo[i - 2], dpx[i - 2]) + inputData[i];
// dpx[i] = dpo[i - 1] + inputData[i]; 직전 계단 밟고, 이번 계단 밟기,

int main(void) {
	int n;
	scanf("%d", &n);
	vector<int> inputData(n+1);

	for (int i = 1; i < n+1; i++)
		scanf("%d", &inputData[i]);

	vector<int>dpo(n + 1);
	vector<int>dpx(n + 1);

	dpo[1] = inputData[1];
	dpx[1] = inputData[1];

	for (int i = 2; i < n + 1; i++) {
		dpo[i] = max(dpo[i - 2], dpx[i - 2]) + inputData[i];
		dpx[i] = dpo[i - 1] + inputData[i];
	}

	printf("%d", max(dpo[n], dpx[n]));

	return 0;
}