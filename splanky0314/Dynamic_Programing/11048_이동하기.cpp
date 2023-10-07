#include <iostream>

using namespace std;
using ll = long long;

int dp[1001][1001]={0,};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, tmp;
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> tmp;
			dp[i][j] = (dp[i-1][j]>dp[i][j-1] ? dp[i-1][j]:dp[i][j-1])+tmp;
		}
	}
	cout << dp[n][m];
}