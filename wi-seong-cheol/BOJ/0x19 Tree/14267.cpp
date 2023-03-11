//
//  14267.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5 3
 -1 1 2 3 4
 2 2
 3 4
 5 6
 [Output]
 0 2 6 6 12
 */
// 시간복잡도: O(n + e)
// 최악시간: 200,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/14267

#include <iostream>
#include <vector>

using namespace std;
const int MX = 100'001;
int n, m, x, w;
int p[MX];
int score[MX];
vector<int> child[MX];

void dfs(int cur) {
    if(p[cur] != -1)
        score[cur] += score[p[cur]];
    for(int nxt: child[cur])
        dfs(nxt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        if(p[i] == -1) continue;
        child[p[i]].push_back(i);
    }
    while(m--) {
        cin >> x >> w;
        score[x] += w;
    }
    dfs(1);
    for(int i = 1; i <= n; i++)
        cout << score[i] << ' ';
    
    return 0;
}
