//
//  14464.cpp
//  main
//
//  Created by wi_seong on 1/22/24.
//

/*
 [Input]
 5 4
 7
 8
 6
 2
 9
 2 5
 4 9
 0 3
 8 13
 [Output]
 3
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 400,000,000
// 난이도: Gold 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/14464

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int c, n;
int check[20005];
vector<int> chicken;
vector<pair<int, int>> cow;

int solve() {
    int cnt = 0;

    for(int i = 0; i < c; i++) {
        for(int j = 0; j < n; j++) {
            if(check[j]) continue;
            if(cow[j].Y <= chicken[i] && chicken[i] <= cow[j].X) {
                cnt++;
                check[j] = 1;
                break;
            }
        }
    }

    return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> c >> n;
    chicken.resize(c);
    cow.resize(n);
    for(int i = 0; i < c; i++) cin >> chicken[i];
    for(int i = 0; i < n; i++) cin >> cow[i].Y >> cow[i].X;
    sort(chicken.begin(), chicken.end());
    sort(cow.begin(), cow.end());
    cout << solve();

	return 0;
}
