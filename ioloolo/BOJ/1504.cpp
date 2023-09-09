#include <bits/stdc++.h>

#define MAX 801

using namespace std;

typedef pair<int, int> pii;

int N, E;
int v1, v2;
int answer = 2e9;

vector<pii> v[MAX];
int dist[MAX];

void dijkstra(int start) {
    priority_queue<pii, vector<pii>, greater<>> q;

    for (int i = 0; i <= N; i++) {
        dist[i] = 2e9;
    }
    dist[start] = 0;

    q.emplace(start, 0);

    while (!q.empty()) {
        auto [c, cd] = q.top();
        q.pop();

        for (auto [n, nd] : v[c]) {
            if (dist[n] > cd + nd) {
                dist[n] = cd + nd;
                q.emplace(n, dist[n]);
            }
        }
    }
}

int main() {
    cin >> N >> E;
    
    while (E--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        v[a].emplace_back(b, c);
        v[b].emplace_back(a, c);
    }
    
    cin >> v1 >> v2;

    dijkstra(1);
    int a1 = dist[v1];
    int a2 = dist[v2];

    dijkstra(v1);
    int b1 = dist[v2];
    int b2 = dist[N];

    dijkstra(v2);
    int c1 = dist[N];

    answer = min(answer, min(a2 + b1 + b2, a1 + b1 + c1));

    cout << (b1 == 2e9 || answer == 2e9 ? -1 : answer);

    return 0;
}

