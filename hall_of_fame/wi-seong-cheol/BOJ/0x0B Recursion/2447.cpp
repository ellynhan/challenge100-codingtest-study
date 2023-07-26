//
//  2447.cpp
//  main
//
//  Created by wi_seong on 2022/11/21.
//

/*
 [Input]
 9
 [Output]
 *********
 * ** ** *
 *********
 ***   ***
 * *   * *
 ***   ***
 *********
 * ** ** *
 *********
 */
// 시간복잡도: O(3^14)
// 최악시간: 4,782,969
// 난이도: Gold 5
// Timer: 12m
// Url: https://www.acmicpc.net/problem/2447

#include <iostream>

using namespace std;
char board[2188][2188];

void func(int x, int y, int n) {
    if(n == 1) {
        board[x][y] = '*';
        return;
    }
    
    int piece = n / 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i != 1 || j != 1) {
                func(x + i * piece, y + j * piece, piece);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        fill(board[i], board[i] + n, ' ');
    func(0, 0, n);
    for(int i = 0; i < n; i++)
        cout << board[i] << '\n';
    
    return 0;
}
