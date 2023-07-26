//
//  2170.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 4
 1 1 5 31
 1 1 6 30
 5 15 8 31
 6 10 12 10
 [Output]
 2
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Gold 3
// Timer: 20m
// Url: https://www.acmicpc.net/problem/2170

#include <iostream>
#include <vector>

using namespace std;
#define X first
#define Y second
int n, ans;
int m1, d1, m2, d2;
vector<pair<int, int>> flower;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m1 >> d1 >> m2 >> d2;
        flower.push_back({m1 * 100 + d1, m2 * 100 + d2});
    }
    
    int t = 301;
    while(t < 1201) {
        int nxt_t = t;
        for(int i = 0; i < n; i++) {
            if(flower[i].X <= t && flower[i].Y >= nxt_t)
                nxt_t = flower[i].Y;
        }
        if(nxt_t == t) {
            cout << 0;
            return 0;
        }
        t = nxt_t;
        ans++;
    }
    cout << ans;
    
    return 0;
}
