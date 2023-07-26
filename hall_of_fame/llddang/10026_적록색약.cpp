#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N;
string arr[100];
bool visited[100][100];
struct node{int i, j;};
queue<node> q;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

void bfs(int ci, int cj, char color){
    visited[ci][cj] = true;

    q.push({ci, cj});
    node n;
    int ni, nj;
    while(!q.empty()){
        n = q.front(); q.pop();
        ci = n.i; cj = n.j;
        for(int l=0; l<4; l++){
            ni = ci + di[l]; nj = cj + dj[l];
            
            if(0 > ni || ni >= N || 0 > nj || nj >= N) continue;
            if(visited[ni][nj] || color != arr[ni][nj]) continue;

            q.push({ni, nj});
            visited[ni][nj] = true;
        }
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];

    int normalCnt = 0, disableCnt = 0;

    memset(visited, false, sizeof(visited));
    for(int i=0; i<N; i++)
    for(int j=0; j<N; j++){
        if(!visited[i][j]) bfs(i, j, arr[i][j]), normalCnt++;
        if(arr[i][j] == 'R') arr[i][j] = 'G';
    }

    memset(visited, false, sizeof(visited));
    for(int i=0; i<N; i++)
    for(int j=0; j<N; j++){
        if(!visited[i][j]) bfs(i, j, arr[i][j]), disableCnt++;
    }

    cout << normalCnt << " " << disableCnt;
}
