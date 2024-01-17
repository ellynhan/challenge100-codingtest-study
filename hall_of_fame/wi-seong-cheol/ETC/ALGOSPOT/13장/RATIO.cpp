//
//  RATIO.cpp
//  main
//
//  Created by wi_seong on 1/17/24.
//

/*
 [Input]
 5
 10 8
 100 80
 47 47
 99000 0
 1000000000 470000000
 [Output]
 1
 6
 -1
 1000
 19230770
 */
// 시간복잡도: O(100logn)
// 최악시간: 200
// 난이도: 하
// Timer: 20m
// Url: https://algospot.com/judge/problem/read/RATIO

#include <iostream>

using namespace std;
#define ll long long
ll L = 2e9;
int t, n, m, z;

int winRatio(ll win, ll total) {
    return int((win * 100) / total);
}

int solve(ll win, ll total) {
    if(z == winRatio(win + L, total + L))
        return -1;
    ll lo = 0, hi = L;

    for(int i = 0; i < 100; i++) {
        ll mid = (lo + hi) / 2;
        if(winRatio(m + mid, n + mid) <= z)
            lo = mid;
        else
            hi = mid;
    }

    return int(hi);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        z = winRatio(m, n);
        cout << solve(m, n) << '\n';
    }

	return 0;
}
