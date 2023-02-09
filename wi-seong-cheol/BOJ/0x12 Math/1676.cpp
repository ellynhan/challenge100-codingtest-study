//
//  1676.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 10
 [Output]
 2
 */
// 시간복잡도: O(nlog5)
// 최악시간: 350
// 난이도: Silver 5
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1676

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    int ans = 0;
    while(n) {
        ans += n / 5;
        n /= 5;
    }
    cout << ans;
    
    return 0;
}
