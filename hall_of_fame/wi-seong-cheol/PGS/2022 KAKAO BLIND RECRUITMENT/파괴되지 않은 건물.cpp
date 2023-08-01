//
//  파괴되지 않은 건물.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/28.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 3,000,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/92344

#include <string>
#include <vector>

using namespace std;
int d[1001][1001];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    
    for(auto s: skill) {
        int x1 = s[1];
        int y1 = s[2];
        int x2 = s[3];
        int y2 = s[4];
        int degree = s[0] == 1 ? -s[5] : s[5];
        d[x1][y1] += degree;
        d[x1][y2 + 1] -= degree;
        d[x2 + 1][y1] -= degree;
        d[x2 + 1][y2 + 1] += degree;
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 1; j < m; j++)
            d[i][j] += d[i][j - 1];
    
    for(int i = 1; i < n; i++)
        for(int j = 0; j < m; j++)
            d[i][j] += d[i - 1][j];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(board[i][j] + d[i][j] > 0) answer++;
    
    return answer;
}
