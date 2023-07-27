//
//  2448.cpp
//  main
//
//  Created by wi_seong on 2022/11/21.
//

/*
 [Input]
 6
 [Output]
      *
     * *
    *****
   *     *
  * *   * *
 ***** *****
 */
// 시간복잡도: O(3 * (2 ^ n))
// 최악시간: 3,072
// 난이도: Gold 4
// Timer: 20m
// Url: https://www.acmicpc.net/problem/2448

#include <iostream>

using namespace std;
const int MAX = 1024 * 3 + 2;
char board[MAX][MAX * 2 - 1];

void fillStar(int x, int y) {
    board[x][y] = '*';
    board[x + 1][y - 1] = '*';
    board[x + 1][y + 1] = '*';
    for(int i = y - 2; i <= y + 2; i++)
        board[x + 2][i] = '*';
}

void func(int x, int y, int n) {
    if(n == 3) {
        fillStar(x, y);
        return;
    }
    int piece = n / 2;
    func(x, y, piece);
    func(x + piece, y - piece, piece);
    func(x + piece, y + piece, piece);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        fill(board[i], board[i] + 2 * n - 1, ' ');
    func(0, n - 1, n);
    for(int i = 0; i < n; i++)
        cout << board[i] << '\n';
    
    return 0;
}
