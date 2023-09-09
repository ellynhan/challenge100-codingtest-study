#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

int N, M;
int arr[8][8];
vector<pair<int, int>> cctv;

int answer = 2e9;

void check(int x, int y, int dir) {
    while (true) {
        int nx = x + dx[dir % 4];
        int ny = y + dy[dir % 4];

        x = nx;
        y = ny;

        if(nx < 0 || ny < 0 || nx >= N || ny >= M) return;
        if(arr[nx][ny] == 6) return;
        if(arr[nx][ny] != 0) continue;

        arr[nx][ny] = -1;
    }
}

void dfs(int idx) {
    if (idx == cctv.size()) {
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!arr[i][j]) {
                    cnt++;
                }
            }
        }

        answer = min(answer, cnt);

        return;
    }

    int tmp[8][8];
    auto [x, y] = cctv[idx];

    for(int dir = 0; dir < 4; dir++) {
        memcpy(tmp, arr, sizeof(arr));

        if(arr[x][y] == 1) {
            check(x, y, dir);
        } else if(arr[x][y] == 2) {
            check(x, y, dir);
            check(x, y, dir+2);
        } else if (arr[x][y] == 3) {
            check(x, y, dir);
            check(x, y, dir + 1);
        } else if (arr[x][y] == 4) {
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
        } else if (arr[x][y] == 5) {
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
            check(x, y, dir + 3);
        }

        dfs(idx + 1);

        memcpy(arr, tmp, sizeof(tmp));
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];

            if (arr[i][j] != 0 && arr[i][j] != 6) {
                cctv.emplace_back(i, j);
            }
        }
    }

    dfs(0);

    cout << answer;

    return 0;
}

