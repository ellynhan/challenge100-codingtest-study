//
//  1946.cpp
//  main
//
//  Created by wi_seong on 3/7/24.
//

/*
 [Input]
 2
 5
 3 2
 1 4
 4 1
 2 3
 5 5
 7
 3 6
 7 3
 4 2
 1 4
 5 7
 2 5
 6 1
 [Output]
 4
 3
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1946

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());

        int answer = 0;
        int prev = v[0].second;

        for(int i = 1; i < n; i++) {
            if(prev <= v[i].second) {
                answer++;
            } else {
                prev = v[i].second;
            }
        }
        cout << n - answer << '\n';
    }

	return 0;
}
