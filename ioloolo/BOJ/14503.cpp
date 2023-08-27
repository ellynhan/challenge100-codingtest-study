#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int N, M;
int r, c, d;
int answer;

vector<vector<int>> arr;
vector<vector<bool>> visited;

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    cin >> r >> c >> d;

    arr.assign(N, vector<int>(M));
    visited.assign(N, vector<bool>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    while (true) {
        if (!visited[r][c]) {
            visited[r][c] = true;
            answer++;
        }

        bool flag = false;

        for (int i = 0; i < 4; i++) {
            d = (d + 3) % 4;
            int nx = r + dx[d];
            int ny = c + dy[d];

            if (arr[nx][ny] == 0 && !visited[nx][ny]) {
                r += dx[d];
                c += dy[d];

                flag = true;
                break;
            }
        }

        if (!flag) {
            int back = (d + 2) % 4;

            if (arr[r + dx[back]][c + dy[back]] == 1) break;

            r += dx[back];
            c += dy[back];
        }
    }

    cout << answer;

    return 0;
}

