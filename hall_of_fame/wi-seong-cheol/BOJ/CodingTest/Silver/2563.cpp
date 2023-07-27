//
//  2563.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/27.
//

/*
 [Input]
 3
 3 7
 15 7
 5 2
 [Output]
 260
 */
// 시간복잡도: O(n * n)
// 최악시간: 10,000
// 난이도: Silver 5
// Timer: 5m
// Url: https://www.acmicpc.net/problem/2563

#include <iostream>

using namespace std;
int t, a, b, ans;
int board[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        cin >> a >> b;
        for(int i = b; i < b + 10; i++)
            for(int j = a; j < a + 10; j++)
                board[i][j] = 1;
    }
    
    for(int i = 1; i <= 100; i++)
        for(int j = 1; j <= 100; j++)
            ans += board[i][j];
    cout << ans;
    
    return 0;
}
