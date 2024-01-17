//
//  23291.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 1/2/24.
//

/*
 [Input]
 8 0
 5 2 3 14 9 2 11 8
 [Output]
 6
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 1,000,000
// 난이도: Platinum 5
// Timer: 3h
// Url: https://www.acmicpc.net/problem/23291

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n, k;
int mn, mx;
int board[100][100];

bool isEnd() {
    mn = *min_element(board[0], board[0] + n);
    mx = *max_element(board[0], board[0] + n);
    return mx - mn <= k;
}

void appendMinFishBowl() {
    for(int i = 0; i < n; i++) {
        if(board[0][i] == 0) break;
        if(board[0][i] == mn) board[0][i]++;
    }
}

void move() {
    int width = 1;
    int height = 1;

    while(n - width * height >= height) {
        int bowl[height + 1][100];
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                bowl[i][j] = board[i][j];
            }
        }
        
        for(int i = 0; i < n - width; i++) {
            board[width][i] = board[height - 1][i + width];
            board[height - 1][i + width] = 0;
        }
        
        for(int i = 0; i < width; i++) {
            for(int j = 0; j < height; j++)
                board[i][j] = bowl[height - j - 1][i];
        }

        if(width == height) height++;
        else width++;
    }
}

void moveSplit(int size) {
    int tmp[n / size][100];
    memset(tmp, 0, sizeof(tmp));
    for(int i = 0; i < (n / size) / 2; i++) {
        for(int j = 0; j < size; j++)
            tmp[i][j] = board[((n / size) / 2) - i - 1][size - j - 1];
    }
    for(int i = 0; i < (n / size) / 2; i++) {
        for(int j = size; j < size * 2; j++) {
            board[i][j - size] = tmp[i][j - size];
            board[i + ((n / size) / 2)][j - size] = board[i][j];
            board[i][j] = 0;
        }
    }
}

void calculate() {
    int tmp[n][100];
    memset(tmp, 0, sizeof(tmp));
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(board[i][j] == 0) continue;
            if(board[i][j + 1] != 0) {
                int x = abs(board[i][j] - board[i][j + 1]) / 5;
                if(x == 0) {

                } else if(board[i][j] < board[i][j + 1]) {
                    tmp[i][j] += x;
                    tmp[i][j + 1] -= x;
                } else {
                    tmp[i][j] -= x;
                    tmp[i][j + 1] += x;
                }
            }
            if(board[i + 1][j] != 0) {
                int x = abs(board[i][j] - board[i + 1][j]) / 5;
                if(x == 0) {

                } else if(board[i][j] < board[i + 1][j]) {
                    tmp[i][j] += x;
                    tmp[i + 1][j] -= x;
                } else {
                    tmp[i][j] -= x;
                    tmp[i + 1][j] += x;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] += tmp[i][j];
        }
    }
}

void flatten() {
    int len = 0;
    int tmp[n];
    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j >= 0; j--) {
            if(board[j][i] == 0) continue;
            tmp[len++] = board[j][i];
            board[j][i] = 0;
        }
    }
    for(int i = 0; i < n; i++)
        board[0][i] = tmp[i];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int cnt = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> board[0][i];

    while(1) {
        if(isEnd()) break;
        cnt++;
        appendMinFishBowl();
        move();
        calculate();
        flatten();
        moveSplit(n / 2);
        moveSplit(n / 4);
        calculate();
        flatten();
    }
    cout << cnt;

	return 0;
}
