//
//  LUNCHBOX.cpp
//  main
//
//  Created by wi_seong on 1/15/24.
//

/*
 [Input]
 2
 3
 2 2 2
 2 2 2
 3
 1 2 3
 1 2 1
 [Output]
 8
 7
 */
// 시간복잡도: O(nlogn)
// 최악시간: 40,000
// 난이도: 하
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/LUNCHBOX

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define X first
#define Y second
const int SIZE = 10001;
int t, n;
int e[SIZE], m[SIZE];

int heat() {
    vector<pair<int, int>> order;
    for(int i = 0; i < n; i++) {
        order.push_back(make_pair(-e[i], i));
    }
    sort(order.begin(), order.end());

    int ret = 0;
    int t = 0;
    for(int i = 0; i < n; i++) {
        int box = order[i].Y;
        t += m[box];
        ret = max(ret, t + e[box]);
    }
    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> m[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> e[i];
        }

        cout << heat() << endl;
    }

	return 0;
}
