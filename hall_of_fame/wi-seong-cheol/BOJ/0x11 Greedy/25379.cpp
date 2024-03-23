//
//  25379.cpp
//  main
//
//  Created by wi_seong on 3/17/24.
//

/*
 [Input]
 4
 4 5 1 0
 [Output]
 2
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Silver 4
// Timer: 20m
// Url: https://www.acmicpc.net/problem/25379

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int n;
ll cnt[2], pre[2];
ll a[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++) {
        if(a[i] % 2 == 0) {
            pre[0]++;
            cnt[0] += pre[1];
        } else {
            pre[1]++;
            cnt[1] += pre[0];
        }
    }

    cout << min(cnt[0], cnt[1]);

	return 0;
}
