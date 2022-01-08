#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int T, M, N, K, cnt;
bool adjMat[MAX][MAX];
bool Visit[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void Input()
{
    cin >> M >> N >> K;
    int x, y;
    for(int i=0; i < K; i++){
        cin >> x >> y;
        adjMat[y][x] = true;
    }
    
}

void DFS(int x, int y)
{
    Visit[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && ny>=0 && nx<N && ny < M)
            if(adjMat[nx][ny] && !Visit[nx][ny])
                    DFS(nx, ny);
    }
}

int main(void)
{
    cin >> T;
    while(T--) {
        cnt=0;
        Input();
        for(int i=0; i<N; i++){
            for(int j=0; j< M; j++)
                if(adjMat[i][j] && !Visit[i][j]){
                    cnt++;
                    DFS(i, j);
                }
        }
        cout << cnt << '\n';
        memset(adjMat, false, sizeof(adjMat));
        memset(Visit, false, sizeof(Visit));
    }
}
