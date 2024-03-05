//
//  7568.cpp
//  main
//
//  Created by wi_seong on 3/5/24.
//

/*
 [Input]
 5
 55 185
 58 183
 88 186
 60 175
 46 155
 [Output]
 2 2 1 2 5
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 2,500
// 난이도: Silver 5
// Timer: 5m
// Url: https://www.acmicpc.net/problem/7568

#include <iostream>
#include <vector>

using namespace std;
int n;
vector<pair<int, int>> p;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }

    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(p[i].first < p[j].first && p[i].second < p[j].second)
                cnt++;
        }
        cout << cnt + 1 << ' ';
    }

	return 0;
}
