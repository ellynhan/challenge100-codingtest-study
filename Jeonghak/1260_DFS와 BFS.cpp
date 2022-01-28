#include <bits/stdc++.h>

#define MAX 1001

using namespace std;

int N, M, V;
bool adjMat[MAX][MAX]; //인접 행렬
bool Visit[MAX];    // 방문 여부
queue<int> q;       // bfs 방문할 노드 저장을 위한 queue

// 재귀를 이용한 DFS
void DFS(int v){
    Visit[v] = true;
    cout << v << ' ';
    for(int i=1; i<=N; i++){
        if(adjMat[v][i] == true && Visit[i] == false)
            DFS(i);
    }
}

// queue를 이용한 BFS
void BFS(int v){
    q.push(v);
    Visit[v] = true;
    cout << v << ' ';

    while(!q.empty()){
        v = q.front();
        q.pop();
        // 자연수 오름차순으로 방문할 노드 탐색
        for(int i=1; i<=N; i++){
            if(adjMat[v][i] == true && Visit[i] == false){
                q.push(i);
                Visit[i] = true;
                cout << i << ' ';
            }
        }

    }
}

int main(void){
    cin >> N >> M >> V;
    for(int i=0; i<M; i++){
        int x, y;
        cin >> x >> y;
        // 인접 행렬
        adjMat[x][y] = true;
        adjMat[y][x] = true;
    }
    DFS(V);
    cout << '\n';
    memset(Visit, false, MAX);  // Visit 초기화
    BFS(V);
    return 0;
}
