//
//  자물쇠와 열쇠.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/01.
//

// 시간복잡도: O(n ^ 4)
// 최악시간: 160,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/60059#

#include <string>
#include <vector>
#include <iostream>

using namespace std;
int n, m, k;

void rotate(vector<vector<int>>& key) {
    vector<vector<int>> board(m, vector<int>(m, 0));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            board[j][m - i - 1] = key[i][j];
    key = board;
}

bool check(vector<vector<int>>& key, vector<vector<int>>& board, int x, int y) {
    bool ret = true;
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            board[i + x][j + y] += key[i][j];
    
    // 가운데 lock 영역이 모두 1이면 true, 아니면 false
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(board[i + m - 1][j + m - 1] != 1) {
                ret = false;
                break;
            }
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            board[i + x][j + y] -= key[i][j];
    
    return ret;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    n = lock.size();
    m = key.size();
    k = 2 * (m - 1) + n;
    vector<vector<int>> board(k, vector<int>(k, 0));
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board[m + i - 1][m + j - 1] = lock[i][j];
    
    for(int dir = 0; dir < 4; dir++) {    // 90도로 4번 회전
        rotate(key);
        for(int i = 0; i <= k - m; i++)
            for(int j = 0; j <= k - m; j++)
                if(check(key, board, i, j))
                    return true;
    }
    
    return false;
}
