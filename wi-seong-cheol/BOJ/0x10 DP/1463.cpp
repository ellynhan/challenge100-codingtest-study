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
// Timer: 6m
// Url: https://www.acmicpc.net/problem/1463

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int d[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 2; i <= n; i++) {
        d[i] = d[i - 1] + 1;
        if(i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
        if(i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
    }
    cout << d[n];
    
    return 0;
}
