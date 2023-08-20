#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

void optimization();
void input();
void dfs(const vector<vector<char>>&, int, int);
int count(const vector<vector<char>>&);

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int N;
vector<vector<char>> normal;
vector<vector<char>> color_week;
vector<vector<bool>> visited;

int main() {
    optimization();
    input();

    int normal_count = count(normal);
    int color_week_count = count(color_week);

    cout << normal_count << ' ' << color_week_count;
}

void optimization() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

void input() {
    cin >> N;

    normal.assign(N, vector<char>(N, '-'));
    color_week.assign(N, vector<char>(N, '-'));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char c;
            cin >> c;

            normal[i][j] = c;
            color_week[i][j] = c == 'G' ? 'R' : c;
        }
    }
}

void dfs(const vector<vector<char>>& table, int y, int x) {
    visited[y][x] = true;

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (!visited[ny][nx] && table[y][x] == table[ny][nx]) {
            dfs(table, ny, nx);
        }
    }
}

int count(const vector<vector<char>>& table) {
    int cnt = 0;

    visited.assign(N, vector<bool>(N, false));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j]) {
                dfs(table, i, j);
                cnt++;
            }
        }
    }

    return cnt;
}
