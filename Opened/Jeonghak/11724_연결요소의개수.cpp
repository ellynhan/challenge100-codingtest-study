#include<iostream>
using namespace std;

int N, M, cnt, graph[1001][1001];
bool visit[1001];
void dfs(int v){
    visit[v] = true;
    for(int i=1; i<=N; i++)
    if(graph[v][i] && !visit[i]){
        dfs(i);
    }
}

int main()
{
    cin >> N >> M;

    for(int i=0; i<M; i++){
        int x,y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    for(int i=1;i<=N;i++){
        if(!visit[i]){
            cnt++;
            dfs(i);
        }
    }
    cout << cnt << endl;
}
