#include <bits/stdc++.h>

using namespace std;

int dx[3] = { -1, 0, 1 };
int dy[3] = { 1, 1, 1 };

int R, C;
int arr[10001][501];
int visited[10001][501];

bool check;
int cnt;

void dfs(int x, int y) {
    visited[x][y] = true;

    if (y == C) {
        check = true;
        cnt++;
        return;
    }

    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (!(nx >= 1 && ny >= 1 && nx <= R && ny <= C)) continue;
        if (!(arr[nx][ny] == 1 && !visited[nx][ny])) continue;

        dfs(nx, ny);

        if (check) return;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> R >> C;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            char c;
            cin >> c;
            arr[i][j] = c == '.' ? 1 : 0;
        }
    }

    for (int i = 1; i <= R; i++) {
        check = false;
        dfs(i, 1);
    }

    cout << cnt;

    return 0;
}

