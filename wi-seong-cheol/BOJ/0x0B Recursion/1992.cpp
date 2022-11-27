//
//  1992.cpp
//  main
//
//  Created by wi_seong on 2022/11/21.
//

/*
 [Input]
 8
 11110000
 11110000
 00011100
 00011100
 11110000
 11110000
 11110011
 11110011
 [Output]
 ((110(0101))(0010)1(0001))
 */
// 시간복잡도: O(n * n)
// 최악시간: 4096
// 난이도: Silver 1
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1992

#include <iostream>

using namespace std;
string board[65];

bool check(int x, int y, int n) {
    for(int i = x; i < x + n; i++)
        for(int j = y; j < y + n; j++)
            if(board[i][j] != board[x][y])
                return false;
    return true;
}

void func(int x, int y, int n) {
    if(check(x, y, n)) {
        cout << board[x][y];
        return;
    }
    int piece = n / 2;
    cout << '(';
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            func(x + i * piece, y + j * piece, piece);
    cout << ')';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    func(0, 0, n);
    
    return 0;
}
