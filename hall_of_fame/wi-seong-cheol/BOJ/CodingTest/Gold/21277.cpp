//
//  21277.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/15.
//

/*
 [Input]
 5 5
 11111
 10000
 11111
 10000
 11111
 5 3
 101
 101
 101
 101
 111
 [Output]
 30
 */
// 시간복잡도: O(n ^ 4)
// 최악시간: 2,500,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/21277

#include <iostream>
#include <algorithm>

using namespace std;
int ans = 0x7f7f7f7f;
int n1, m1, n2, m2;
char board1[51][51];
char board2[51][51];
char board3[151][151];

void rotate() {
    swap(n2, m2);
    char tmp[n2][m2];
    for(int i = 0; i < n2; i++)
        for(int j = 0; j < m2; j++)
            tmp[i][j] = board2[j][n2 - i - 1];
    for(int i = 0; i < n2; i++)
        for(int j = 0; j < m2; j++)
            board2[i][j] = tmp[i][j];
}

void getSize(int x, int y) {
    bool flag = false;
    for(int i = y; i < y + n2; i++) {
        for(int j = x; j < x + m2; j++) {
            if(board3[i][j] == '1' && board2[i - y][j - x] == '1') {
                flag = true;
                break;
            }
        }
        
        if(flag) break;
    }
    
    if(flag == false) {
        int minx = min(x, 50);
        int miny = min(y, 50);
        int maxx = max(x + m2 - 1, 49 + m1);
        int maxy = max(y + n2 - 1, 49 + n1);
        
        int space = (maxx - minx + 1) * (maxy - miny + 1);
        ans = min(ans, space);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n1 >> m1;
    for(int i = 0; i < n1; i++)
        for(int j = 0; j < m1; j++)
            cin >> board1[i][j];
    cin >> n2 >> m2;
    for(int i = 0; i < n2; i++)
        for(int j = 0; j < m2; j++)
            cin >> board2[i][j];
    for(int i = 0; i < n1; i++)
        for(int j = 0; j < m1; j++)
            board3[i + 50][j + 50] = board1[i][j];
    for(int dir = 0; dir < 4; dir++) {
        for(int i = 0; i < 100; i++)
            for(int j = 0; j < 100; j++)
                getSize(i, j);
        if(dir != 3) rotate();
    }
    cout << ans;
    
    return 0;
}
