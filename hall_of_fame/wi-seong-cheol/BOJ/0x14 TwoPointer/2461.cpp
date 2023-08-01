//
//  2461.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 3 4
 12 16 67 43
 7 17 68 48
 14 15 77 54
 [Output]
 2
 */
// 시간복잡도: O(n^2)
// 최악시간: 1,000,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2461

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define X first
#define Y second
int n, m;
int st, en, num;
int cnt[1001];
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x; cin >> x;
            v.push_back({x, i});
        }
    }
    sort(v.begin(), v.end());
    int ans = 0x7f7f7f7f;
    while(en < n * m) {
        if(cnt[v[en].Y] == 0) num++;
        cnt[v[en].Y]++;
        en++;
        while(num == n){
            ans = min(ans, v[en - 1].X - v[st].X);
            cnt[v[st].Y]--;
            if(cnt[v[st].Y] == 0) num--;
            st++;
        }
    }
    cout << ans;
    
    return 0;
}
