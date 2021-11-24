#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0,  0, 1, -1 };

vector<vector<int>> inputData;
class pos {
public:
	int x;
	int y;
	int day;
	pos(int x, int y, int day) : x(x), y(y), day(day) {}
};
bool expandable(pos next) {
	int x = next.x;
	int y = next.y;
	int nextDay = next.day;
	if (x < 0 || x >= inputData.size())
		return false;
	if (y < 0 || y >= inputData[0].size())
		return false;
	if (inputData[x][y] == -1)
		return false;
	if (inputData[x][y] == 0)
		return true;

	return inputData[x][y] > nextDay;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> m >> n;
	inputData = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> inputData[i][j];

	queue<pos> dfs;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (inputData[i][j] == 1)
				dfs.emplace(i, j, 1);

	while (dfs.size()) {
		pos now = dfs.front();
		dfs.pop();
		
		for (int z = 0; z < 4; z++) {
			pos nextPos(now.x + dx[z], now.y + dy[z], now.day + 1);
			if (expandable(nextPos)) {
				inputData[nextPos.x][nextPos.y] = nextPos.day;
				dfs.push(nextPos);
			}
		}
	}

	int ans = -1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (inputData[i][j] == 0) {
				cout << -1;
				return 0;
			}
			else
				ans = max(ans, inputData[i][j]);
		}
	cout << ans - 1;

	return 0;
}