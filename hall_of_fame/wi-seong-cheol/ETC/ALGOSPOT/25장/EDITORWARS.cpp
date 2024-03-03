//
//  EDITORWARS.cpp
//  main
//
//  Created by wi_seong on 1/23/24.
//

/*
 [Input]
 4
 4 4
 ACK 0 1
 ACK 1 2
 DIS 1 3
 ACK 2 0
 100 4
 ACK 0 1
 ACK 1 2
 ACK 2 3
 ACK 3 4
 3 3
 ACK 0 1
 ACK 1 2
 DIS 2 0
 8 6
 DIS 0 1
 ACK 1 2
 ACK 1 4
 DIS 4 3
 DIS 5 6
 ACK 5 7
 [Output]
 MAX PARTY SIZE IS 3
 MAX PARTY SIZE IS 100
 CONTRADICTION AT 3
 MAX PARTY SIZE IS 5
 */
// 시간복잡도: O(n + m)
// 최악시간: 110,000
// 난이도: 중
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/EDITORWARS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct NaiveDisjointSet {
    vector<int> parent, rank, enemy, size;

    NaiveDisjointSet(int n) : parent(n), rank(n, 1), enemy(n, -1), size(n, 1) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    int merge(int u, int v) {
        if(u == -1 || v == -1) return max(u, v);
        u = find(u); v = find(v);
        if(u == v) return u;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        size[v] += size[u];
        if(rank[u] == rank[v]) ++rank[v];
        return v;
    }

    bool dis(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return false;
        int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
        enemy[a] = b; enemy[b] = a;
        return true;
    }

    bool ack(int u, int v) {
        u = find(u); v = find(v);
        if(enemy[u] == v) return false;
        int a = merge(u, v), b = merge(enemy[u], enemy[v]);
        enemy[a] = b;
        if(b != -1) enemy[b] = a;
        return true;
    }

    int maxParty() {
        int ret = 0;
        for(int idx = 0; idx < size.size(); idx++) {
            if(parent[idx] == idx) {
                int enemy_idx = enemy[idx];
                if(enemy_idx > idx) continue;
                int mySize = size[idx];
                int enemySize = (enemy_idx == -1 ? 0 : size[enemy_idx]);
                ret += max(mySize, enemySize);
            }
        }
        return ret;
    }
};
int t, n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        NaiveDisjointSet set(n);

        bool flag = true;
        int idx = 0;
        for(int i = 1; i <= m; i++) {
            int a, b;
            string s;
            cin >> s >> a >> b;
            if(!flag) continue;

            if(s == "ACK") {
                if(!set.ack(a, b)) {
                    idx = i;
                    flag = false;
                }
            } else {
                if(!set.dis(a, b)) {
                    idx = i;
                    flag = false;
                }
            }
        }
        if(flag) {
            cout << "MAX PARTY SIZE IS " << set.maxParty() << "\n";
        } else {
            cout << "CONTRADICTION AT " << idx << "\n";
        }
    }

    return 0;
}
