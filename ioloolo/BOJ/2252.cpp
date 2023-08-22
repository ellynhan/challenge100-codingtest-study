#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> topology(32001);
vector<bool> visited(32001);
queue<int> q;

void dfs(int node){
    if (visited[node]) return;

    visited[node] = true;

    for (int i : topology[node]) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    cout << node << ' ';
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        topology[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i) {
        if (topology[i].empty()) {
            visited[i] = true;
            cout << i << ' ';
        } else {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if(visited[node]) continue;

        dfs(node);
    }
}

