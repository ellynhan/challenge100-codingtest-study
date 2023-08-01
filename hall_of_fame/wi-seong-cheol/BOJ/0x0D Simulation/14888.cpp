//
//  14888.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 3
 3 4 5
 1 0 1 0
 [Output]
 35
 17
 */
// 시간복잡도: O(2^n)
// 최악시간: 2,048
// 난이도: Silver 1
// Timer: 20m
// Url: https://www.acmicpc.net/problem/14888

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int a[12];
int op[4];
int mx = -0x7f7f7f7f;
int mn = 0x7f7f7f7f;

void func(int ans, int k) {
    if(k == n) {
        mx = max(mx, ans);
        mn = min(mn, ans);
        return;
    }
    for(int i = 0; i < 4; i++) {
        if(op[i] == 0) continue;
        op[i]--;
        if(i == 0) func(ans + a[k], k + 1);
        else if(i == 1) func(ans - a[k], k + 1);
        else if(i == 2) func(ans * a[k], k + 1);
        else func(ans / a[k], k + 1);
        op[i]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < 4; i++)
        cin >> op[i];
    func(a[0], 1);
    cout << mx << '\n' << mn;
    
    return 0;
}
