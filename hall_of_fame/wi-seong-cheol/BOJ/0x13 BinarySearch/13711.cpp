//
//  13711.cpp
//  main
//
//  Created by wi_seong on 1/9/24.
//

/*
 [Input]
 5
 1 3 5 2 4
 5 3 2 4 1
 [Output]
 3
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Platinum 5
// Timer: 20m
// Url: https://www.acmicpc.net/problem/13711

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n;
int idx[100001];
vector<int> a;
vector<pair<int, int>> element;
vector<int> lcs;

void solve() {
    for(int i = 0; i < n; i++) {
        if(lcs.empty() || lcs.back () < element[i].Y) {
            lcs.push_back(element[i].Y);
        } else {
            *lower_bound(lcs.begin(), lcs.end(), element[i].Y) = element[i].Y;
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
        idx[x] = i;
    }
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        int pos = idx[x];
        element.push_back({x, pos});
    }

    solve();

    cout << lcs.size();

	return 0;
}
