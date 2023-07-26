//
//  2457.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 4
 1 3
 2 5
 3 5
 6 7
 [Output]
 5
 */
// 시간복잡도: O(nlogn)
// 최악시간: 6,000,000
// 난이도: Gold 5
// Timer: 20m
// Url: https://www.acmicpc.net/problem/2457

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int x, y, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    tie(x, y) = v[0];
    for(int i = 1; i < n; i++) {
        int nx, ny;
        tie(nx, ny) = v[i];
        if(nx <= y && y <= ny) y = ny;
        else if(y < nx) {
            ans += y - x;
            x = nx;
            y = ny;
        }
    }
    cout << ans + y - x;
    
    return 0;
}
