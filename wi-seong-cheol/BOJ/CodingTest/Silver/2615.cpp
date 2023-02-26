//
//  2615.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/13.
//

/*
 [Input]
 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
 1 1 2 0 0 2 2 2 1 0 0 0 0 0 0 0 0 0 1
 1 0 1 2 0 0 0 0 1 0 0 0 0 0 0 0 0 0 2
 1 0 0 1 2 0 0 0 0 0 0 0 0 0 0 0 0 0 1
 1 0 0 0 0 2 2 0 0 0 0 0 0 0 0 0 0 0 0
 1 0 1 1 0 1 1 2 1 1 1 1 1 1 1 0 0 0 0
 1 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0
 1 0 0 0 0 0 0 1 0 0 0 0 2 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0 0 0 2 0 0 0 0 0 0
 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0
 0 0 0 0 0 0 1 0 0 0 0 0 2 0 0 0 0 0 0
 0 0 0 0 0 1 0 0 0 0 0 0 2 0 0 0 0 0 0
 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 2 0
 0 0 0 1 0 0 0 0 0 0 0 0 0 0 2 0 0 2 2
 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 0 2 1
 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 2 2
 0 0 0 0 0 0 0 0 0 0 0 0 0 1 2 1 2 2 2
 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 1 2 2 2
 [Output]
 1
 15 4
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 8,000
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2615

#include <iostream>

using namespace std;
int board[20][20];

bool OOB(int x, int y) { return x < 0 || x >= 19 || y < 0 || y >= 19; }

bool isWin(int x, int y, int color) {
    
    // 가로
    int cnt = 0;
    if((OOB(x, y - 1) || board[x][y - 1] != color) &&
       (OOB(x, y + 5) || board[x][y + 5] != color)) {
        for(int i = 0; i < 5; i++)
            if(!OOB(x, y + i) && board[x][y + i] == color)
                cnt++;
        if(cnt == 5) return true;
    }
    
    // 세로
    if((OOB(x - 1, y) || board[x - 1][y] != color) &&
       (OOB(x + 5, y) || board[x + 5][y] != color)) {
        cnt = 0;
        for(int i = 0; i < 5; i++)
            if(!OOB(x + i, y) && board[x + i][y] == color)
                cnt++;
        if(cnt == 5) return true;
    }
    
    // 대각선
    if((OOB(x - 1, y - 1) || board[x - 1][y - 1] != color) &&
       (OOB(x + 5, y + 5) || board[x + 5][y + 5] != color)) {
        cnt = 0;
        for(int i = 0; i < 5; i++)
            if(!OOB(x + i, y + i) && board[x + i][y + i] == color)
                cnt++;
        if(cnt == 5) return true;
    }
    
    // 대각선 /
    if((OOB(x + 1, y - 1) || board[x + 1][y - 1] != color) &&
       (OOB(x - 5, y + 5) || board[x - 5][y + 5] != color)) {
        cnt = 0;
        for(int i = 0; i < 5; i++)
            if(!OOB(x - i, y + i) && board[x - i][y + i] == color)
                cnt++;
        if(cnt == 5) return true;
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 19; i++)
        for(int j = 0; j < 19; j++)
            cin >> board[i][j];
    for(int i = 0; i < 19; i++)
        for(int j = 0; j < 19; j++) {
            if(!board[i][j]) continue;
            if(isWin(i, j, 1)) {
                cout << "1\n";
                cout << i + 1 << ' ' << j + 1;
                return 0;
            }
            if(isWin(i, j, 2)) {
                cout << "2\n";
                cout << i + 1 << ' ' << j + 1;
                return 0;
            }
        }
    cout << 0;
    
    return 0;
}
