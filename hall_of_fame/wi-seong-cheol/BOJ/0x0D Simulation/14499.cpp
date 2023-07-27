//
//  14499.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 4 2 0 0 8
 0 2
 3 4
 5 6
 7 8
 4 4 4 1 3 3 3 2
 [Output]
 0
 0
 3
 0
 0
 8
 6
 3
 */
// 시간복잡도: O(n * m)
// 최악시간: 400
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/14499

#include <iostream>

using namespace std;
int n, m, x, y, k, command;
int board[21][21];
int dice[7];

int idx[5][4] = {
  {},        // dummy
  {2,6,4,5}, // 동쪽, 5->2, 2->6, 6->4, 4->5
  {2,5,4,6}, // 서쪽, 6->2, 2->5, 5->4, 4->6
  {3,2,1,4}, // 북쪽, 4->3, 3->2, 2->1, 1->4
  {2,3,4,1}, // 남쪽, 1->2, 2->3, 3->4, 4->1
};

bool OOB(int a, int b) { return a < 0 || a >= n || b < 0 || b >= m; }

void roll(int c) {
    int tmp[7];
    
    for(int i = 0; i < 7; i++)
        tmp[i] = dice[i];
    for(int i = 0; i < 4; i++)
        tmp[idx[c][i]] = dice[idx[c][(i + 1) % 4]];
    for(int i = 0; i < 7; i++)
        dice[i] = tmp[i];
}

void score(int c) {
    int nx = x;
    int ny = y;
    
    if(c == 1) ny++;
    else if(c == 2) ny--;
    else if(c == 3) nx--;
    else nx++;
    
    if(!OOB(nx, ny)) {
        x = nx;
        y = ny;
        
        roll(c);
        if(board[nx][ny] == 0) {
            board[nx][ny] = dice[4];
        } else {
            dice[4] = board[nx][ny];
            board[nx][ny] = 0;
        }
        cout << dice[2] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    while(k--) {
        cin >> command;
        score(command);
    }
    
    return 0;
}
