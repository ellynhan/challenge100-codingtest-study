//
//  등굣길.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/11.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000
// 난이도: Level 3
// Timer: 15m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42898

#include <string>
#include <vector>

using namespace std;
const int mod = 1e9 + 7;
int d[101][101];
int board[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    
    d[1][1] = 1;
    for(auto element: puddles)
        board[element[1]][element[0]] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i == 1 && j == 1) continue;
            if(board[i][j] == 1) continue;
            d[i][j] = (d[i - 1][j] + d[i][j - 1]) % mod;
        }
    }
    
    return d[n][m];
}
