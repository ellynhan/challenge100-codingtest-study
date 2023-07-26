//
//  16967.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/20.
//

/*
 [Input]
 2 4 1 1
 1 2 3 4 0
 5 7 9 11 4
 0 5 6 7 8
 [Output]
 1 2 3 4
 5 6 7 8
 */
// 시간복잡도: O(n * m)
// 최악시간: 360,000
// 난이도: Silver 3
// Timer: 20m
// Url: https://www.acmicpc.net/problem/5214

#include <iostream>

using namespace std;
int h, w, x, y;
int a[601][601];
int b[601][601];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> h >> w >> x >> y;
    for(int i = 0; i < h + x; i++)
        for(int j = 0; j < w + y; j++)
            cin >> b[i][j];
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(i >= x && j >= y) {
                a[i][j] = b[i][j] - a[i - x][j - y];
            } else {
                a[i][j] = b[i][j];
            }
        }
    }
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    
    return 0;
}
