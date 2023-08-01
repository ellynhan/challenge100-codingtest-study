//
//  16437.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/07.
//

/*
 [Input]
 4
 S 100 3
 W 50 1
 S 10 1
 [Output]
 60
 */
// 시간복잡도: O(E + V)
// 최악시간: 123,456
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/16437

#include <iostream>
#include <vector>

using namespace std;
#define ll long long
int n, a, p;
char t;
ll val[123457];
vector<int> adj[123457];

ll dfs(int cur) {
    ll ret = 0;
    
    for(int nxt: adj[cur])
        ret += dfs(nxt);
    
    ret += val[cur];
    if(ret < 0) ret = 0;
    
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 2; i <= n; i++) {
        cin >> t >> a >> p;
        if(t == 'W') val[i] = -1 * a;
        else val[i] = a;
        adj[p].push_back(i);
    }
    cout << dfs(1);
    
    return 0;
}
