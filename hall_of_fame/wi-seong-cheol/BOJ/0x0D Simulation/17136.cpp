//
//  17136.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 0 0 0 0 0 0 0 0 0 0
 0 1 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 1 0 0 0 0 0
 0 0 0 0 0 1 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
 0 0 1 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
 [Output]
 4
 */
// 시간복잡도: O(n ^ 5)
// 최악시간: 100,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17136

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x7f7f7f7f;
int ans;
int board[10][10];
int usedPaper[6];

bool OOB(int x, int y) { return x > 10 || y > 10; }

//// 붙일 수 있는 정사각형을 확인
bool isAttach(int row, int col, int size) {
    for(int r = row; r < row + size; r++)
        for(int c = col; c < col + size; c++)
            if(board[r][c] == 0) return false;
    return true;
}

void addPaper(int row, int col, int size){
    for(int r = row; r < row + size; r++)
        for(int c = col; c < col + size; c++)
            board[r][c] = 0;
}

void revertPaper(int row, int col, int size) {
    for(int r = row; r < row + size; r++)
        for(int c = col; c < col + size; c++)
            board[r][c] = 1;
}

// depth가 현재 색종이가 붙여진 횟수가 된다.
void solve(int sr, int depth, int paperCount) {
    if(depth > ans) return;
    if(paperCount == 0) {
        ans = min(ans, depth);
        return;
    }

    for(int r = sr; r < 10; r++) {
        for(int c = 0; c < 10; c++) {
            if(board[r][c] == 0) continue;
            for(int p = 1; p <= 5; p++) {
                if(usedPaper[p] == 0 || OOB(r + p, c + p)) continue;
                if(!isAttach(r, c, p)) continue;
                usedPaper[p]--;
                addPaper(r, c, p);

                solve(r, depth + 1, paperCount - p * p);

                revertPaper(r, c, p);
                usedPaper[p]++;
            }
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ans = INF;
    int paperCount = 0;
    for(int p = 1; p <= 5; p++) usedPaper[p] = 5;
    
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++) {
            cin >> board[i][j];
            paperCount += board[i][j];
        }
    
    solve(0, 0, paperCount);
    
    if(ans == INF) cout << -1;
    else cout << ans;
    
    return 0;
}
