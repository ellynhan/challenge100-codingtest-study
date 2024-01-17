//
//  JLIS.cpp
//  main
//
//  Created by wi_seong on 1/10/24.
//

/*
 [Input]
 3
 3 3
 1 2 4
 3 4 7
 3 3
 1 2 3
 4 5 6
 5 3
 10 20 30 1 2
 10 20 30
 [Output]
 5
 6
 5
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 1,000,000
// 난이도: 하
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/JLIS

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
const long long NEGINF = numeric_limits<long long>::min();
int t, n, m, x;
int a[101], b[101];
int cache[101][101];

int jlis(int idx1, int idx2) {
    int &ret = cache[idx1 + 1][idx2 + 1];
    if(ret != -1) return ret;

    ret = 0;
    ll valA = (idx1 == -1 ? NEGINF : a[idx1]);
    ll valB = (idx2 == -1 ? NEGINF : b[idx2]);
    ll maxElement = max(valA, valB);

    for(int nextA = idx1 + 1; nextA < n; nextA++) {
        if(maxElement < a[nextA])
            ret = max(ret, jlis(nextA, idx2) + 1);
    }
    for(int nextB = idx2 + 1; nextB < m; nextB++) {
        if(maxElement < b[nextB])
            ret = max(ret, jlis(idx1, nextB) + 1);
    }

    return ret;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        memset(cache, -1, sizeof(cache));

        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];

        cout << jlis(-1, -1) << '\n';
    }

	return 0;
}
