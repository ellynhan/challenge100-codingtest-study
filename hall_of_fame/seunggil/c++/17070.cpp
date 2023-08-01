#include <vector>
#include <iostream>
#include <stack>
using namespace std;

const int delta[4][2] = { {}, {1,1},{0,1},{1,0}};
int n;
vector<vector<int>> inputData;

class pos {
public:
	int dir; // 대각선:1, 가로:2, 세로:3, 
	int x;
	int y;

	pos(int dir, int x, int y): dir(dir), x(x), y(y){}
};

bool isValid(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n)
		return false;
	return !inputData[x][y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> n;

	inputData = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> inputData[i][j];
		}
	}

	stack<pos> dfs;
	dfs.emplace(2, 0, 1);

	int ans = 0;

	while (dfs.size()) {
		int dir = dfs.top().dir;
		int x = dfs.top().x;
		int y = dfs.top().y;

		dfs.pop();
		if (x == n - 1 && y == n - 1) {
			ans++;
			continue;
		}

		bool diag = isValid(x + delta[1][0], y + delta[1][1]);
		bool right = isValid(x + delta[2][0], y + delta[2][1]);
		bool down = isValid(x + delta[3][0], y + delta[3][1]);

		if (dir != 2 && down)
			dfs.emplace(3, x + delta[3][0], y + delta[3][1]);
		if (dir != 3 && right)
			dfs.emplace(2, x + delta[2][0], y + delta[2][1]);
		if (down && right && diag)
			dfs.emplace(1, x + delta[1][0], y + delta[1][1]);
	}

	cout << ans;

	return 0;
}

