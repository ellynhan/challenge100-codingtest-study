//
//  15898.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 12/28/23.
//

/*
 [Input]
 4
 6 3 3 -9
 -6 8 -6 8
 9 5 1 -1
 -8 2 -3 -1
 R B G Y
 Y B R R
 W R R R
 G R W B
 -6 -2 -4 -3
 1 -3 0 9
 8 -7 2 0
 0 3 -5 7
 W B R Y
 Y W R B
 W B G G
 Y G B R
 8 7 2 1
 -9 8 8 -9
 -1 -4 8 6
 -7 8 -3 8
 Y W W G
 Y B R B
 Y W R R
 R Y W Y
 4 -5 8 3
 2 3 1 3
 -5 0 1 -3
 4 3 3 -6
 W Y G W
 G G R W
 G Y G R
 R R G Y
 [Output]
 634
 */
// 시간복잡도: O((nCr) ^ 3)
// 최악시간: 1,728,000
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/15898

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;
int n;
int pickItem[3];
int roteteItem[3];
int placeItem[3];
bool isused[10];
int item[10][2][4][4][4];
int board[2][5][5];
int place[4][2] = {
    {0, 0}, {0, 1}, {1, 0}, {1, 1}
};
unordered_map<char, int> colorSet = {
    {'R', 1}, {'B', 2}, {'G', 3}, {'Y', 4}
};

int makeBomb(int depth) {
    if(depth == 3) {
        int sumArr[5];
        memset(sumArr, 0, sizeof(sumArr));

        for(int i = 0; i < 3; i++) {
            int x = place[placeItem[i]][0];
            int y = place[placeItem[i]][1];
            int pick = pickItem[i];
            int rotate = roteteItem[i];

            for(int j = 0; j < 4; j++) {
                for(int k = 0; k < 4; k++) {
                    board[0][j + x][k + y] = max(0, min(9, board[0][j + x][k + y] + item[pick][0][rotate][j][k]));

                    if(item[pick][1][rotate][j][k] > 0) {
                        board[1][j + x][k + y] = item[pick][1][rotate][j][k];
                    }
                }
            }
        }

        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                sumArr[board[1][j][k]] += board[0][j][k];
                board[0][j][k] = board[1][j][k] = 0;
            }
        }

        return sumArr[1] * 7 + sumArr[2] * 5 + sumArr[3] * 3 + sumArr[4] * 2;
    }

    int ret = 0;

    for(int i = 0; i < 4; i++) {
        placeItem[depth] = i;
        ret = max(ret, makeBomb(depth + 1));
    }

    return ret;
}

int move(int depth) {
    if(depth == 3) return makeBomb(0);

    int ret = 0;

    for(int i = 0; i < 4; i++) {
        roteteItem[depth] = i;
        ret = max(ret, move(depth + 1));
    }

    return ret;
}

int solve(int depth) {
    if(depth == 3) return move(0);

    int ret = 0;

    for(int i = 0; i < n; i++) {
        if(isused[i]) continue;
        pickItem[depth] = i;
        isused[i] = true;
        ret = max(ret, solve(depth + 1));
        isused[i] = false;
    }

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++)
                cin >> item[i][0][0][j][k];
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++) {
                char color; cin >> color;
                item[i][1][0][j][k] = colorSet[color];
            }
        for(int j = 1; j < 4; j++)
            for(int k = 0; k < 4; k++)
                for(int l = 0; l < 4; l++) {
                    item[i][0][j][k][l] = item[i][0][j - 1][4 - l - 1][k];
                    item[i][1][j][k][l] = item[i][1][j - 1][4 - l - 1][k];
                }
    }

    cout << solve(0);

	return 0;
}
