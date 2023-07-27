//
//  18869.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 2 3
 1 3 2
 12 50 10
 [Output]
 0
 */
// 시간복잡도: O(n^3)
// 최악시간: 100,000,000
// 난이도: Gold 5
// Timer: 20m
// Url: https://www.acmicpc.net/problem/18869

#include <iostream>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n, m, ans;
pair<int, int> board[101][10001];
int sort_board[101][10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int x; cin >> x;
            board[i][j] = {x, -1};
            sort_board[i][j] = x;
        }
        sort(sort_board[i], sort_board[i] + n);
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int idx = (int)(lower_bound(sort_board[i], sort_board[i] + n, board[i][j].X) - sort_board[i]);
            board[i][j] = {board[i][j].X, idx};
        }
    }
    for(int i = 0; i < m - 1; i++) {
        for(int j = i + 1; j < m; j++) {
            bool isSame = true;
            for(int k = 0; k < n; k++)
                if(board[i][k].Y != board[j][k].Y) isSame = false;
            if(isSame) ans++;
        }
    }
    cout << ans;
    
    return 0;
}
