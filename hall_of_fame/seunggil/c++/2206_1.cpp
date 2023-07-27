#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;
int n, m;
int answer = -1;

const int dx[4] = { 0, 0, 1,-1 };
const int dy[4] = { 1,-1, 0, 0 };
class pos {
public:
	int length = 0;
	int x;
	int y;
	bool breakWall = true;

	pos(int length, int x, int y, bool breakWall) : length(length), x(x), y(y), breakWall(breakWall) {}

};
class location {
public:
	int minLength = 1000001;
	int minLengthWithBreak = 1000001;
};

vector<vector<location>> map;

bool validRange(int x, int y) {
	if (x < 0 || x >= n)
		return false;
	if (y < 0 || y >= m)
		return false;
	return true;
}

bool isBreakable(int x, int y, int length) {
	if (validRange(x + 1, y) && map[x + 1][y].minLengthWithBreak >= length)
		return true;
	if (validRange(x - 1, y) && map[x - 1][y].minLengthWithBreak >= length)
		return true;
	if (validRange(x, y + 1) && map[x][y + 1].minLengthWithBreak >= length)
		return true;
	if (validRange(x, y - 1) && map[x][y - 1].minLengthWithBreak >= length)
		return true;
	return false;
}

int main(void) {
	cin >> n >> m;
	map = vector<vector<location>>(n, vector<location>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char in;
			cin >> in;
			if (in == '1')
				map[i][j].minLength = 0;
		}
	}

	queue<pos> bfs;
	bfs.push(pos(1, 0, 0, true));

	while (bfs.size()) {
		pos nowPos = bfs.front();
		int x = bfs.front().x;
		int y = bfs.front().y;
		int length = bfs.front().length;
		bool breakable = bfs.front().breakWall;
		bfs.pop();

		if (map[x][y].minLength == 0) {
			if (breakable && length < map[x][y].minLengthWithBreak)
				breakable = false;
			else
				continue;
		}

		if (breakable) {
			if (nowPos.length < map[x][y].minLength)
				map[x][y].minLength = length;
			else
				continue;
		}
		else {
			if (nowPos.length < map[x][y].minLengthWithBreak)
				map[x][y].minLengthWithBreak = length;
			else
				continue;
		}


		if (x == n - 1 && y == m - 1) {
			answer = length;
			break;
		}


		for (int i = 0; i < 4; i++) {
			if (validRange(x + dx[i], y + dy[i]) && map[x + dx[i]][y + dy[i]].minLength != 0 && (length + 1) < map[x + dx[i]][y + dy[i]].minLength)
				bfs.push(pos(length + 1, x + dx[i], y + dy[i], breakable));
			if (breakable && validRange(x + dx[i], y + dy[i]) && map[x + dx[i]][y + dy[i]].minLength == 0 && isBreakable(x + dx[i], y + dy[i], length + 1) && (length + 1) < map[x + dx[i]][y + dy[i]].minLengthWithBreak)
				bfs.push(pos(length + 1, x + dx[i], y + dy[i], breakable));
		}

	}

	cout << answer;
	return 0;
}