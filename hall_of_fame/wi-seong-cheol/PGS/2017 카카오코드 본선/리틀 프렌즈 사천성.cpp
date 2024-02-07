//
//  리틀 프렌즈 사천성.cpp
//  main
//
//  Created by wi_seong on 2/7/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 6,760,000
// 난이도: Level 3
// Timer: 2h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/1836#

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Point {
    int x, y;
};

bool isMove(char ch, int x1, int y1, int x2, int y2, vector<string>& board) {
    for(int i = x1; i <= x2; i++) {
        for(int j = y1; j <= y2; j++) {
            if(board[i][j] == ch) continue;
            if(board[i][j] == '.') continue;
            return false;
        }
    }
    return true;
}

bool isRemove(int idx, vector<string>& board, vector<Point> v[26]) {
    int x1, x2, y1, y2;
    x1 = v[idx][0].x;
    y1 = v[idx][0].y;
    x2 = v[idx][1].x;
    y2 = v[idx][1].y;

    char ch = char('A' + idx);

    if(x1 == x2) {
        if(y1 > y2) swap(y1, y2);
        if(!isMove(ch, x1, y1, x2, y2, board)) return false;
    } else if(y1 == y2) {
        if(x1 > x2) swap(x1, x2);
        if(!isMove(ch, x1, y1, x2, y2, board)) return false;
    } else {
        if(x1 < x2) {
            if(y1 < y2) {
                if(!(isMove(ch, x1, y1, x1, y2, board) && isMove(ch, x1, y2, x2, y2, board) ||
                     isMove(ch, x1, y1, x2, y1, board) && isMove(ch, x2, y1, x2, y2, board))) {
                    return false;
                }
            } else {
                if(!(isMove(ch, x1, y2, x1, y1, board) && isMove(ch, x1, y2, x2, y2, board) ||
                     isMove(ch, x1, y1, x2, y1, board) && isMove(ch, x2, y2, x2, y1, board))) {
                    return false;
                }
            }
        } else {
            if(y1 < y2) {
                if(!(isMove(ch, x1, y1, x1, y2, board) && isMove(ch, x2, y2, x1, y2, board) ||
                     isMove(ch, x2, y1, x1, y1, board) && isMove(ch, x2, y1, x2, y2, board))) {
                    return false;
                }
            } else {
                if(!(isMove(ch, x1, y2, x1, y1, board) && isMove(ch, x2, y2, x1, y2, board) ||
                     isMove(ch, x2, y1, x1, y1, board) && isMove(ch, x2, y2, x2, y1, board))) {
                    return false;
                }
            }
        }
    }

    board[v[idx][0].x][v[idx][0].y] = board[v[idx][1].x][v[idx][1].y] = '.';
    return true;
}

string solve(int m, int n, vector<string>& board, vector<Point> v[26], int total) {
    string ret = "";
    int removeCount = 0;

    while(true) {
        bool flag = true;

        for(int i = 0; i < 26; i++) {
            if(!v[i].empty() && isRemove(i, board, v)) {
                flag = false;
                removeCount += 2;
                v[i].clear();
                ret += char('A' + i);
                break;
            }
        }

        if(flag) break;
    }

    if(total > removeCount) return "IMPOSSIBLE";
    return ret;
}

string solution(int m, int n, vector<string> board) {
    vector<Point> v[26];
    int total = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if('A' <= board[i][j] && board[i][j] <= 'Z') {
                v[board[i][j] - 'A'].push_back({i, j});
                total++;
            }
        }
    }

    string answer = solve(m, n, board, v, total);

    return answer;
}
