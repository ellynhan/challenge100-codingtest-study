#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000 + 1;
const int INF = 987654321;

int N, M;
int trace[MAX];
vector<pair<int, int>> graph[MAX];

vector<int> dijkstra(int start, int vertex) {
    vector<int> distance(vertex, INF);
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (distance[cur] < cost) continue;

        for (int i = 0; i < graph[cur].size(); i++) {
            int neighbor = graph[cur][i].first;
            int neighborDistance = cost + graph[cur][i].second;

            if (distance[neighbor] > neighborDistance) {
                distance[neighbor] = neighborDistance;
                trace[neighbor] = cur;
                pq.push({ neighborDistance, neighbor });
            }
        }
    }

    return distance;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    N++;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
    }

    int start, finish;
    cin >> start >> finish;

    vector<int> result = dijkstra(start, N);
    vector<int> route;

    cout << result[finish] << "\n";

    int node = finish;
    while (node){
        route.push_back(node);
        node = trace[node];
    }

    cout << route.size() << "\n";
    for (int i = route.size() - 1; i >= 0; i--) {
        cout << route[i] << " ";
    }
    cout << "\n";

    return 0;

}

