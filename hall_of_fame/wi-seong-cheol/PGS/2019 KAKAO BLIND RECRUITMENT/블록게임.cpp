//
//  블록게임.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/06.
//

// 시간복잡도: O(n ^ 4)
// 최악시간: 6,450,000
// 난이도: Level 4
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42894

#include <string>
#include <vector>

using namespace std;
int n;
vector<vector<int>> Board;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

bool canFill(int x, int y) {
    for(int i = 0; i < x; i++)
        if(Board[i][y] != 0) return false;
    return true;
}

bool find(int row, int col, int h, int w) {
    int emptyCnt = 0;
    int lastValue = -1;
    
    for(int r = row; r < row + h; r++) {
        for(int c = col; c < col + w; c++) {
            if(Board[r][c] == 0) {
                if(emptyCnt == 2 || !canFill(r, c)) return false;
                emptyCnt++;
            }
            else {
                if(lastValue != -1 && Board[r][c] != lastValue) return false;
                lastValue = Board[r][c];
            }
        }
    }
    
    for(int r = row; r < row + h; r++)
        for(int c = col; c < col + w; c++)
            Board[r][c] = 0;
    
    return true;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    n = board.size();
    Board = board;
    int cnt = 0;
    
    do {
        cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!OOB(i + 1, j + 2) && find(i, j, 2, 3)) {
                    cnt++;
                } else if(!OOB(i + 2, j + 1) && find(i, j, 3, 2)) {
                    cnt++;
                }
            }
        }
        answer += cnt;
    } while(cnt);
    
    return answer;
}
