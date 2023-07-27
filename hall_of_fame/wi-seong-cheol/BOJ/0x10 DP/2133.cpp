//
//  2133.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 2
 [Output]
 3
 */
// 시간복잡도: O(n^2)
// 최악시간: 900
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2133

#include <iostream>

using namespace std;
int n;
int d[31];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[0] = 1;
    for(int i = 2; i <= n; i++) {
        d[i] = d[i - 2] * 3;
        for(int j = i - 4; j >= 0; j -= 2)
            d[i] += d[j] * 2;
    }
    cout << d[n];
    
    return 0;
}
