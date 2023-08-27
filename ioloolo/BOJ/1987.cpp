#include <bits/stdc++.h>

using namespace std;

int R, C;
vector<vector<char>> arr(20, vector<char>(20));
vector<bool> visited(26);

int answer;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int length) {
    answer = max(answer, length);

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (!(nx >= 0 && ny >= 0 && nx < R && ny < C) || visited[arr[nx][ny] - 'A']) continue;

        visited[arr[nx][ny] - 'A'] = true;
        dfs(nx, ny, length + 1);
        visited[arr[nx][ny] - 'A'] = false;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }

    visited[arr[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << answer;

    return 0;
}

