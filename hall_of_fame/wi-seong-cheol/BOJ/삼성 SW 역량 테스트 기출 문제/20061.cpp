//
//  20061.cpp
//  main
//
//  Created by wi_seong on 3/18/24.
//

/*
 [Input]
 1
 1 1 1
 [Output]
 0
 2
 */
// 시간복잡도: O(n * m)
// 최악시간: 400,000
// 난이도: Gold 2
// Timer: 2h
// Url: https://www.acmicpc.net/problem/20061

#include <iostream>
#include <deque>

using namespace std;
int k, t, x, y;
int score, now = 1;
deque<deque<int>> g(6, deque<int>(4)), b(6, deque<int>(4));
int dx[4] = {0, 0, 0, 1};
int dy[4] = {0, 0, 1, 0};

int status(deque<int>& x) {
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        if(x[i] == 0) cnt++;
    }
    if(cnt == 4) return 0;
    if(cnt == 0) return 1;
    return 2;
}

void add_block(int t, int v, deque<deque<int>>& board, int row) {
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

void add(int t, int x, deque<deque<int>>& board) {
    add_block(t, x, board, 0);

    while(1) {
        int idx = 2;
        while(idx < 6 && status(board[idx]) != 1) idx++;
        if(idx == 6) break;
        score++;
        for(int i = idx - 1; i >= 0; i--)
            board[i + 1] = board[i];
        board.pop_front();
        board.push_front(deque<int>(4));
    }

    if(status(board[0]) != 0) {
        board.pop_back(); board.pop_back();
        board.push_front(deque<int>(4));
        board.push_front(deque<int>(4));
    } else if(status(board[1]) != 0) {
        board.pop_back();
        board.push_front(deque<int>(4));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    while(k--) {
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
