//
//  11561.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/16.
//

/*
 [Input]
 4
 1
 2
 100
 1000000
 [Output]
 1
 1
 13
 1413
 */
// 시간복잡도: O(Tlogn)
// 최악시간: 16 * T
// 난이도: Silver 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/11561

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define ull unsigned long long
ull t, n;

ull binary_search(ull x) {
    ull ret = 0;
    
    ull st = 1;
    ull en = sqrt(x) * 2;
    while(st <= en) {
        ull mid = (en + st) / 2;
        if(mid * (mid + 1) <= 2 * n) {
            ret = max(ret, mid);
            st = mid + 1;
        } else {
            en = mid - 1;
        }
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        cin >> n;
        cout << binary_search(n) << '\n';
    }
    
    return 0;
}
