#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int>> dir{ {1, 2}, {-1, 2}, {2, 1}, {-2, 1}, 
							{1, -2}, {-1, -2}, {2, -1}, {-2, -1} };

int I{};
vector<vector<int>> map;

bool isInMap(int r, int c) {
	if (r >= 0 && c >= 0 && r < I && c < I) return true;
	else return false;
}

void bfs(int r, int c, int er, int ec) {
	int cnt = 0;
	queue<pair<int, int>> q;

	q.push({ r, c });
	map[r][c] = 0;

	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		if (r == er && c == ec) {
			break;
		}

		for (int i = 0; i < dir.size(); i++) {
			int nr = r + dir[i].first;
			int nc = c + dir[i].second;
			if (!isInMap(nr, nc)) continue;
			if (map[nr][nc] == 0) {
				q.push({ nr, nc });
				map[nr][nc] = map[r][c] + 1;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T{};
	cin >> T;
	for (int t = 0; t < T; t++) {
		int r{}, c{}, er{}, ec{};
		cin >> I >> r >> c >> er >> ec;
		map.clear();
		for (int i = 0; i < I; i++) {
			vector<int> v(I);
			map.push_back(v);
		}

		if (r != er || c != ec) {
			bfs(r, c, er, ec);
		}
		cout << map[er][ec] << "\n";
	}
	return 0;
}
