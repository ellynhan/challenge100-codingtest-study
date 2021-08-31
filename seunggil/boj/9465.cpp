#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int test_case;

	cin >> test_case;

	while (test_case--) {
		int n;
		cin >> n;
		vector<vector<int>> inputData(2, vector<int>(n));
		for (int i = 0; i < n; i++)
			cin >> inputData[0][i];
		for (int i = 0; i < n; i++)
			cin >> inputData[1][i];

		vector<vector<int>> dp(2, vector<int>(n));
		dp[0][0] = inputData[0][0];
		dp[1][0] = inputData[1][0];

		if (n > 1) {
			dp[0][1] = dp[1][0] + inputData[0][1];
			dp[1][1] = dp[0][0] + inputData[1][1];
			
			for (int i = 2; i < n; i++) {
				dp[0][i] = max(max(dp[1][i - 1] , dp[0][i - 2]), dp[1][i - 2]) + inputData[0][i];
				dp[1][i] = max(max(dp[0][i - 1] , dp[0][i - 2]), dp[1][i - 2]) + inputData[1][i];
			}
		}
		
		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}

	return 0;
}