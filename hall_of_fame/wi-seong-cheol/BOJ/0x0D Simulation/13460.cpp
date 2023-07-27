//
//  13460.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 7 7
 #######
 #..R#B#
 #.#####
 #.....#
 #####.#
 #O....#
 #######
 [Output]
 5
 */
// 시간복잡도: O(n^2)
// 최악시간: 100
// 난이도: Gold1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/13460

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
#define X first
#define Y second
int n, m;
pair<int,int> red, blue;
string board[11];
int dist[11][11][11][11];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int bfs() {
    queue<tuple<int, int, int, int>> Q;
    Q.push({red.X, red.Y, blue.X, blue.Y});
    dist[red.X][red.Y][blue.X][blue.Y] = 0;
    while(!Q.empty()) {
        int rx, ry, bx, by;
        tie(rx, ry, bx, by) = Q.front(); Q.pop();
        int cnt = dist[rx][ry][bx][by];
        if(cnt >= 10) return -1;
        for(int dir = 0; dir < 4; dir++) {
            int nrx = rx;
            int nry = ry;
            int nbx = bx;
            int nby = by;
            
            // Blue 이동
            while(board[nbx + dx[dir]][nby + dy[dir]] == '.') {
                nbx += dx[dir];
                nby += dy[dir];
            }
            if(board[nbx + dx[dir]][nby + dy[dir]] == 'O') continue;
            
            // Red 이동
            while(board[nrx + dx[dir]][nry + dy[dir]] == '.') {
                nrx += dx[dir];
                nry += dy[dir];
            }
            if(board[nrx + dx[dir]][nry + dy[dir]] == 'O') return cnt + 1;
            
            // Red, Blue가 겹쳐진 경우 늦게 출발한 구슬을 한칸 뒤로 이동
            if((nrx == nbx) && (nry == nby)) {
                if(dir == 0) // 위쪽
                    ry < by ? nry-- : nby--;
                else if(dir == 1) // 오른쪽
                    rx < bx ? nrx-- : nbx--;
                else if(dir == 2) // 아래쪽
                    ry > by ? nry++ : nby++;
                else // 왼쪽
                    rx > bx ? nrx++ : nbx++;
            }
            if (dist[nrx][nry][nbx][nby] != -1) continue;
            dist[nrx][nry][nbx][nby] = cnt + 1;
            Q.push({nrx, nry, nbx, nby});
        }
    }
    
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            for(int k = 0; k < 10; k++)
                fill(dist[i][j][k], dist[i][j][k] + 10, -1);
    
    for(int i = 0; i < n; i++) {
        cin >> board[i];
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'R') {
                red = {i, j};
                board[i][j] = '.';
            }
            else if(board[i][j] == 'B') {
                blue = {i, j};
                board[i][j] = '.';
            }
        }
    }
    
    cout << bfs();
    
    return 0;
}
