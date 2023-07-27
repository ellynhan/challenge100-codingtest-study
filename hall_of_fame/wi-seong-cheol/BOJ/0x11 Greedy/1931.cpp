//
//  1931.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 11
 1 4
 3 5
 0 6
 5 7
 3 8
 5 9
 6 10
 8 11
 8 12
 2 13
 12 14
 [Output]
 4
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 1
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1931

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define X first
#define Y second
int n;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int st, en; cin >> st >> en;
        v.push_back({en, st});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int pivot = 0;
    for(int i = 0; i < n; i++) {
        if(pivot <= v[i].Y) {
            ans++;
            pivot = v[i].X;
        }
    }
    cout << ans;
    
    return 0;
}
