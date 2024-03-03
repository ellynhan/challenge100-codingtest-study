//
//  20005.cpp
//  main
//
//  Created by wi_seong on 1/11/24.
//

/*
 [Input]
 6 6 3
 b.Bc..
 ......
 .a....
 ......
 ...X..
 .....X
 a 36
 b 19
 c 39
 79
 [Output]
 2
 */
// 시간복잡도: O(n ^ 2 * p)
// 최악시간: 26,000,000
// 난이도: Gold 3
// Timer: 40m
// Url: https://www.acmicpc.net/problem/20005

#include <iostream>
#include <queue>
#include <unordered_map>
#include <cstring>

using namespace std;
#define X first
#define Y second
int n, m, p;
string board[1001];
unordered_map<char, int> id;
pair<int, int> player[26];
pair<int, int> boss;
int hp;
int dps[26];
int dist[26][1001][1001];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void bfs(int id) {
    queue<pair<int, int>> Q;
    Q.push({player[id].X, player[id].Y});
    dist[id][player[id].X][player[id].Y] = 0;

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        if(board[cur.X][cur.Y] == 'B') break;
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || board[nx][ny] == 'X') continue;
            if(dist[id][nx][ny] != -1) continue;
            dist[id][nx][ny] = dist[id][cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    memset(dist, -1, sizeof(dist));
    int numberOfPlayer = 0;

    cin >> n >> m >> p;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
        for(int j = 0; j < m; j++) {
            if('a' <= board[i][j] && board[i][j] <= 'z') {
                player[numberOfPlayer] = {i, j};
                id[board[i][j]] = numberOfPlayer++;
            }
            if(board[i][j] == 'B')
                boss = {i, j};
        }
    }

    for(int i = 0; i < p; i++) {
        char c; int d;
        cin >> c >> d;
        int playerId = id[c];
        dps[playerId] = d;
        bfs(playerId);
    }
    cin >> hp;

    int turn = 0;
    int cnt = 0;
    while(hp > 0) {
        turn++;
        cnt = 0;
        for(int i = 0; i < p; i++) {
            if(dist[i][boss.X][boss.Y] > turn) continue;
            cnt++;
            hp -= dps[i];
        }
    }
    cout << cnt;

	return 0;
}
