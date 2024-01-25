//
//  CANADATRIP.cpp
//  main
//
//  Created by wi_seong on 1/16/24.
//

/*
 [Input]
 2
 3 15
 500 100 10
 504 16 4
 510 60 6
 2 1234567
 8030000 8030000 1
 2 2 1
 [Output]
 480
 1234563
 */
// 시간복잡도: O(nlogn)
// 최악시간: 10,000
// 난이도: 중
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/CANADATRIP

#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 5001;
int t, n, m;
int L[MAXN], M[MAXN], G[MAXN];

bool decision(int pos) {
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        if(pos < L[i] - M[i]) continue;
        cnt += (min(pos, L[i]) - (L[i] - M[i])) / G[i] + 1;
    }

    return cnt >= m;
}

int optimize(int mx) {
    int lo = 0, hi = mx;

    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if(decision(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    return hi;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        int mx = 0;
        for(int i = 0; i < n; i++) {
            cin >> L[i] >> M[i] >> G[i];
            mx = max(mx, L[i]);
        }
        cout << optimize(mx) << '\n';
    }

	return 0;
}
