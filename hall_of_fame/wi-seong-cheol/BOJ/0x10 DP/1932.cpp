//
//  1932.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 5
 7
 3 8
 8 1 0
 2 7 4 4
 4 5 2 6 5
 [Output]
 30
 */
// 시간복잡도: O(n^2)
// 최악시간: 125,250
// 난이도: Silver 1
// Timer: 8m
// Url: https://www.acmicpc.net/problem/1932

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int d[501][501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j < i + 1; j++)
            cin >> d[i][j];
    for(int i = 2; i <= n; i++)
        for(int j = 1; j < i + 1; j++)
            d[i][j] += max(d[i - 1][j - 1], d[i - 1][j]);
    cout << *max_element(d[n], d[n] + n + 1);
    
    return 0;
}
