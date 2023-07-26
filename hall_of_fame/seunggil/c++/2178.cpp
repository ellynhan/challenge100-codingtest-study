#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>

using namespace std;

const int dx[4] = { 1,-1, 0,0 };
const int dy[4] = { 0, 0, 1,-1 };
class pos {
public:
	int x;
	int y;
	int length;

	pos(int x, int y, int length = 1) :x(x), y(y), length(length) {};
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> inputData(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < m; j++)
			inputData[i][j] = row[j] - '0';
	}

	queue<pos> bfs;
	bfs.emplace(0, 0);
	inputData[0][0] = 0;

	while (bfs.size()) {
		int x = bfs.front().x;
		int y = bfs.front().y;
		int length = bfs.front().length;
		bfs.pop();

		if (x == n - 1 && y == m - 1) {
			cout << length;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int newX = x + dx[i];
			int newY = y + dy[i];

			if (newX >= 0 && newX < n && newY >= 0 && newY < m && inputData[newX][newY]) {
				bfs.emplace(newX, newY, length + 1);
				inputData[newX][newY] = 0;
			}
		}
	}

	return 0;
}