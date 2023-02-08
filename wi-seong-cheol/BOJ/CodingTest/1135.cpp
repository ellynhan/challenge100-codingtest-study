//
//  1135.cpp
//  main
//
//  Created by wi_seong on 2023/02/08.
//

/*
 [Input]
 3
 -1 0 0
 [Output]
 2
 */
// 시간복잡도: O(n + e)
// 최악시간: 100
// 난이도: Gold 2
// Timer: 40m
// Url: https://www.acmicpc.net/problem/1135

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, x, ans;
vector<int> adj[51];

int dfs(int cur) {
    int ret = 0;
    vector<int> v;
    int w = (int)adj[cur].size() - 1;
    for(int nxt: adj[cur])
        v.push_back(dfs(nxt));
    sort(v.begin(), v.end());
    for(int time: v)
        ret = max(ret, time + w--);
    return ret + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(x == -1) continue;
        adj[x].push_back(i);
    }
    ans = dfs(0);
    cout << ans - 1;
    
    return 0;
}

