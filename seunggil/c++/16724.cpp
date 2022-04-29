#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

const int dir[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
const unordered_map<char, int> delta{
	{'U' , 0},
	{'L' , 1},
	{'R' , 2},
	{'D' , 3},
};

class pos {
public:
	int x;
	int y;

	pos(int x, int y): x(x), y(y) {}
	
};

class map {
public:
	int dir = 0;
	bool visit = false;
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	string s;
	vector<vector<map>> inputData(n,vector<map>(m));
	
	for (size_t i = 0; i < n; i++){
		cin >> s;
		for (size_t j = 0; j < m; j++) {
			inputData[i][j].dir = delta.at(s[j]);
		}
	}
	int answer = 0;
	queue<pos> bfs;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			if (!inputData[i][j].visit) {
				answer++;
				inputData[i][j].visit = true;
				bfs.emplace(i, j);
			}
			while (bfs.size()) {
				pos now = bfs.front();
				bfs.pop();

				int x = now.x;
				int y = now.y;
				int d = inputData[x][y].dir;

				int nextX = x + dir[d][0];
				int nextY = y + dir[d][1];
				// 정방향
				if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && !inputData[nextX][nextY].visit) {
					inputData[nextX][nextY].visit = true;
					bfs.emplace(nextX, nextY);
				}

				// 역방향
				for (size_t i = 0; i < 4; i++){
					nextX = x + dir[i][0];
					nextY = y + dir[i][1];
					if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && !inputData[nextX][nextY].visit) {
						if (3 - inputData[nextX][nextY].dir == i) {
							inputData[nextX][nextY].visit = true;
							bfs.emplace(nextX, nextY);
						}
					}
				}
			}
		}
	}

	cout << answer;

	return 0;
}