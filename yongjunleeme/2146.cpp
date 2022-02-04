#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, cnt = 0;
const int MX = 102;
int vis[MX][MX];
int dist[MX][MX];
int board[MX][MX];


bool OOB(int a, int b){
  return a < 0 || a >= n || b < 0 || b >= n;
}

void island(){
    int idx = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 0 || vis[i][j]) continue;
            queue<pair<int, int>> Q;
            Q.push({i, j});
            vis[i][j] = 1;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                board[cur.X][cur.Y] = idx;
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(OOB(nx, ny) || vis[nx][ny] || board[nx][ny] == 0) continue;
                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            idx++;
        }
    }
}


int main(void){
  ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> board[i][j];

    island();
    for(int i = 0; i < n; i++)
        fill(dist[i], dist[i] + n, -1);
    queue<pair<int, int>> Q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] != 0) {
                Q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    int ans = 999999;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(OOB(nx, ny) || board[cur.X][cur.Y] == board[nx][ny]) continue; // 인접한 곳이 다른 섬인 경우
            if(board[nx][ny] != 0) ans = min(ans, dist[cur.X][cur.Y] + dist[nx][ny]);

            else{ // 바다일 경우
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                board[nx][ny] = board[cur.X][cur.Y];
                Q.push({nx, ny});
            }
        }
    }
    cout << ans;
}
