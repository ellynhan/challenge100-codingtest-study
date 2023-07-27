//
//  1654.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4 11
 802
 743
 457
 539
 [Output]
 200
 */
// 시간복잡도: O(nlogn)
// 최악시간: 4,000
// 난이도: Silver 2
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1654

#include <iostream>

using namespace std;
#define ll long long
int k, n;
int a[10001];

bool solve(ll x) {
    ll cur = 0;
    for(int i = 0; i < k; i++)
        cur += a[i] / x;
    return cur >= n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k >> n;
    for(int i = 0; i < k; i++)
        cin >> a[i];
    ll st = 1;
    ll en = 0x7fffffff;
    while(st < en) {
        ll mid = (st + en + 1) / 2;
        if(solve(mid)) st = mid;
        else en = mid - 1;
    }
    cout << st;
    
    return 0;
}
