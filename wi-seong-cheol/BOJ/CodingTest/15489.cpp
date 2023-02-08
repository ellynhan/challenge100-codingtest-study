//
//  15489.cpp
//  main
//
//  Created by wi_seong on 2023/02/08.
//

/*
 [Input]
 3 1 4
 [Output]
 42
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 900
// 난이도: Silver 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/15489

#include <iostream>

using namespace std;
int r, c, w, ans;
int d[31][31];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c >> w;
    for(int i = 1; i < 31; i++) {
        for(int j = 1; j <= i; j++) {
            if(i == 1 || j == 1) d[i][j] = 1;
            else d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
        }
    }
    for(int i = r; i < r + w; i++)
        for(int j = c; j <= c + i - r; j++)
            ans += d[i][j];
    cout << ans;
    
    return 0;
}
