//
//  12019.cpp
//  main
//
//  Created by wi_seong on 1/10/24.
//

/*
 [Input]
 8 2
 5 8 6 10 1 15 3 9
 [Output]
 3 6
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 100,000
// 난이도: Gold 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/12019

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
#define INF 987654321
int n, m;
int a[101];
int d[101][11][101];

int solve(int cur, int cnt, int prev, int sum) {
    int &ret = d[cur][cnt][prev];
    if(ret != -1) return ret;
    if(cur == n) return ret = sum * a[cur];
    ret = INF;

    if(cnt) ret = min(ret, solve(cur + 1, cnt - 1, cur, 0));
    ret = min(ret, solve(cur + 1, cnt, prev, sum + a[cur]));

    return ret += a[cur] * sum;
}

void trace() {
    int cnt = m;
    int prev = 0;

    for(int i = 1; i < n; i++) {
        if(!cnt) break;
        int a = d[i + 1][cnt][prev];
        int b = d[i + 1][cnt - 1][i];

        if(a >= b) {
            prev = i;
            cnt--;
            cout << i << ' ';
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    memset(d, -1, sizeof(d));
    cout << solve(1, m, 0, 0) << '\n';
    trace();

	return 0;
}
