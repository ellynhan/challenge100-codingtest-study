//
//  3085.cpp
//  main
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 5
 YCPZY
 CYZZP
 CCPPP
 YCYZC
 CPPZZ
 [Output]
 4
 */
// 시간복잡도: O(n ^ 5)
// 최악시간: 312,500,000
// 난이도: Silver 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/3085

#include <iostream>
#include <algorithm>

using namespace std;
int ans;
int n;
char board[51][51];

int solve() {
    int ret = 1;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int len = 1;
            for(int k = j + 1; k < n; k++) {
                if(board[i][j] != board[i][k]) break;
                len++;
            }
            ret = max(ret, len);
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int len = 1;
            for(int k = i + 1; k < n; k++) {
                if(board[i][j] != board[k][j]) break;
                len++;
            }
            ret = max(ret, len);
        }
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i < n - 1 && board[i][j] != board[i + 1][j]) {
                swap(board[i][j], board[i + 1][j]);
                ans = max(ans, solve());
                swap(board[i][j], board[i + 1][j]);
            }
            
            if(j < n - 1 && board[i][j] != board[i][j + 1]) {
                swap(board[i][j], board[i][j + 1]);
                ans = max(ans, solve());
                swap(board[i][j], board[i][j + 1]);
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
