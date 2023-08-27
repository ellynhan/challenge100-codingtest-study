#include <bits/stdc++.h>

#define INF 1000000
#define MAX_VERTEX 20001 
#define MAX_EDGE 300001

using namespace std;

int d[MAX_VERTEX];
vector<pair<int, int> > edge[MAX_EDGE];
priority_queue<pair<int, int>> pq;

void dijkstra(int start_node){
    d[start_node] = 0;

    pq.emplace(0, start_node);

    while(!pq.empty()){
        int curr = pq.top().second;
        int cd = -pq.top().first;

        pq.pop();

        if (d[curr] < cd){
            continue;
        }

        for (auto & i : edge[curr]){
            int next = i.second;

            int nd = cd + i.first;

            if (d[next] > nd){
                d[next] = nd;
                pq.emplace(-d[next], next);
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int v, e, s;
    cin >> v >> e >> s;

    for (int i=1; i<v+1; ++i){
        d[i] = INF;
    }

    for (int i=0; i<e; ++i){
        int start, end, cost;
        cin >> start >> end >> cost;

        edge[start].emplace_back(cost, end);
    }

    dijkstra(s);

    for (int i=1; i<v+1; ++i){
        if (d[i] == INF) {
            cout << "INF";
        } else {
            cout << d[i];
        }
        cout << '\n';
    }

    return 0;
}

