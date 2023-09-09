#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m;
int graph[501][501];
bool visited[501][501];

int answer;

void dfs(int x, int y, int depth, int sum) {
    if (depth == 3) {
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
        if (visited[nx][ny]) continue;

        visited[nx][ny] = true;
        dfs(nx, ny, depth + 1, sum + graph[nx][ny]);
        visited[nx][ny] = false;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = true;
            dfs(i, j, 0, graph[i][j]);
            visited[i][j] = false;

            if (i-1 >= 0 && j + 2 < m) {
                answer = max(answer, graph[i][j] + graph[i][j+1] + graph[i][j + 2] + graph[i-1][j+1]);
            }
            if (j + 2 < m && i+1 < n) {
                answer = max(answer, graph[i][j] + graph[i][j+1] + graph[i][j + 2] + graph[i+1][j+1]);
            }
            if (i+2 < n && j+1 < m) {
                answer = max(answer, graph[i][j] + graph[i+1][j] + graph[i+2][j] + graph[i+1][j+1]);
            }
            if (i+1 < n && i-1 >= 0 && j+1 < m) {
                answer = max(answer, graph[i][j] + graph[i-1][j+1] + graph[i][j+1] + graph[i+1][j+1]);
            }
        }
    }

    cout << answer;

    return 0;
}

