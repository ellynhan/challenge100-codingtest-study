//
//  STRJOIN.cpp
//  main
//
//  Created by wi_seong on 1/15/24.
//

/*
 [Input]
 3
 3
 2 2 4
 5
 3 1 3 4 1
 8
 1 1 1 1 1 1 1 2
 [Output]
 12
 26
 27
 */
// 시간복잡도: O(nlogn)
// 최악시간: 200
// 난이도: 중
// Timer: 30분
// Url: https://algospot.com/judge/problem/read/STRJOIN

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int t, n, x;
priority_queue<int, vector<int>, greater<int>> pq;

int calc() {
    int ret = 0;
    while(pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        ret += a + b;
        pq.push(a + b);
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
            cin >> x;
            pq.push(x);
        }
        cout << calc() << '\n';
        pq.pop();
    }

	return 0;
}
