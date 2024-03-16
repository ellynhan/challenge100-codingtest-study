//
//  18110.cpp
//  main
//
//  Created by wi_seong on 3/15/24.
//

/*
 [Input]
 0
 [Output]
 0
 */
// 시간복잡도: O(nlogn)
// 최악시간: 1,500,000
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/18110

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
double n;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    if(n == 0) {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int k = (0.15 * n + 0.5);
    double sum = 0;
    for(int i = k; i < n - k; i++) {
        sum += v[i];
    }
    cout << (int)(sum / double(n - 2 * k) + 0.5);

	return 0;
}
