//
//  SNAIL.cpp
//  main
//
//  Created by wi_seong on 1/11/24.
//

/*
 [Input]
 4
 5 4
 5 3
 4 2
 3 2
 [Output]
 0.99609375
 0.84375
 0.5625
 0.9375
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: 하
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/SNAIL

#include <iostream>

using namespace std;
#define ll long long
int t, n, m;
double cache[1001][2001];

void init() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2 * m; j++)
            cache[i][j] = -1;
}

double climb(int days, int climbed) {
    if(days == m) return (climbed >= n ? 1 : 0);
    double &ret = cache[days][climbed];
    if(ret != -1) return ret;
    return ret = climb(days + 1, climbed + 1) * 0.25 + climb(days + 1, climbed + 2) * 0.75;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.precision(10);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        init();
        cout << climb(0, 0) << '\n';
    }

	return 0;
}
