//
//  1799.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/22.
//

/*
 [Input]
 5
 1 1 0 1 1
 0 1 0 0 0
 1 0 1 0 1
 1 0 0 0 0
 1 0 1 1 1
 [Output]
 7
 */
// 시간복잡도: O(2^n)
// 최악시간: 1,048,576
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1799

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int ans[2];
bool isused[2][20];
vector<pair<int, int>> board[2][20];

void bishop(int idx, int cnt, int color) {
    if(idx == 2 * n) {
        ans[color] = max(ans[color], cnt);
        return;
    }
    for(auto v: board[color][idx]) {
        int x, y;
        tie(x, y) = v;
        if(isused[color][x + y]) continue;
        isused[color][x + y] = true;
        bishop(idx + 1, cnt + 1, color);
        isused[color][x + y] = false;
    }
    bishop(idx + 1, cnt, color);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x; cin >> x;
            if(x) board[(i + j + 1) % 2][n + i - j - 1].push_back({i, j});
        }
    }
    bishop(0, 0, 0);
    bishop(0, 0, 1);
    
    cout << ans[0] + ans[1];
    
    return 0;
}
