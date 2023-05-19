//
//  1911.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/13.
//

/*
 [Input]
 3 3
 1 6
 13 17
 8 12
 [Output]
 5
 */
// 시간복잡도: O(nlogn)
// 최악시간: 40,000
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1911

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define ST first
#define EN second
int n, l, st, en;
int ans, pos = -1;
vector<pair<int, int>> P;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        cin >> st >> en;
        P.push_back({st, en});
    }
    sort(P.begin(), P.end());
    for(auto cur: P) {
        int cnt = 0;
        if(cur.ST <= pos && pos < cur.EN) {
            int len = cur.EN - pos;
            cnt = len / l + (len % l != 0);
            pos += cnt * l;
            ans += cnt;
        } else if(pos < cur.ST) {
            int len = cur.EN - cur.ST;
            cnt = len / l + (len % l != 0);
            pos = cur.ST + cnt * l;
            ans += cnt;
        }
    }
    cout << ans;
    
    return 0;
}
