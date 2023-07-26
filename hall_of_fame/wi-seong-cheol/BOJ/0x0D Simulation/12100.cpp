//
//  12100.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 3
 2 2 2
 4 4 4
 8 8 8
 [Output]
 16
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 204,800
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/12100

#include <iostream>
#include <vector>

using namespace std;
int mx, n;
int board1[21][21];
int board2[21][21];

void rotate() {
    int tmp[21][21];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            tmp[i][j] = board2[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board2[i][j] = tmp[n - 1 - j][i];
}

void tilt(int dir) {
    while(dir--) rotate();
    for(int i = 0; i < n; i++) {
        int tilted[21] = {};
        int idx = 0;
        for(int j = 0; j < n; j++) {
            if(board2[i][j] == 0) continue;
            if(tilted[idx] == 0)
                tilted[idx] = board2[i][j];
            else if(tilted[idx] == board2[i][j])
                tilted[idx++] *= 2;
            else
                tilted[++idx] = board2[i][j];
        }
        for(int j = 0; j < n; j++) board2[i][j] = tilted[j];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board1[i][j];
    for(int tmp = 0; tmp < 1024; tmp++) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                board2[i][j] = board1[i][j];
        int brute = tmp;
        for(int i = 0; i < 5; i++) {
            int dir = brute % 4;
            brute /= 4;
            tilt(dir);
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                mx = max(mx, board2[i][j]);
    }
    cout << mx;
    
    return 0;
}
