#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int N, M;
int arr[8][8];
int visited[8][8];

int answer;

void copyArray(int des[8][8], int src[8][8]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            des[i][j] = src[i][j];
        }
    }
}

void spreadVirus() {
    queue<pair<int,int>> q;

    int spread[8][8];
    copyArray(spread, visited);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (spread[i][j] == 2) {
                q.emplace(i, j);
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (spread[nx][ny] != 0) continue;

            spread[nx][ny] = 2;
            q.emplace(nx, ny);
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (spread[i][j] == 0) {
                cnt++;
            }
        }
    }

    answer = max(answer, cnt);
}

void wall(int cur) {
    if (cur == 3) {
        spreadVirus();
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0) {
                visited[i][j] = 1;
                wall(cur+1);
                visited[i][j] = 0;
            }
        }
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
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j]==0) {
                copyArray(visited, arr);

                visited[i][j] = 1;
                wall(1);
                visited[i][j] = 0;
            }
        }
    }

    cout << answer;

    return 0;
}

