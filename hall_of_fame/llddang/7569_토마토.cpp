#include <iostream>
#include <queue>
using namespace std;

int N, M, H;
int i, j, k, l;
int ni, nj, nk, cnt;
int answer = 1;
int arr[100][100][100];
bool visited[100][100][100]={false};
struct node{int i, j, k, n;};
queue<node> q;

int di[6] = {0, 0, 0, 0, 1, -1};
int dj[6] = {0, 0, 1, -1, 0, 0};
int dk[6] = {1, -1, 0, 0, 0, 0};

void bfs(){
    node n;
    while(!q.empty()){
        n = q.front(); q.pop();

        cnt = n.n + 1;
        for(l=0; l<6; l++){
            ni = n.i + di[l];
            nj = n.j + dj[l];
            nk = n.k + dk[l];
            if(0 > ni || ni >= N
            || 0 > nj || nj >= M
            || 0 > nk || nk >= H) continue;

            if(visited[ni][nj][nk] ||arr[ni][nj][nk] == -1) continue;

            arr[ni][nj][nk] = cnt;
            visited[ni][nj][nk] = true;
            q.push({ni, nj, nk, cnt});
            answer = max(answer, cnt);
        }
    }
}

int main(){
    cin >> N >> M >> H;

    for( k=0; k<H; k++)
    for( j=0; j<M; j++)
    for( i=0; i<N; i++){
        cin >> arr[i][j][k];
        if(arr[i][j][k] == 1){
            q.push({i, j, k, 1});
            visited[i][j][k] = true;
        }
    }

    bfs();

    for( k=0; k<H; k++)
    for( j=0; j<M; j++)
    for( i=0; i<N; i++){
        if(arr[i][j][k] == 0){
            cout << -1;
            return 0;
        }
    }

    cout << answer - 1;
}
