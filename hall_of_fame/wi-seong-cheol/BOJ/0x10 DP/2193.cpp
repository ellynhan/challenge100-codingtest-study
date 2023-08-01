//
//  2193.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 3
 [Output]
 2
 */
// 시간복잡도: O(n)
// 최악시간: 90
// 난이도: Silver 3
// Timer: 5m
// Url: https://www.acmicpc.net/problem/2193

#include <iostream>

using namespace std;
#define ll long long
int n;
ll d[91];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1] = 1;
    d[2] = 1;
    for(int i = 3; i <= n; i++)
        d[i] = d[i - 1] + d[i - 2];
    cout << d[n];
    return 0;
}
