//
//  4097.cpp
//  main
//
//  Created by wi_seong on 2023/02/11.
//

/*
 [Input]
 6
 -3
 4
 9
 -2
 -5
 8
 2
 -1000
 -19
 0
 [Output]
 14
 -19
 */
// 시간복잡도: O(n)
// 최악시간: 250,000
// 난이도: Silver 2
// Timer: 10m
// Url: https://www.acmicpc.net/problem/4097

#include <iostream>
#include <algorithm>

using namespace std;
int t, n;
int a[250001];
int d[250001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            d[i] = a[i];
        }
        for(int i = 0; i < n; i++)
            d[i] = max(d[i], d[i - 1] + a[i]);
        cout << *max_element(d, d + n) << '\n';
    }
    
    return 0;
}
