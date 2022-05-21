#include <iostream>
#include <vector>

#define NOTDEF 32110000
#define INF 16000001

using namespace std;

vector<vector<int>> inputData;
vector<vector<int>> dp;
int n;

		// 현재 노드, 몇개 선택, 방문 정보
int dfs(int node, int count, int visited) {
	if (count >= n) {
		return dp[visited][node] = inputData[node][0];
		//return 0;
	}

	vector<int> result;
	for (size_t i = 0; i < n; i++){
		if ((visited & (1 << i)) == 0 && inputData[node][i] != INF) {
			int n;
			if (dp[visited | (1 << i)][i] == NOTDEF) {
				n = dfs(i, count + 1, visited | (1 << i));
			}
			else {
				n = dp[visited | (1 << i)][i];
			}
			if (n != INF)
				result.push_back(n + inputData[node][i]);
		}
	}

	for (int i : result) {
		if (dp[visited][node] > i)
			dp[visited][node] = i;
	}

	if (dp[visited][node] == NOTDEF)
		dp[visited][node] = INF;
	return dp[visited][node];

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	
	inputData = vector<vector<int>>(n, vector<int>(n));
	dp = vector<vector<int>>((1<<n), vector<int>(n, NOTDEF));

	for (size_t i = 0; i < n; i++){
		for (size_t j = 0; j < n; j++){
			cin >> inputData[i][j];
			if (inputData[i][j] == 0) {
				inputData[i][j] = INF; 
			}
			if (i == j)
				inputData[i][j] = 0;
		}
	}

	dfs(0, 1, 1);
	cout << dp[1][0];
	return 0;
}