//
//  2578.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 3/6/24.
//

/*
 [Input]
 11 12 2 24 10
 16 1 13 3 25
 6 20 5 21 17
 19 4 8 14 9
 22 15 7 23 18
 5 10 7 16 2
 4 22 8 17 13
 3 18 1 6 25
 12 19 23 14 21
 11 24 9 20 15
 [Output]
 15
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 25
// 난이도: Silver 4
// Timer: 13m
// Url: https://www.acmicpc.net/problem/2578

#include <iostream>

using namespace std;
int board[5][5];
bool chk[5][5];

bool isBingo() {
    int cnt = 0;
    bool flag = true;

    for(int i = 0; i < 5; i++) {
        flag = true;
        for(int j = 0; j < 5; j++) {
            if(!chk[i][j]) {
                flag = false;
                break;
            }
        }
        if(flag) cnt++;

        flag = true;
        for(int j = 0; j < 5; j++) {
            if(!chk[j][i]) {
                flag = false;
                break;
            }
        }
        if(flag) cnt++;
    }

    flag = true;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(i == j) {
                if(!chk[i][j]) {
                    flag = false;
                    break;
                }
            }
        }
    }
    if(flag) cnt++;

    flag = true;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(i + j == 4) {
                if(!chk[i][j]) {
                    flag = false;
                    break;
                }
            }
        }
    }
    if(flag) cnt++;

    return cnt >= 3;
}

void check(int x) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(board[i][j] == x) {
                chk[i][j] = true;
                return;
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < 25; i++) {
        int x; cin >> x;
        check(x);
        if(isBingo()) {
            cout << i + 1;
            break;
        }
    }

	return 0;
}
