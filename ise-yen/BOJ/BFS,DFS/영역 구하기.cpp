#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

vector<vector<bool>> isVisit;
vector<vector<int>> map;

bool isInMap(int r, int c, int R, int C) {
	if (r >= 0 && r < R && c >= 0 && c < C) return true;
	else return false;
}

int bfs(int r, int c, int R, int C) {
	int cnt{};
	
	queue<pair<int, int>> q;

	q.push({ r, c });
	isVisit[r][c] = true;
	cnt++;

	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];

			if (!isInMap(nr, nc, R, C)) continue;
			if (isVisit[nr][nc] || map[nr][nc] != 0) continue;

			q.push({ nr, nc });
			isVisit[nr][nc] = true;
			cnt++;
		}
	}

	return cnt;
}

int main() {
	int M{}, N{}, K{};
	cin >> M >> N >> K;
	
	for (int m = 0; m < M; m++) {
		vector<int> v(N);
		vector<bool> isV(N);
		map.push_back(v);
		isVisit.push_back(isV);
	}

	// 맵 그리기
	for (int k = 0; k < K; k++) {
		int sx, sy, ex, ey; // 시작점은 그대로, 종료점은 -1씩
		cin >> sx >> sy; // sy행 sx열
		cin >> ex >> ey; // ey-1행 ex-1열

		for (int i = sy; i < ey; i++) {
			for (int j = sx; j < ex; j++) {
				map[i][j] = 1;
			}
		}
	}

	vector<int> ans;
	int answer{};
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (isVisit[i][j] || map[i][j] != 0) continue;

			int c = bfs(i, j, M, N);
			if (c != 0) {
				answer++;
				ans.push_back(c);
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << answer << "\n";
	for (int a : ans) {
		cout << a << " ";
	}
}
