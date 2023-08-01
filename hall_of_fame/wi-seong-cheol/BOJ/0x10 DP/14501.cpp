//
//  14501.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 7
 3 10
 5 20
 1 10
 1 20
 2 15
 4 40
 2 200
 [Output]
 45
 */
// 시간복잡도: O(n)
// 최악시간: 15
// 난이도: Silver 3
// Timer: 15m
// Url: https://www.acmicpc.net/problem/14501

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int t[16];
int p[16];
int d[16];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> t[i] >> p[i];
    for(int i = 0; i < n; i++) {
        d[i] = max(d[i], d[i - 1]);
        if(i + t[i] <= n + 1)
            d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
    }
    cout << *max_element(d, d + n + 1);
    
    return 0;
}
