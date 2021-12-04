#include <iostream>
#include <vector>

using namespace std;

const int dx[4] = {1,-1, 0, 0};
const int dy[4] = {0, 0, 1,-1};

int n, m;
vector<vector<int>> inputData;
vector<vector<bool>> visitable;

bool enable(int x, int y) {
	if (x < 0 || x >= n)
		return false;
	if (y < 0 || y >= m)
		return false;
	
	return visitable[x][y];
}
int dfs(int x, int y, int depth, int score) {
	score += inputData[x][y];

	if (depth == 3)
		return score;
	
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (enable(nextX, nextY)) {
			visitable[nextX][nextY] = false;
			ans = max(ans, dfs(nextX, nextY, depth + 1, score));
			visitable[nextX][nextY] = true;
		}
	}
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	inputData = vector<vector<int>>(n, vector<int>(m));
	visitable = vector<vector<bool>>(n, vector<bool>(m, true));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> inputData[i][j];

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			visitable[i][j] = false;
			ans = max(ans, dfs(i, j, 0, 0));
			visitable[i][j] = true;

			// ㅗ 모양 블록

			if (i > 0 && i < n - 1) {
				if (j < m - 1)
					ans = max(ans, inputData[i][j] + inputData[i - 1][j] + inputData[i + 1][j] + inputData[i][j + 1]);
				if (0 < j)
					ans = max(ans, inputData[i][j] + inputData[i - 1][j] + inputData[i + 1][j] + inputData[i][j - 1]);
			}
			if (j > 0 && j < m - 1) {
				if (i > 0)
					ans = max(ans, inputData[i][j] + inputData[i - 1][j] + inputData[i][j - 1] + inputData[i][j + 1]);
				if (i < n - 1)
					ans = max(ans, inputData[i][j] + inputData[i + 1][j] + inputData[i][j - 1] + inputData[i][j + 1]);
			}
		}
	
	cout << ans;

	return 0;
}