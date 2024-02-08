//
//  TICTACTOE.cpp
//  main
//
//  Created by wi_seong on 1/21/24.
//

/*
 [Input]
 3
 ...
 ...
 ...
 xx.
 oo.
 ...
 xox
 oo.
 x.x
 [Output]
 TIE
 x
 o
 */
// 시간복잡도: O(3 ^ 11)
// 최악시간: 177,147
// 난이도: 하
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/TICTACTOE

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t;
int cache[19683];
vector<string> board;

int bijection(vector<string> &board) {
    int ret = 0;
    for(int y = 0; y < 3; y++) {
        for(int x = 0; x < 3 ; x++) {
            ret = ret * 3;
            if(board[y][x] == 'o') ret += 1;
            else if(board[y][x] == 'x') ret += 2;
        }
    }
    return ret;
}

bool isFinished(const vector<string> &board, char turn) {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == turn && board[i][1] == turn && board[i][2] == turn) return true;
        if(board[0][i] == turn && board[1][i] == turn && board[2][i] == turn) return true;
    }
    if(board[0][0] == turn && board[1][1] == turn && board[2][2] == turn) return true;
    if(board[0][2] == turn && board[1][1] == turn && board[2][0] == turn) return true;
    return false;
}

int canWin(vector<string> &board, char turn) {
    if(isFinished(board, 'o' + 'x' - turn)) return -1;
    int &ret = cache[bijection(board)];
    if(ret != -2) return ret;

    int result = 2;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != '.') continue;
            board[i][j] = turn;
            result = min(result, canWin(board, 'o' + 'x' - turn));
            board[i][j] = '.';
        }
    }

    if(result == 2 || result == 0) return ret = 0;

    return ret = -result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        for(int i = 0; i < 19683; i++) cache[i] = -2;
        board.resize(3);
        for(int i = 0; i < 3 ; i++) {
            cin >> board[i];
        }
        int x = 0, o = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3 ; j++) {
                if(board[i][j] == 'x') x++;
                else if(board[i][j] == 'o') o++;
            }
        }

        char turn = (x <= o ? 'x' : 'o');
        int result = canWin(board, turn);

        if(result == 1) cout << turn << '\n';
        else if(result == -1) cout << (turn == 'x' ? 'o' : 'x') << '\n';
        else cout << "TIE\n";
    }

	return 0;
}
