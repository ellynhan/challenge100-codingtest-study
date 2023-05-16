//
//  18222.cpp
//  main
//
//  Created by wi_seong on 2023/02/28.
//

/*
 [Input]
 10
 [Output]
 0
 */
// 시간복잡도: O(logn)
// 최악시간: 18
// 난이도: Silver 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/18222

#include <iostream>

using namespace std;
#define ll long long
ll n;

ll func(ll x) {
    if(x == 1) return 0;
    ll i;
    for(i = 1; i + i < x; i += i);
    return !func(x-i);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    cout << func(n);
    
    return 0;
}
