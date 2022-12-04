//
//  15654.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/22.
//

/*
 [Input]
 3 1
 4 5 2
 [Output]
 2
 4
 5
 */
// 시간복잡도: O(n ^ n)
// 최악시간: 16,777,216
// 난이도: Silver 3
// Timer: 7m
// Url: https://www.acmicpc.net/problem/15654

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int ans[10];
int board[10];
bool isused[10];

void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!isused[i]) {
            isused[i] = true;
            ans[k] = board[i];
            func(k + 1);
            isused[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    sort(board, board + n);
    func(0);
    
    return 0;
}
