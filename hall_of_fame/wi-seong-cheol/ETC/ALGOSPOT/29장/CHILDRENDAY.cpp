//
//  CHILDRENDAY.cpp
//  main
//
//  Created by wi_seong on 1/27/24.
//

/*
 [Input]
 5
 1 7 0
 1 10 1
 0 7 3
 345 9997 3333
 35 9 8
 [Output]
 111111
 11
 IMPOSSIBLE
 54535355353
 53
 */
// 시간복잡도: O(2 * n * |d|)
// 최악시간: 200,000
// 난이도: 상
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/CHILDRENDAY

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int t, n, m;
string digits;

int append(int here, int edge) {
    int there = here * 10 + edge;
    if(there >= n) {
        return n + there % n;
    }
    return there % n;
}

string solve() {
    sort(digits.begin(), digits.end());
    queue<int> Q;
    vector<int> parent(2 * n, -1);
    vector<int> choice(2 * n, -1);
    Q.push(0);
    parent[0] = 0;

    while(!Q.empty()) {
        int here = Q.front();
        Q.pop();
        for(int i = 0; i < digits.size(); i++) {
            int there = append(here, digits[i] - '0');
            if(parent[there] == -1) {
                parent[there] = here;
                choice[there] = digits[i] - '0';
                Q.push(there);
            }
        }
    }

    if(parent[n + m] == -1) {
        return "IMPOSSIBLE";
    }

    string ret;
    int here = n + m;
    while(parent[here] != here) {
        ret += char('0' + choice[here]);
        here = parent[here];
    }
    reverse(ret.begin(), ret.end());

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> digits >> n >> m;
        cout << solve() << "\n";
    }

	return 0;
}
