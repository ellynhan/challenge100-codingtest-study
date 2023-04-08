//
//  1018.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 10 13
 BBBBBBBBWBWBW
 BBBBBBBBBWBWB
 BBBBBBBBWBWBW
 BBBBBBBBBWBWB
 BBBBBBBBWBWBW
 BBBBBBBBBWBWB
 BBBBBBBBWBWBW
 BBBBBBBBBWBWB
 WWWWWWWWWWBWB
 WWWWWWWWWWBWB
 [Output]
 12
 */
// 시간복잡도: O(n ^ 4)
// 최악시간: 160,000
// 난이도: Silver 4
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1018

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x7f7f7f7f;
int ans = INF;
int n, m;
char board[51][51];

int draw(int x, int y) {
    int cnt1 = 0;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++) {
            if((i + j) % 2 == 0){
                if(board[i + x][j + y] == 'W') cnt1++;
            } else {
                if(board[i + x][j + y] == 'B') cnt1++;
            }
        }
    
    int cnt2 = 0;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++) {
            if((i + j) % 2 == 0){
                if(board[i + x][j + y] == 'B') cnt2++;
            } else {
                if(board[i + x][j + y] == 'W') cnt2++;
            }
        }
    
    return min(cnt1, cnt2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    for(int i = 0; i <= n - 8; i++)
        for(int j = 0; j <= m - 8; j++)
            ans = min(ans, draw(i, j));
    cout << ans;
    
    return 0;
}
