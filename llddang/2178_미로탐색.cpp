#include <iostream>
#include <queue>
using namespace std;

int N, M;
string map[100];
bool visited[100][100] = {false};

struct node{int i, j, cnt;};

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

void bfs(int ci, int cj){
    queue<node> q; q.push({ci, cj, 1});
    visited[ci][cj] = true;

    node n;
    int ni, nj;
    while(!q.empty()){
        n = q.front(); q.pop();

        for(int i=0; i<4; i++){
            ni = n.i + di[i]; nj = n.j + dj[i];

            if(0 > ni || ni >= N || 0 > nj || nj >= M) continue;
            if(visited[ni][nj] || map[ni][nj] == '0') continue;

            if(ni == N-1 && nj == M-1){
                cout << n.cnt + 1;
                return;
            }

            q.push({ni, nj, n.cnt+1});
            visited[ni][nj] = true;
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> map[i];

    bfs(0, 0);
}
