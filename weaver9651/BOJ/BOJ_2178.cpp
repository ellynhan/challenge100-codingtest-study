#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M;
int map[101][101] = {0,}; // 1-index
int dist[101][101] = {0,};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void init() {
    cin >> N >> M;
    string line;
    for (int i = 1; i <= N; i++) {
        cin >> line;
        for (int j = 1; j <= M; j++) {
            map[i][j] = line[j-1] - '0';
        }
    }
}

// debug
void print_map() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

// debug
void print_dist_map() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << dist[i][j];
        }
        cout << endl;
    }
}

int bfs() {
    vector<bool> row_visit(M+1, false);
    vector<vector<bool>> visit(N+1, row_visit);
    queue<pii> q;
    pii cur;
    pii next;

    q.push(pii(1, 1));
    visit[1][1] = true;
    dist[1][1] = 1;

    while (!q.empty()) {
        cur = q.front();   
        q.pop();

        for (int d = 0; d < 4; d++) {
            next.first = cur.first + dx[d];
            next.second = cur.second + dy[d];
            if (map[next.first][next.second] == 1 && !visit[next.first][next.second]) {
                visit[next.first][next.second] = true;
                q.push(next);
                dist[next.first][next.second] = dist[cur.first][cur.second] + 1;
                if (next.first == N && next.second == M) {
                    return dist[next.first][next.second];
                }
            }
        }
    }
    return -1;
}

int main() {
    init();
    // print_map();
    int result = bfs();
    cout << result << endl;
    // print_dist_map();

    return 0;
}