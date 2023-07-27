//
//  2828.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/06.
//

/*
 [Input]
 5 1
 3
 1
 5
 3
 [Output]
 6
 */
// 시간복잡도: O(n)
// 최악시간: 20
// 난이도: Silver 5
// Timer: 10m
// Url: https://www.acmicpc.net/problem/2828

#include <iostream>
#include <algorithm>

using namespace std;
int ans;
int n, m, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    int cur = 1;
    while(k--) {
        int pos; cin >> pos;
        if(cur <= pos && pos <= cur + m - 1) continue;
        int move = min(abs(cur - pos), abs(cur + m - 1 - pos));
        if(pos < cur) cur -= move;
        else cur += move;
        ans += move;
    }
    cout << ans;
    
    return 0;
}
