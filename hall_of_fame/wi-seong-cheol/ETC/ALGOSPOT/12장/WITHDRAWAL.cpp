//
//  WITHDRAWAL.cpp
//  main
//
//  Created by wi_seong on 1/17/24.
//

/*
 [Input]
 3
 3 2
 1 4 6 10 10 17
 4 2
 4 8 9 12 3 10 2 5
 10 5
 70 180 192 192 1 20 10 200 6 102 60 1000 4 9 1 12 8 127 100 700
 [Output]
 0.5000000000
 0.3333333333
 0.0563991323
 */
// 시간복잡도: O(nlogn)
// 최악시간: 3,000
// 난이도: 상
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/WITHDRAWAL

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t, n, k;
int r[1001], c[1001];

bool decision(double average) {
    vector<double> v;

    for(int i = 0; i < n; i++)
        v.push_back(average * c[i] - r[i]);
    sort(v.begin(), v.end());
    double sum = 0;
    for(int i = n - k; i < n; i++)
        sum += v[i];

    return sum >= 0;
}

double solve() {
    double lo = -1e-9, hi = 1.0;

    for(int i = 0; i < 100; i++) {
        double mid = (lo + hi) / 2;
        if(decision(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    return hi;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.precision(10);
    cout << fixed;

    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            cin >> r[i] >> c[i];
        }
        cout << solve() << endl;
    }

	return 0;
}
