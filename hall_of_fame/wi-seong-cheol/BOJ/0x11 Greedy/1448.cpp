//
//  1448.cpp
//  main
//
//  Created by wi_seong on 3/11/24.
//

/*
 [Input]
 3
 1
 2
 2
 [Output]
 5
 */
// 시간복잡도: O(nlogn)
// 최악시간: 6,000,000
// 난이도: Silver 3
// Timer: 3m
// Url: https://www.acmicpc.net/problem/1448

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int i = 0; i < n - 2; i ++) {
        if(v[i] < v[i + 1] + v[i + 2]) {
            cout << v[i] + v[i + 1] + v[i + 2];
            return 0;
        }
    }
    cout << -1;

	return 0;
}
