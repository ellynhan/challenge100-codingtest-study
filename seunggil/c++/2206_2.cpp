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
	bool isWall = false;

	bool visitable = true; // 벽을 부수지 않은 사람이 방문 가능
	bool visitableWithbreaker = true; // 벽을 부순 사람이 방문 가능
};

vector<vector<location>> map;

bool validRange(int x, int y) {
	if (x < 0 || x >= n)
		return false;
	if (y < 0 || y >= m)
		return false;
	return true;
}


int main(void) {
	cin >> n >> m;
	map = vector<vector<location>>(n, vector<location>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char in;
			cin >> in;
			if (in == '1')
				map[i][j].isWall = true;
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




		if (breakable) {
			if (map[x][y].isWall) {
				if (map[x][y].visitableWithbreaker) {
					breakable = false;
					map[x][y].visitableWithbreaker = false;
				}
				else
					continue;
			}
			else {
				if (map[x][y].visitable)
					map[x][y].visitable = false;
				else
					continue;
			}

		}
		else {
			if (map[x][y].isWall || !map[x][y].visitableWithbreaker)
				continue;
			else
				map[x][y].visitableWithbreaker = false;
		}

		//cout << breakable << " ( " << x << ',' << y << " )" << endl;
		if (x == n - 1 && y == m - 1) {
			answer = length;
			break;
		}


		for (int i = 0; i < 4; i++) {
			if (validRange(x + dx[i], y + dy[i]))
				bfs.push(pos(length + 1, x + dx[i], y + dy[i], breakable));
		}

	}

	cout << answer;
	return 0;
}