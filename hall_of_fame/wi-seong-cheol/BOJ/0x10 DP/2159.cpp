//
//  2159.cpp
//  main
//
//  Created by wi_seong on 1/4/24.
//

/*
 [Input]
 3
 2 2
 3 6
 6 7
 7 3
 [Output]
 11
 */
// 시간복잡도: O(n)
// 최악시간: 500,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2159

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
#define X first
#define Y second
#define INF 0x3f3f3f3f3f3f3f3fLL
#define ll long long
int n;
pair<ll, ll> arr[100001];
ll dp[100001][5];
int dx[] = {0, 0, 1, 0, -1};
int dy[] = {0, 1, 0, -1, 0};

ll dist(ll a, ll b, ll x, ll y) {
    return abs(a - x) + abs(b - y);
}

ll solve(int cnt, int d, ll x, ll y) {
    if(cnt == n) return 0;
    ll &ret = dp[cnt][d];
    if(ret != -1) return ret;

    ret = INF;
    for(int dir = 0; dir < 5; dir++) {
        ll nx = arr[cnt + 1].X + dx[dir];
        ll ny = arr[cnt + 1].Y + dy[dir];
        ret = min(ret, dist(x, y, nx, ny) + solve(cnt + 1, dir, nx, ny));
    }
    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n + 1; i++)
        cin >> arr[i].X >> arr[i].Y;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, arr[0].X, arr[0].Y);

	return 0;
}
