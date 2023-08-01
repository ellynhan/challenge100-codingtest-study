//
//  21940.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4 9
 1 2 9
 2 3 9
 3 1 9
 1 4 1
 4 1 1
 2 4 1
 4 2 1
 3 4 1
 4 3 1
 3
 1 2 3
 [Output]
 4
 */
// 시간복잡도: O(n^3)
// 최악시간: 8,000,000
// 난이도: Gold 4
// Timer: 40m
// Url: https://www.acmicpc.net/problem/21940

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, K;
int a, b, c;
int f[201];
int d[201][201];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        fill(d[i] + 1, d[i] + n + 1, INF);
        d[i][i] = 0;
    }
    while(m--) {
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }
    cin >> K;
    for(int i = 1; i <= K; i++)
        cin >> f[i];
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        int mx = 0;
        for(int j = 1; j <= K; j++)
            mx = max(mx, d[i][f[j]] + d[f[j]][i]);
        ans.push_back(mx);
    }
    int mn = *min_element(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
        if(ans[i] == mn) cout << i + 1 << ' ';
    
    return 0;
}
