//
//  16987.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/22.
//

/*
 [Input]
 3
 8 5
 1 100
 3 5
 [Output]
 3
 */
// 시간복잡도: O(2^n)
// 최악시간: 1,024
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/16987

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define X first
#define Y second
int n, ans;
vector<pair<int, int>> v;

void func(int k, int cnt) {
    if(k == n) {
        ans = max(ans, cnt);
        return;
    }
    if(v[k].X <= 0 || cnt == n - 1) {
        func(k + 1, cnt);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(i != k && v[i].X > 0) {
            v[k].X -= v[i].Y;
            v[i].X -= v[k].Y;
            if(v[k].X <= 0) cnt++;
            if(v[i].X <= 0) cnt++;
            func(k + 1, cnt);
            if(v[k].X <= 0) cnt--;
            if(v[i].X <= 0) cnt--;
            v[k].X += v[i].Y;
            v[i].X += v[k].Y;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }
    func(0, 0);
    cout << ans;
    
    return 0;
}
