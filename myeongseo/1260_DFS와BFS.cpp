#include <bits/stdc++.h>

using namespace std;

bool graph[1001][1001];
bool visited[1001] = {false, };
vector<int> pathD, pathB;
queue<int> q;

int N, M, V, a, b;

void input() {
    cin >> N >> M >> V;
    while(M--) {
        cin >> a >> b;
        graph[a][b]=1; graph[b][a]=1;
    }
}

void dfs(int v) {
    visited[v] = true;
    pathD.push_back(v);

    for(int i=0; i<1001; i++) {
        if(graph[v][i]==1&&visited[i]==false) dfs(i);
    }
}

void bfs(int v) {
    if(!visited[v]) pathB.push_back(v);
    visited[v] = true;

    for(int i=0; i<1001; i++) {
        if(graph[v][i]==1&&visited[i]==false) q.push(i);
    }

    if(!q.empty()) {
        int next = q.front();
        q.pop();
        bfs(next);
    }
}


int main() {
    input();
    dfs(V);
    for(auto p : pathD) {
        cout << p << " ";
    }
    cout << endl;

    fill(visited, visited+1001, false);

    bfs(V);
    for(auto p : pathB) {
        cout << p << " ";
    }

    return 0;
}
