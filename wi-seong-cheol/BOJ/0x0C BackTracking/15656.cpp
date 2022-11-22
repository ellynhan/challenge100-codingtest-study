//
//  15656.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/22.
//

/*
 [Input]
 4 2
 9 8 7 1
 [Output]
 1 1
 1 7
 1 8
 1 9
 7 1
 7 7
 7 8
 7 9
 8 1
 8 7
 8 8
 8 9
 9 1
 9 7
 9 8
 9 9
 */
// 시간복잡도: O(n ^ n)
// 최악시간: 16,777,216
// 난이도: Silver 3
// Timer: 7m
// Url: https://www.acmicpc.net/problem/15656

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int ans[10];
int board[10];

void func(int k, int st) {
    if(k == m) {
        for(int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++) {
        ans[k] = board[i];
        func(k + 1, i + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    sort(board, board + n);
    func(0, 0);
    
    return 0;
}
