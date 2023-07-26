//
//  15787.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/11.
//

/*
 [Input]
 5 5
 1 1 1
 1 1 2
 1 2 2
 1 2 3
 3 1
 [Output]
 2
 */
// 시간복잡도: O(100,000)
// 최악시간: n
// 난이도: Silver 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/15787

#include <iostream>
#include <vector>

using namespace std;
int n, m, op, idx, x, ans;
vector<int> a(100001);
vector<bool> vis(1 << 21);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(m--) {
        cin >> op >> idx;
        if(op <= 2) cin >> x;
        if(op == 1) {
            a[idx] |= (1 << x);
        } else if(op == 2) {
            a[idx] &= ~(1 << x);
        } else if(op == 3) {
            a[idx] = a[idx] << 1;
            a[idx] &= ((1 << 21) - 1);
        } else {
            a[idx] = a[idx] >> 1;
            a[idx] &= ~1;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[a[i]])
            ans++;
        vis[a[i]] = true;
    }
    cout << ans;
    
    return 0;
}
