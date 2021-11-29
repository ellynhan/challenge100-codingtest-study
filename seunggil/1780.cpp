#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> inputData;
class pos {
public:
	int x;
	int y;
	int length;

	pos(int x, int y, int length) : x(x), y(y), length(length) {}
};

bool isSame(int x, int y, int length) {
	bool result = true;
	int ans = inputData[x][y];
	for (int i = x; i < x + length; i++)
		for (int j = y; j < y + length; j++)
			if (inputData[i][j] != ans) {
				result = false;
				break;
			}

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	inputData = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> inputData[i][j];
		}
	}

	int ans[3] = { 0,0,0 };

	stack<pos> dfs;
	dfs.emplace(0, 0, n);

	while (dfs.size()) {
		pos now = dfs.top();
		dfs.pop();
		//cout << now.x << ' ' << now.y << ' '<<  now.length << '\n';
		if (isSame(now.x, now.y, now.length)) {
			ans[inputData[now.x][now.y] + 1]++;
			continue;
		}

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				dfs.emplace(now.x + (now.length/3) * i, now.y + (now.length / 3) * j, now.length / 3);

	}

	for (int i : ans)
		cout << i << '\n';
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << inputData[i][j] << ' ';
	//	}cout << '\n';
	//}

	return 0;
}