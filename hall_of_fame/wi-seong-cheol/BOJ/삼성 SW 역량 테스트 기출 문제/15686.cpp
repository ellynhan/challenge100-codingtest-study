//
//  15686.cpp
//  main
//
//  Created by wi_seong on 3/7/24.
//

/*
 [Input]
 5 3
 0 0 1 0 0
 0 0 2 0 1
 0 1 2 0 0
 0 0 1 0 0
 0 0 0 0 2
 [Output]
 5
 */
// 시간복잡도: O(2 ^ n)
// 최악시간: 8,192
// 난이도: Gold 5
// Timer: 19m
// Url: https://www.acmicpc.net/problem/15686

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 0x7f7f7f7f;
struct Point {
    int x, y;
};
int n, m;
vector<Point> chicken;
vector<Point> house;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x; cin >> x;
            if(x == 1) house.push_back({i, j});
            if(x == 2) chicken.push_back({i, j});
        }
    }

    int sz = int(chicken.size());
    vector<int> v(sz);
    fill(v.begin() + sz - m, v.end(), 1);

    int answer = INF;
    do {
        vector<int> idx;
        for(int i = 0; i < sz; i++) {
            if(v[i]) idx.push_back(i);
        }

        int sum = 0;
        for(auto h: house) {
            int dist = INF;
            for(auto i: idx) {
                dist = min(dist, abs(h.x - chicken[i].x) + abs(h.y - chicken[i].y));
            }
            sum += dist;
        }
        answer = min(answer, sum);
    } while(next_permutation(v.begin(), v.end()));
    cout << answer;

	return 0;
}
