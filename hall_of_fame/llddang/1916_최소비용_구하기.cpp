#include <iostream>
#include <queue>
using namespace std;

int N, M;
int start, goal;
int arr[1001][1001];
int value[1001];
queue<pair<int, int>> q;

void bfs(){
    value[start] = 0;
    q.push({start, 0});

    int idx, fee;
    while(!q.empty()){
        idx = q.front().first;
        fee = q.front().second;
        q.pop();

        for(int i=1; i<=N; i++){
            if(arr[idx][i] == INT32_MAX) continue;
            if(value[i] <= fee + arr[idx][i]) continue;

            value[i] = fee + arr[idx][i];
            q.push({i, value[i]});
        }
    }
}

int main(){
    cin >> N >> M;

    for(int i=1; i<=N; i++)
    for(int j=1; j<=N; j++) arr[i][j] = INT32_MAX;
    
    for(int i=1; i<=N; i++) value[i] = INT32_MAX;

    int s, e, fee;
    for(int i=0; i<M; i++){
        cin >> s >> e >> fee;
        if(fee < arr[s][e]) arr[s][e] = fee;
    }
    cin >> start >> goal;

    bfs();

    cout << value[goal];
}
