//
//  1700.cpp
//  main
//
//  Created by wi_seong on 3/15/24.
//

/*
 [Input]
 2 7
 2 3 2 3 1 2 7
 [Output]
 2
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 1,000,000
// 난이도: Gold 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1700

#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;
int n, k;
int a[101];
unordered_set<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 0; i < k; i++) {
        if(s.find(a[i]) == s.end()) {
            if(s.size() == n) {
                int idx = -1;
                vector<pair<int, int>> v;

                for(auto it = s.begin(); it != s.end(); it++) {
                    bool flag = true;
                    for(int j = i + 1; j < k; j++) {
                        if(a[j] == *it) {
                            v.push_back({j, *it});
                            flag = false;
                            break;
                        }
                    }
                    if(flag) {
                        v.push_back({k, *it});
                    }
                }
                sort(v.begin(), v.end());
                s.erase(v.back().second);
                ans++;
            }
            s.insert(a[i]);
        }
    }
    cout << ans;

	return 0;
}
