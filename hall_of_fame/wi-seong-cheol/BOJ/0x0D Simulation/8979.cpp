//
//  8979.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 3/6/24.
//

/*
 [Input]
 4 3
 1 1 2 0
 2 0 1 0
 3 0 1 0
 4 0 0 1
 [Output]
 2
 */
// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: Silver 5
// Timer: 9m
// Url: https://www.acmicpc.net/problem/8979

#include <iostream>

using namespace std;
struct Nation {
    int g, s, b;
};
int n, m;
Nation v[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int idx, g, s, b;
        cin >> idx >> g >> s >> b;
        v[idx] = {g, s, b};
    }

    int rank = 1;
    for(int i = 1; i <= n; i++) {
        if(i == m) continue;
        if(v[i].g == v[m].g) {
            if(v[i].s == v[m].s) {
                if(v[i].b > v[m].b) {
                    rank++;
                }
            } else {
                if(v[i].s > v[m].s) rank++;
            }
        } else {
            if(v[i].g > v[m].g) rank++;
        }
    }
    cout << rank;

	return 0;
}
