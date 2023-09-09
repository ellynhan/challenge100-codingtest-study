#include <bits/stdc++.h>

#define MAX_N 22

using namespace std;

const int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};

int n;
int arr[MAX_N][MAX_N];
int bx, by;
int result = 0;
int cnt = 0;
int sz = 2;
bool stop = false;
bool eat = false;

void bfs(int a, int b, bool visit[][MAX_N], int shSize) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{a, b}, 0});
    visit[b][a] = true;
    int temp;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;

        if (arr[y][x] > 0 && arr[y][x] < shSize && temp == cnt) {
            if ((by > y) || (by == y && bx > x)) {
                by = y;
                bx = x;
                continue;
            }
        }

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[ny][nx]) {
                if (arr[ny][nx] <= shSize) {
                    if (arr[ny][nx] > 0 && arr[ny][nx] < shSize && !eat) {
                        eat = true;
                        bx = nx;
                        by = ny;
                        temp = cnt + 1;
                        result += temp;
                    } else {
                        q.push({{nx, ny}, cnt + 1});
                        visit[ny][nx] = true;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 9) {
                by = i;
                bx = j;
                arr[i][j] = 0;
            }
        }
    }

    while (!stop) {
        bool visit[MAX_N][MAX_N] = {0};
        bfs(bx, by, visit, sz);

        if (eat) {
            eat = false;
            cnt += 1;
            arr[by][bx] = 0;

            if (cnt == sz) {
                sz += 1;
                cnt = 0;
            }
        } else {
            stop = true;
        }
    }

    cout << result << '\n';
    return 0;
}

