//
//  17142.cpp
//  main
//
//  Created by wi_seong on 3/13/24.
//

/*
 [Input]
 7 3
 2 0 0 0 1 1 0
 0 0 1 0 1 2 0
 0 1 1 0 1 0 0
 0 1 0 0 0 0 0
 0 0 0 2 0 1 1
 0 1 0 0 0 0 0
 2 1 0 0 0 0 2
 [Output]
 4
 */
// 시간복잡도: O(2 ^ 10 * n ^ 2)
// 최악시간: 256,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/17142

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
const int INF = 1e9 + 7;
struct Point {
    int x, y;
};
int n, m;
int emptyCount;
int board[51][51];
vector<Point> virus, allVirus;
int dist[51][51];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int bfs() {
    int ret = 0;
    int cnt = 0;
    queue<Point> Q;
    for(auto element: virus) {
        Q.push(element);
        dist[element.x][element.y] = 0;
    }

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(OOB(nx, ny) || board[nx][ny] == 1) continue;
            if(dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            Q.push({nx, ny});
            if(board[nx][ny] == 0) {
                cnt++;
                ret = dist[nx][ny];
            }
        }
    }

    if(emptyCount != cnt) return INF;
    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) allVirus.push_back({i, j});
            else if(board[i][j] == 0) emptyCount++;
        }
    }
    
    int ans = INF;
    vector<int> brute(int(allVirus.size()));
    fill(brute.begin() + m, brute.end(), 1);
    do {
        virus.clear();
        memset(dist, -1, sizeof(dist));
        for(int i = 0; i < int(brute.size()); i++) {
            if(!brute[i]) virus.push_back(allVirus[i]);
        }
        int result = bfs();
        ans = min(ans, result);
    } while(next_permutation(brute.begin(), brute.end()));

    if(ans == INF) cout << -1;
    else cout << ans;

	return 0;
}
