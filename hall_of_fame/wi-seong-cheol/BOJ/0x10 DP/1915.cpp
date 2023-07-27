//
//  1915.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 4 4
 0100
 0111
 1110
 0010
 [Output]
 4
 */
// 시간복잡도: O(n * m)
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 5m
// Url: https://www.acmicpc.net/problem/1915

#include <iostream>
#include <algorithm>

using namespace std;
int n, m, ans;
char board[1001][1001];
int d[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> board[i][j];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(board[i][j] == '1') {
                d[i][j] += min({d[i - 1][j - 1], d[i - 1][j], d[i][j - 1]}) + 1;
                ans = max(ans, d[i][j]);
            }
        }
    }
    cout << ans * ans;
    
    return 0;
}
