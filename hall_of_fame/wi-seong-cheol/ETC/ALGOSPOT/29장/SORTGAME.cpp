//
//  SORTGAME.cpp
//  main
//
//  Created by wi_seong on 1/25/24.
//

/*
 [Input]
 3
 8
 1 2 3 4 8 7 6 5
 4
 3 4 1 2
 3
 1 2 3
 [Output]
 1
 2
 0
 */
// 시간복잡도: O(n!)
// 최악시간: 40320
// 난이도: 중
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/SORTGAME

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
int t, n;
map<vector<int>, int> toSort;

void precalc(int n) {
    vector<int> perm(n);
    for(int i = 0; i < n; i++) {
        perm[i] = i;
    }
    queue<vector<int>> q;
    q.push(perm);
    toSort[perm] = 0;

    while(!q.empty()) {
        vector<int> here = q.front();
        q.pop();
        int cost = toSort[here];
        for(int i = 0; i < n; i++) {
            for(int j = i + 2; j <= n; j++) {
                reverse(here.begin() + i, here.begin() + j);
                if(toSort.count(here) == 0) {
                    toSort[here] = cost + 1;
                    q.push(here);
                }
                reverse(here.begin() + i, here.begin() + j);
            }
        }
    }
}

int solve(const vector<int>& perm) {
    int n = int(perm.size());
    vector<int> fixed(n);
    for(int i = 0; i < n; i++) {
        int smaller = 0;
        for(int j = 0; j < n; j++) {
            if(perm[j] < perm[i]) {
                ++smaller;
            }
        }
        fixed[i] = smaller;
    }
    return toSort[fixed];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        precalc(n);
        vector<int> perm(n);
        for(int i = 0; i < n; i++) {
            cin >> perm[i];
        }

        cout << solve(perm) << '\n';
    }

	return 0;
}
