//
//  15810.cpp
//  main
//
//  Created by wi_seong on 2023/02/09.
//

/*
 [Input]
 3 8
 5 7 3
 [Output]
 14
 */
// 시간복잡도: O(logn)
// 최악시간: 12
// 난이도: Silver 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/15810

#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
const int MX = 1'000'000;
int n, m, cnt, mn;
int a[MX + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    ll st = 1, en = 1'000'000'000'001;
    while(st + 1 < en) {
        ll mid = (st + en) / 2;
        ll cnt = 0;
        for(int i = 0; i < n; i++)
            cnt += mid / a[i];
        if(cnt < m) st = mid;
        else en = mid;
    }
    cout << en;
    
    return 0;
}
