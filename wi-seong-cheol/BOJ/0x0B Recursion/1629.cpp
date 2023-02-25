//
//  1629.cpp
//  main
//
//  Created by wi_seong on 2022/11/21.
//

/*
 [Input]
 10 11 12
 [Output]
 4
 */
// 시간복잡도: O(logN)
// 최악시간: 9.33
// 난이도: Silver 1
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1629

#include <iostream>

using namespace std;
#define ll long long

ll POW(ll a, ll b, ll c) {
    if(b == 1) return a % c;
    ll val = POW(a, b/2, c);
    val = val * val % c;
    if(b%2 == 0) return val;
    return val * a % c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll a, b, c;
    cin >> a >> b >> c;
    cout << POW(a, b, c);
    
    return 0;
}
