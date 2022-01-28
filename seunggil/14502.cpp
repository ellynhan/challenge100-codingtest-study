#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int dx[4] = {  0, 1, 0,-1 };
const int dy[4] = { -1, 0, 1, 0 };
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;
	vector<vector<int>> inputData(n, vector<int>(m));
	vector<pair<int, int>> virus;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> inputData[i][j];

			if (inputData[i][j] == 2)
				virus.emplace_back(i, j);
		}
	}


	int count = 0;
	int range = n * m;
	int ans = 0;
	for (int i = 0; i < range; i++) {
		for (int j = i + 1; j < range; j++) {
			for (int k = j + 1; k < range; k++) {
				int wall1X = i / m, wall1Y = i % m;
				int wall2X = j / m, wall2Y = j % m;
				int wall3X = k / m, wall3Y = k % m;
				
				if (inputData[wall1X][wall1Y] == 0 && inputData[wall2X][wall2Y] == 0 && inputData[wall3X][wall3Y] == 0) {
					
					vector<vector<int>> map(n,vector<int>(m));

					for (int i = 0; i < n; i++)
						for (int j = 0; j < m; j++) 
							map[i][j] = inputData[i][j];

					map[wall1X][wall1Y] = 1;
					map[wall2X][wall2Y] = 1;
					map[wall3X][wall3Y] = 1;

					queue<pair<int, int>> bfs;
					for (pair<int, int> v : virus)
						bfs.push(v);

					while (bfs.size()) {
						pair<int, int> now = bfs.front();
						bfs.pop();

						for (int a = 0; a < 4; a++) {
							int nextX = now.first + dx[a];
							int nextY = now.second + dy[a];

							if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || map[nextX][nextY] != 0)
								continue;

							map[nextX][nextY] = 2;
							bfs.emplace(nextX, nextY);

						}

					}

					int safeArea = 0;
					for (int i = 0; i < n; i++)
						for (int j = 0; j < m; j++)
							if (map[i][j] == 0)
								safeArea++;
					if (safeArea > ans)
						ans = safeArea;
				}
			}
		}

	}
	cout << ans;
	return 0;
}