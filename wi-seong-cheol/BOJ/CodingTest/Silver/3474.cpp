//
//  3474.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/08.
//

/*
 [Input]
 6
 3
 60
 100
 1024
 23456
 8735373
 [Output]
 0
 14
 24
 253
 5861
 2183837
 */
// 시간복잡도: O(logn)
// 최악시간: 9
// 난이도: Silver 3
// Timer: 40m
// Url: https://www.acmicpc.net/problem/3474

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define ll long long
int t, n, cnt2, cnt5;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        cnt2 = cnt5 = 0;
        cin >> n;
        for(int j = 1; ; j++) {
            if((ll)pow(2, j) <= n)
                cnt2 += n / (ll)pow(2, j);
            else break;
        }
        for(int j = 1; ; j++) {
            if((long long)pow(5, j) <= n)
                cnt5 += n / (ll)pow(5, j);
            else break;
        }
        cout << min(cnt2, cnt5) << '\n';
    }
    
    return 0;
}
