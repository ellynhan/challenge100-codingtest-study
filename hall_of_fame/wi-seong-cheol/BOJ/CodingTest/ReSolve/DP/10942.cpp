//
//  10942.cpp
//  main
//
//  Created by wi_seong on 3/14/24.
//

/*
 [Input]
 7
 1 2 1 3 1 2 1
 4
 1 3
 2 5
 3 3
 5 7
 [Output]
 1
 0
 1
 1
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 4,000,000
// 난이도: Gold 4
// Timer: 5m
// Url: https://www.acmicpc.net/problem/10942

#include <iostream>
#include <cstring>

using namespace std;
int n, m;
int st, en;
int arr[2001];
int cache[2001][2001];

int solve(int s, int e) {
    if(s == e) return 1;
    if(s + 1 == e) return arr[s] == arr[e];
    int& ret = cache[s][e];
    if(ret != -1) return ret;

    if(arr[s] != arr[e]) return ret = 0;

    return ret = solve(s + 1, e - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    memset(cache, -1, sizeof(cache));
    cin >> m;
    while(m--) {
        cin >> st >> en;
        cout << solve(--st, --en) << '\n';
    }

	return 0;
}
