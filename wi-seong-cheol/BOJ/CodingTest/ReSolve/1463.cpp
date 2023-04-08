//
//  1463.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 2
 [Output]
 1
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Silver 3
// Timer: 5m
// Url: https://www.acmicpc.net/problem/1463

#include <iostream>
#include <algorithm>

using namespace std;
const int SIZE = 1000001;
const int INF = 0x7f7f7f7f;
int n;
int d[SIZE];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    fill(d, d + n + 1, INF);
    d[1] = 0;
    for(int i = 1; i <= n; i++) {
        d[i + 1] = min(d[i + 1], d[i] + 1);
        if(i * 2 > SIZE) continue;
        d[i * 2] = min(d[i * 2], d[i] + 1);
        if(i * 3 > SIZE) continue;
        d[i * 3] = min(d[i * 3], d[i] + 1);
    }
    cout << d[n];
    
    return 0;
}
