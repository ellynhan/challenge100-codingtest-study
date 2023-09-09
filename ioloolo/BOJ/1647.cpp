#include <bits/stdc++.h>

#define MAX 100001

using namespace std;

int N, M;
int parent[MAX];
int result;
vector<tuple<int, int, int>> edge;

int find_parent(int num) {
    if (num == parent[num]) return num;
    return parent[num] = find_parent(parent[num]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    if (a != b) {
        parent[a] = b;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    edge.resize(M);
    for (int i = 0; i < M; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;

        edge[i] = { cost, a, b };
    }

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    sort(edge.begin(), edge.end());

    int max_cost = 0;
    for (int i = 0; i < M; i++) {
        auto [cost, a, b] = edge[i];

        if (find_parent(a) != find_parent(b)) {
            max_cost = max(max_cost, cost);
            result += cost;
            union_parent(a, b);
        }
    }

    cout << result - max_cost;

    return 0;
}

