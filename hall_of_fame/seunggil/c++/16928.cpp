#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int ladder, snake;
	cin >> ladder >> snake;

	unordered_map<int, int> move;
	for (int i = 0; i < ladder + snake; i++) {
		int from, to;
		cin >> from >> to;
		move[from] = to;
	}

	vector<int> dp(101, 100000);
	dp[1] = 0;

	queue<int> bfs;

	bfs.push(2);
	while (bfs.size()) {
		int i = bfs.front();
		bfs.pop();

		if (i > 100)
			continue;

		int n = dp[i - 1];
		for (int j = 2; j < 7; j++)
			if(i - j > 0)
				n = min(n, dp[i - j]);

		if (move[i]) {
			if (dp[move[i]] > n + 1) {
				dp[move[i]] = min(dp[move[i]], n + 1);
				bfs.push(move[i]);
			}
		}
		else {
			dp[i] = min(dp[i], n + 1);
		}
		bfs.push(i + 1);
		
	}

	cout << dp[100];

	return 0;
}