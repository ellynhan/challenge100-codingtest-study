#include<iostream>
#include<queue>
#define MAX 100
using namespace std;

int N, M;
bool visit[MAX][MAX];
queue<pair<int, int>> q;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int cnt[MAX][MAX] = {0};
char map[MAX][MAX];

void BFS(int x, int y){
    cnt[x][y]++;
    q.push(make_pair(x, y));
    visit[x][y] = true;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M && visit[nx][ny]==false && map[nx][ny] == '1'){
                q.push(make_pair(nx, ny));
                visit[nx][ny] = true;
                cnt[nx][ny] = cnt[x][y] + 1;
            }
        }
    }
}
int main(void){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> map[i];
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            visit[i][j] = false;
    }

    BFS(0, 0);
    cout << cnt[N-1][M-1];
    return 0;
}
