//
//  1780.cpp
//  main
//
//  Created by wi_seong on 2022/11/21.
//

/*
 [Input]
 9
 0 0 0 1 1 1 -1 -1 -1
 0 0 0 1 1 1 -1 -1 -1
 0 0 0 1 1 1 -1 -1 -1
 1 1 1 0 0 0 0 0 0
 1 1 1 0 0 0 0 0 0
 1 1 1 0 0 0 0 0 0
 0 1 -1 0 1 -1 0 1 -1
 0 -1 1 0 1 -1 0 1 -1
 0 1 -1 1 0 -1 0 1 -1
 [Output]
 10
 12
 11
 */
// 시간복잡도: O(n * n)
// 최악시간: 4,782,969
// 난이도: Silver 2
// Timer: 20m
// Url: https://www.acmicpc.net/problem/1780

#include <iostream>

using namespace std;
int board[2188][2188];
int cnt[3];

bool check(int x, int y, int n) {
    for(int i = x; i < x+n; i++)
        for(int j = y; j < y+n; j++)
            if(board[x][y] != board[i][j])
                return false;
    return true;
}

void func(int x, int y, int size) {
    if(check(x, y, size)) {
        cnt[board[x][y] + 1] += 1;
        return;
    }
    
    int piece = size / 3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            func(x + i * piece, y + j * piece, piece);
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    func(0, 0, n);
    for(int i = 0; i < 3; i++)
        cout << cnt[i] << '\n';
    
    return 0;
}
