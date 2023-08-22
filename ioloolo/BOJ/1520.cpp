#include <bits/stdc++.h>

#define MAX 500

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int N, M;
int MAP[MAX][MAX];
int DP[MAX][MAX];

bool safe(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

bool arrive(int x, int y) {
    return x == N-1 && y == M-1;
}

int dfs(int x, int y) {
    if (!safe(x, y)) return 0;
    if (arrive(x, y)) return 1;

    if (DP[x][y] != -1) return DP[x][y];

    DP[x][y] = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (MAP[nx][ny] >= MAP[x][y])
            continue;

        DP[x][y] = DP[x][y] + dfs(nx, ny);
    }

    return DP[x][y];
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    memset(DP, -1, sizeof(DP));

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> MAP[i][j];

    cout << dfs(0, 0);
}

