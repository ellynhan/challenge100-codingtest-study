#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int x;
    int y;
    int k;
    int cnt;
} point;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

const int hdx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
const int hdy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int K, W, H;
int arr[200][200];
bool visited[201][201][31];

int bfs() {
    queue<point> q;
    
    q.push({ 0,0,0,0 });
    visited[0][0][0] = true;
    
    while (!q.empty()) {
        auto [x, y, k, cnt] = q.front();
        q.pop();

        if (x == H - 1 && y == W - 1) {
            return cnt;
        }
        
        if (k < K) {
            for (int i = 0; i < 8; i++) {
                int nx = hdx[i] + x;
                int ny = hdy[i] + y;
                
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (visited[nx][ny][k+1] || arr[nx][ny] == 1) continue;
                
                visited[nx][ny][k+1] = true;
                q.push({nx, ny, k+1, cnt+1});
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = dy[i] + x;
            int ny = dx[i] + y;
            
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (visited[nx][ny][k] || arr[nx][ny] == 1) continue;
            
            visited[nx][ny][k] = true;
            q.push({nx, ny, k, cnt+1});
        }
    }
    
    return -1;
}

int main() {
    cin >> K >> W >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> arr[i][j];
        }
    }

    cout << bfs();
    
    return 0;
}

