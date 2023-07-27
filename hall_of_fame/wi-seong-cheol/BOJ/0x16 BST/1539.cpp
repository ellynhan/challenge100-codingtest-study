//
//  1539.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 10
 9
 1
 4
 3
 2
 5
 6
 7
 8
 0
 [Output]
 40
 */
// 시간복잡도: O(nlogn)
// 최악시간: 1,250,000
// 난이도: Platinum 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1539

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
#define ll long long
ll ans;
int n, x;
map<int, int> h1, h2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        auto l = h1.lower_bound(x);
        auto r = h2.lower_bound(-x);
        int m = 0;
        if(l != h1.end()) m = max(m, l -> second);
        if(r != h2.end()) m = max(m, r -> second);
        h1[x] = h2[-x] = 1 + m;
        ans += 1LL + m;
    }
    cout << ans;
    
    return 0;
}
