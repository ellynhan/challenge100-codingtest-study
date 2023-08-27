#include <bits/stdc++.h>

#define MAX 1001

using namespace std;

int N, M;
int start, destination;
int dist[MAX];
vector<pair<int, int>> Bus[MAX];
priority_queue<pair<int, int>> pq;

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;

        Bus[a].emplace_back(b, c);
    }

    cin >> start >> destination;
    for(int i = 1; i <= N; i++){
        dist[i] = 1e9;
    }

    pq.emplace(0, start);
    dist[start] = 0;

    while(!pq.empty()){
        auto [cost, cur] = pq.top();
        cost *= -1;
        pq.pop();

        if (dist[cur] < cost) continue;
        for (auto & i : Bus[cur]) {
            int next = i.first;
            int ncost = cost+i.second;

            if (dist[next] > ncost) {
                dist[next] = ncost;
                pq.emplace(-ncost, next);
            }
        }
    }
    cout << dist[destination];

    return 0;
}

