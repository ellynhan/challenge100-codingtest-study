//
//  18808.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 5 4 4
 3 3
 1 0 1
 1 1 1
 1 0 1
 2 5
 1 1 1 1 1
 0 0 0 1 0
 2 3
 1 1 1
 1 0 1
 3 3
 1 0 0
 1 1 1
 1 0 0
 [Output]
 18
 */
// 시간복잡도: O(n^5)
// 최악시간: 64,000,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/18808

#include <iostream>
#include <utility>

using namespace std;
int n, m, k, r, c;
int note[41][41];
int paper[12][12];

void paste(int x, int y) {
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(paper[i][j] == 1)
                note[x + i][y + j] = 1;
}

bool pastable(int x, int y) {
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(note[x + i][y + j] == 1 && paper[i][j] == 1)
                return false;
    return true;
}

void rotate() {
    int tmp[12][12];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            tmp[i][j] = paper[i][j];
    for(int i = 0; i < c; i++)
        for(int j = 0; j < r; j++)
            paper[i][j] = tmp[r - 1 - j][i];
    swap(r, c);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    while(k--) {
        cin >> r >> c;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cin >> paper[i][j];
        for(int rot = 0; rot < 4; rot++) {
            bool isPaste = false;
            for(int i = 0; i <= n - r; i++) {
                if(isPaste) break;
                for(int j = 0; j <= m - c; j++) {
                    if(pastable(i, j)) {
                        paste(i, j);
                        isPaste = true;
                        break;
                    }
                }
            }
            if(isPaste) break;
            rotate();
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cnt += note[i][j];
    cout << cnt;
    
    return 0;
}
