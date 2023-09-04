#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n, m;
int graph[1001][1001];

queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;

            if (graph[nx][ny] == -1)
                continue;

            if (graph[nx][ny] == 0) {
                graph[nx][ny] = graph[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];

            if (graph[i][j] == 1)
                q.emplace(i, j);
        }

    bfs();

    int result = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            result = max(result, graph[i][j] - 1);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (graph[i][j] == 0)
                result = -1;

    cout << result;
}
