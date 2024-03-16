//
//  9084.cpp
//  main
//
//  Created by wi_seong on 3/14/24.
//

/*
 [Input]
 3
 2
 1 2
 1000
 3
 1 5 10
 100
 2
 5 7
 22
 [Output]
 501
 121
 1
 */
// 시간복잡도: O(n * m)
// 최악시간: 200,000
// 난이도: Gold 5
// Timer: 20m
// Url: https://www.acmicpc.net/problem/9084

#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
int n, m;
int a[21];
ll cache[21][10001];

ll solve(int k, int coin) {
    if(coin == 0) return 1;
    if(k == n) return 0;
    ll& ret = cache[k][coin];
    if(ret != -1) return ret;
    ret = 0;

    for(int i = 0; a[k] * i <= coin; i++) {
        ret += solve(k + 1, coin - a[k] * i);
    }

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> m;
        memset(cache, -1, sizeof(cache));
        cout << solve(0, m) << '\n';
    }

	return 0;
}
