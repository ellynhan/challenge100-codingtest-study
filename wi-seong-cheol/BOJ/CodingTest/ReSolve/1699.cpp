//
//  1699.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 13
 [Output]
 2
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 2
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1699

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int d[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        d[i] = i;
        for(int j = 1; j*j <= i; j++)
            d[i] = min(d[i], d[i - j * j] + 1);
    }
    cout << d[n];
    
    return 0;
}
