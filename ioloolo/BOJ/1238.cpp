#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N, M, X;
vector<pii> graph[2][1001];
vector<int> dist[2];

int answer;

void dijkstra(int k){
    priority_queue<pii, vector<pii>, greater<>> pq;

    pq.emplace(0, X);
    dist[k][X] = 0;

    while (!pq.empty()) {
        auto [cost, n] = pq.top();
        pq.pop();

        if (cost > dist[k][n]) continue;

        for (auto [next_cost, next] : graph[k][n]) {
            next_cost += cost;

            if (next_cost < dist[k][next]) {
                dist[k][next] = next_cost;

                pq.emplace(next_cost, next);
            }
        }
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> X;

    for (int i = 0; i < M; i++) {
        int u, v, t;
        cin >> u >> v >> t;

        graph[0][u].emplace_back(t, v);
        graph[1][v].emplace_back(t, u);
    }

    dist[0].assign(N+1, 2e9);
    dist[1].assign(N+1, 2e9);

    dijkstra(1);
    dijkstra(0);

    for (int i = 1; i <= N; i++) {
        answer = max(answer, dist[0][i] + dist[1][i]);
    }

    cout << answer;

    return 0;
}

