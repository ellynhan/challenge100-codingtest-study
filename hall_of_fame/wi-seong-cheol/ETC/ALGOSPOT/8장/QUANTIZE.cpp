//
//  QUANTIZE.cpp
//  main
//
//  Created by wi_seong on 1/11/24.
//

/*
 [Input]
 2
 10 3
 3 3 3 1 2  3 2 2 2 1
 9 3
 1 744 755 4 897 902 890 6 777
 [Output]
 0
 651
 */
// 시간복잡도: O(n ^ 2 * s)
// 최악시간: 100,000
// 난이도: 중
// Timer: 1h
// Url: https://www.algospot.com/judge/problem/read/QUANTIZE

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
#define INF 987654321
int t, n, s;
int a[101];
int cache[101][11];
int pSum[101], pSqSum[101];

void init() {
    memset(a, 0, sizeof(a));
    memset(cache, -1, sizeof(cache));
    memset(pSum, 0, sizeof(pSum));
    memset(pSqSum, 0, sizeof(pSqSum));
}

void precalc() {
    sort(a, a + n);
    pSum[0] = a[0];
    pSqSum[0] = a[0] * a[0];
    for(int i = 1; i < n; i++) {
        pSum[i] = pSum[i - 1] + a[i];
        pSqSum[i] = pSqSum[i - 1] + a[i] * a[i];
    }
}

int calculate(int lo, int hi) {
    int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
    int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);

    int m = int(0.5 + (double)sum / (hi - lo + 1));

    int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);

    return ret;
}

int quantize(int st, int parts) {    // st: 시작점, cnt: 구간의 개수
    if(st == n) return 0;
    if(parts == 0) return INF;
    int &ret = cache[st][parts];
    if(ret != -1) return ret;

    ret = INF;
    for(int partsSize = 1; partsSize + st <= n; partsSize++) {
        ret = min(ret, calculate(st, st + partsSize - 1) + quantize(st + partsSize, parts - 1));
    }

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        init();
        cin >> n >> s;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        precalc();
        cout << quantize(0, s) << '\n';
    }

	return 0;
}
