#include <bits/stdc++.h>

using namespace std;

int V, E;
int parent[10001];
int ans;

vector<tuple<int, int, int>> v;

int find_(int x){
    if (parent[x] == x) return x;

    return parent[x] = find_(parent[x]);
}

void union_(int a, int b){
    a = find_(a);
    b = find_(b);

    parent[b] = a;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> V >> E;

    for (int i = 0; i < E; i++){
        int a, b, c;
        cin >> a >> b >> c;

        v.emplace_back(c, a, b);
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }

    int cnt = 0;
    for (auto curEdge : v) {
        auto [cost, now, next] = curEdge;

        if (find_(now) == find_(next)) continue;

        union_(now, next);
        ans += cost;

        if(++cnt == V - 1) break;
    }

    cout << ans;

    return 0;
}

