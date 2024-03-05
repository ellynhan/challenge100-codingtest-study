//
//  1966.cpp
//  main
//
//  Created by wi_seong on 3/5/24.
//

/*
 [Input]
 3
 1 0
 5
 4 2
 1 2 3 4
 6 0
 1 1 9 1 1 1
 [Output]
 1
 2
 5
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000
// 난이도: Silver 3
// Timer: 18m
// Url: https://www.acmicpc.net/problem/1966

#include <iostream>
#include <deque>

using namespace std;
int t, n, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        deque<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            v.push_back({x, i});
        }
        
        int cnt = 0;
        while(true) {
            cnt++;
            while(true) {
                bool flag = false;
                for(int i = 1; i < int(v.size()); i++) {
                    if(v[i].first > v.front().first) {
                        flag = true;
                        v.push_back(v.front());
                        v.pop_front();
                        break;
                    }
                }
                if(flag) continue;
                break;
            }
            if(v.front().second == k) break;
            v.pop_front();
        }
        cout << cnt << '\n';
    }

	return 0;
}
