//
//  15664.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/22.
//

/*
 [Input]
 4 2
 9 7 9 1
 [Output]
 1 7
 1 9
 7 9
 9 9
 */
// 시간복잡도: O(n!)
// 최악시간: 40,320
// 난이도: Silver 2
// Timer: 5m
// Url: https://www.acmicpc.net/problem/15664

#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int ans[10];
int board[10];
bool isused[10];

void func(int k, int st) {
    if(k == m) {
        for(int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    int tmp = 0;
    for(int i = st; i < n; i++) {
        if(!isused[i] && board[i] != tmp) {
            isused[i] = true;
            ans[k] = board[i];
            tmp = board[i];
            func(k + 1, i + 1);
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
    func(0, 0);
    
    return 0;
}
