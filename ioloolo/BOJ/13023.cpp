#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> v(2001);
vector<bool> check(2001);

void dfs(vector<int> list) {
    int now = list.back();
    
    if (list.size() > 1) {
        for (int i = 0; i <= list.size() - 2; i++) {
            if (list[i] == now) {
                return;
            }
        }
        
        if (list.size() == 5) {
            cout << 1;
            exit(0);
        }
    }
    
    for (int i : v[now]) {
        list.push_back(i);
        dfs(list);
        list.pop_back();
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        
        v[a].push_back(b);
        v[b].push_back(a);
        
        check[a] = true;
        check[b] = true;
    }
    
    vector<int> list;
    for (int i = 0; i < check.size(); i++) {
        if (!check[i]) continue;

        list.push_back(i);
        dfs(list);
        list.pop_back();
    }

    cout << 0 ;
    return 0;
}
