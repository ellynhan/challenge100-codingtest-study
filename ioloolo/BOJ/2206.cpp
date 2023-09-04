#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

typedef struct {
    int x;
    int y;
    int depth;
    int flag;
} Node;

const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };

int n, m;
int arr[MAX][MAX];
bool visited[MAX][MAX][2] = { false, };
queue<Node> q;

int bfs() {
    q.push({ 0, 0, 1, false });
    visited[0][0][0] = true;

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        if (curr.x == m - 1 && curr.y == n - 1) {
            return curr.depth;
        }

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

            if (arr[ny][nx] == 1 && curr.flag == 0) {
                visited[ny][nx][curr.flag + 1] = true;
                q.push({ nx, ny, curr.depth + 1, curr.flag + 1 });
            } else if (arr[ny][nx] == 0 && !visited[ny][nx][curr.flag]) {
                visited[ny][nx][curr.flag] = true;
                q.push({ nx, ny, curr.depth + 1, curr.flag });
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        for (int j = 0; j < m; j++) {
            arr[i][j] = temp[j] - 48;
        }
    }

    cout << bfs();

    return 0;
}

