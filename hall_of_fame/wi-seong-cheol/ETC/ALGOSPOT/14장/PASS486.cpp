//
//  PASS486.cpp
//  main
//
//  Created by wi_seong on 1/17/24.
//

/*
 [Input]
 3
 2 2 10
 12 486 486
 200 1000000 2000000
 [Output]
 4
 1
 19
 */
// 시간복잡도: O(nlogn)
// 최악시간: 70,000,000
// 난이도: 중
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/PASS486

#include <iostream>
#include <cstring>

using namespace std;
const int MXN = 10000000;
int t, n, lo, hi;
int factor[MXN + 1];

void getFactorBrute() {
    memset(factor, 0, sizeof(factor));
    for(int div = 1; div <= MXN; div++) {
        for(int multiple = div; multiple <= MXN; multiple += div)
            factor[multiple]++;
    }
}

int solve() {
    int cnt = 0;

    for(int i = lo; i <= hi; i++) {
        if(factor[i] == n) cnt++;
    }

    return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    getFactorBrute();
    cin >> t;
    while(t--) {
        cin >> n >> lo >> hi;
        cout << solve() << "\n";
    }

	return 0;
}
