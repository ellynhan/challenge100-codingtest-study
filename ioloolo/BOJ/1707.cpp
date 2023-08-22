#include <bits/stdc++.h>

using namespace std;

int V, E;

int visited[20001];
vector<int> v[20001];

queue<int> q;

void BFS(int start) {
    visited[start] = 1;
    q.push(start);

    while (!q.empty()) {
        auto n = q.front();
        q.pop();

        for (int i = 0; i < v[n].size(); i++) {
            if(visited[v[n][i]] == 0) {
                q.push(v[n][i]);
                visited[v[n][i]] = visited[n] == 1 ? 2 : 1;
            }
        }
    }
}

bool check() {
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (visited[i] == visited[v[i][j]]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int K;
    cin >> K;

    while (K--) {
        cin >> V >> E;
        for (int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;

            v[a].push_back(b);
            v[b].push_back(a);
        }

        for (int i = 1; i <= V; i++) {
            if (visited[i] == 0) {
                BFS(i);
            }
        }

        cout << (check() ? "YES" : "NO") << '\n';

        memset(visited, 0, sizeof(visited));
        memset(v, 0, sizeof(v));
    }
}

