#include <iostream>

using namespace std;

int dp[301];
int score[301];

int main() {
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> score[i];
		dp[i] = 0;
	}
	
	dp[1] = score[1];
	dp[2] = score[1] + score[2];
	dp[3] = max(score[3] + score[1], score[3] + score[2]);
	
	for (int i = 4; i <= N; i++) {
		dp[i] = max(score[i]+score[i-1]+dp[i-3], score[i]+dp[i-2]);
	}
	
	cout << dp[N] << endl;
	
	return 0;
}
