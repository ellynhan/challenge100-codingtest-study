//
//  19235.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 1
 1 1 1
 [Output]
 0
 2
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 100,000,000
// 난이도: Platinum 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/19235

#include <iostream>
#include <vector>

using namespace std;
int n, t, x, y;
int score, now = 1;
vector<vector<int>> g(6, vector<int>(4)), b(6, vector<int>(4));
int dx[4] = {0, 0, 0, 1}; // t = 1 : 자기 자신 2번, t = 2 : 오른쪽 블럭과 자신, t = 3 : 위쪽 블럭과 자신
int dy[4] = {0, 0, 1, 0};

// 0 : empty, 1 : full, 2 : neither
int status(vector<int>& x) {
    int cnt0 = 0;
    for(int i = 0; i < 4; i++) {
        if(x[i] == 0) cnt0++;
    }
    if(cnt0 == 4) return 0;
    if(cnt0 == 0) return 1;
    return 2;
}

void add_block(int t, int v, vector<vector<int>>& board, int row) {
    while(1) {
        if(board[row][v] || board[row + dx[t]][v + dy[t]]) {
            row--;
            break;
        }
        if(t == 3 && row == 4) break;
        if(row == 5) break;
        row++;
    }
    board[row][v] = board[row + dx[t]][v + dy[t]] = now++;
}

void add(int t, int x, vector<vector<int>>& board) {
    add_block(t, x, board, 0);
    
    while(1) {
        int idx = 2;
        while(idx < 6 && status(board[idx]) != 1) idx++;
        if(idx == 6) break; // 꽉 찬 행이 없을 경우
        score++;
        board[idx] = vector<int>(4);
        for(int i = idx - 1; i >= 0; i--) {
            for(int j = 0; j < 4; j++) {
                if(board[i][j] == 0) continue;
                if(j != 3 && board[i][j] == board[i][j+1]) { // 2번 블럭 형태
                    board[i][j] = board[i][j+1] = 0;
                    add_block(2, j, board, i);
                } else if(i != 0 && board[i-1][j] == board[i][j]) { // 3번 블럭 형태
                    board[i-1][j] = board[i][j] = 0;
                    add_block(3, j, board, i-1);
                } else { // 1번 블럭 형태
                    board[i][j] = 0;
                    add_block(1, j, board, i);
                }
            }
        }
    }
    // 3. 0행 or 1행이 비지 않은 경우 처리
    if(status(board[0]) != 0) { // 0행이 비지 않은 경우(1행도 당연히 비지 않았음)
        board.pop_back(); board.pop_back();
        board.insert(board.begin(), 2, vector<int>(4));
    } else if(status(board[1]) != 0) { // 0행은 비었는데 1행은 비지 않은 경우
        board.pop_back();
        board.insert(board.begin(), vector<int>(4));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--) {
        now++;
        cin >> t >> x >> y;
        if(t == 1){
            add(1, y, g);
            add(1, x, b);
        }
        else if(t == 2){
            add(2, y, g);
            add(3, x, b);
        }
        else{
            add(3, y, g);
            add(2, x, b);
        }
    }
    int cnt = 0;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 4; j++)
            cnt += (b[i][j] != 0) + (g[i][j] != 0);
    }
    cout << score << '\n' << cnt;
    
    return 0;
}
