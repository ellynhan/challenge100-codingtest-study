#include<bits/stdc++.h>

using namespace std;

int dx[6] = {1, 0, -1 ,0 ,0 ,0};
int dy[6] = {0, 1, 0, -1 ,0 ,0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int m, n, h;
int board[102][102][102];
int dist[102][102][102];

queue<tuple<int, int, int>> q;

int answer;

void bfs(){
    while(!q.empty()){
        auto [x, y, z] = q.front();
        q.pop();

        for (int i = 0; i < 6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
            if (dist[nx][ny][nz] >= 0) continue;

            q.emplace(nx, ny, nz);

            dist[nx][ny][nz] = dist[x][y][z] + 1;
        }
    }
}
int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> m >> n >> h;

    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j][k];
                
                if (board[i][j][k] == 1){
                    q.emplace(i, j, k);
                }
                
                if (board[i][j][k] == 0){
                    dist[i][j][k] = -1;
                }
            }
        }
    }

    bfs();

    for (int k = 0; k < h; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (dist[i][j][k] == -1) {
                    cout << -1;
                    return 0;
                }

                answer = max(answer, dist[i][j][k]);
            }
        }
    }

    cout << answer;

    return 0;
}

