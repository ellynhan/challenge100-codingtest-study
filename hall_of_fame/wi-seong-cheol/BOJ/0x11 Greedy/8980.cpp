//
//  8980.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 4 40
 6
 3 4 20
 1 2 10
 1 3 20
 1 4 30
 2 3 10
 2 4 20
 [Output]
 70
 */
// 시간복잡도: O(nlogn)
// 최악시간: 3,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/8980

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
int n, m, c, s, e, w, ans;
int truck[2001];
vector<tuple<int, int, int>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> c >> m;
    for(int i = 0; i < m; i++) {
        cin >> s >> e >> w;
        v.push_back({e, s, w});
    }
    sort(v.begin(), v.end());
    
    for(auto d : v) {
        tie(e, s, w) = d;
        bool loadable = true;
        for(int i = s; i < e; i++) {
            w = min(w, c - truck[i]);
            if(!w) {
                loadable = false;
                break;
            }
        }
        if(loadable) {
            ans += w;
            for(int i = s; i < e; i++) truck[i] += w;
        }
    }
    cout << ans;
    
    return 0;
}
