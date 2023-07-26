//
//  2630.cpp
//  main
//
//  Created by wi_seong on 2022/11/21.
//

/*
 [Input]
 8
 1 1 0 0 0 0 1 1
 1 1 0 0 0 0 1 1
 0 0 0 0 1 1 0 0
 0 0 0 0 1 1 0 0
 1 0 0 0 1 1 1 1
 0 1 0 0 1 1 1 1
 0 0 1 1 1 1 1 1
 0 0 1 1 1 1 1 1
 [Output]
 9
 7
 */
// 시간복잡도: O(n * n)
// 최악시간: 16,384
// 난이도: Silver 2
// Timer: 12m
// Url: https://www.acmicpc.net/problem/2630

#include <iostream>

using namespace std;
int board[129][129];
int cnt[2];

bool check(int x, int y, int n) {
    for(int i = x; i < x + n; i++)
        for(int j = y; j < y + n; j++)
            if(board[i][j] != board[x][y])
                return false;
    return true;
}

void func(int x, int y, int n) {
    if(check(x, y, n)) {
        cnt[board[x][y]] += 1;
        return;
    }
    
    int piece = n / 2;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            func(x + i * piece, y + j * piece, piece);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    func(0, 0, n);
    for(int i = 0; i < 2; i++)
        cout << cnt[i] << '\n';
    
    return 0;
}
