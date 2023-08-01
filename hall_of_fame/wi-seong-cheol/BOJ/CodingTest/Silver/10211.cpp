//
//  10211.cpp
//  main
//
//  Created by wi_seong on 2023/02/09.
//

/*
 [Input]
 2
 5
 1 2 3 4 5
 5
 2 1 -2 3 -5
 [Output]
 15
 4
 */
// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: Silver 4
// Timer: 20m
// Url: https://www.acmicpc.net/problem/10211

#include <iostream>
#include <algorithm>

using namespace std;
int t, n;
int a[1001];
int d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        cin >> n;
        fill(d, d + n, 0);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            d[i] = a[i];
        }
        for(int i = 0; i < n; i++)
            d[i] = max(d[i], a[i] + d[i - 1]);
        cout << *max_element(d, d + n) << '\n';
    }
    
    return 0;
}
