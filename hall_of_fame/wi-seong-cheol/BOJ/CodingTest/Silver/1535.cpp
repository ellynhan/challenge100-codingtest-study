//
//  1535.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 
 [Output]
 
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 2,000
// 난이도: Silver 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1535

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int L[21], J[21];
int d[21][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> L[i];
    for(int i = 1; i <= n; i++)
        cin >> J[i];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < 101; j++) {
            if(L[i] >= j) {
                d[i][j] = d[i - 1][j];
            } else {
                d[i][j] = max(d[i - 1][j], d[i - 1][j - L[i]] + J[i]);
            }
        }
    }
    cout << d[n][100];
    
    
    return 0;
}
