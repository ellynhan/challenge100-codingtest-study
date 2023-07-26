//
//  9934.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/10.
//

/*
 [Input]
 3
 1 6 4 3 5 2 7
 [Output]
 3
 6 2
 1 4 5 7
 */
// 시간복잡도: O(nlogn)
// 최악시간: 10,240
// 난이도: Silver 1
// Timer: 40m
// Url: https://www.acmicpc.net/problem/9934

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int n, k;
int a[1025];
vector<int> tree[10];

void solve(int s, int e, int depth) {
    if(depth == k) return;
    if(s == e) {
        tree[depth].push_back(a[s]);
        return;
    }
    
    int m = (s + e) / 2;
    if(m < 0 || m >= n) return;
    
    tree[depth].push_back(a[m]);
    solve(s, m - 1, depth + 1);
    solve(m + 1, e, depth + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k;
    n = pow(2, k) - 1;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    solve(0, n - 1, 0);
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < tree[i].size(); j++)
            cout << tree[i][j] << ' ';
        cout << '\n';
    }
    
    return 0;
}
