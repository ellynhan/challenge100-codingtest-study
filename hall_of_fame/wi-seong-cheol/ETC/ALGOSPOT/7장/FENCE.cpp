//
//  FENCE.cpp
//  main
//
//  Created by wi_seong on 1/12/24.
//

/*
 [Input]
 3
 7
 7 1 5 9 6 7 3
 7
 1 4 4 4 4 1 1
 4
 1 8 2 2
 [Output]
 20
 16
 8
 */
// 시간복잡도: O(n)
// 최악시간: 20,000
// 난이도: 중
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/FENCE

#include <iostream>
#include <algorithm>

using namespace std;
int t, n;
int h[20001];

int solve(int left, int right) {
    if(left == right) return h[left];

    int mid = (left + right) / 2;

    int ret = max(solve(left, mid), solve(mid + 1, right));

    int lo = mid, hi = mid + 1;
    int height = min(h[lo], h[hi]);
    ret = max(ret, height * 2);

    while(left < lo || hi < right) {
        if(hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
            hi++;
            height = min(height, h[hi]);
        } else {
            lo--;
            height = min(height, h[lo]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> h[i];
        cout << solve(0, n - 1) << '\n';
    }

	return 0;
}
