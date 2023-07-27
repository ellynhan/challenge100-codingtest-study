//
//  2240.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 7 2
 2
 1
 1
 2
 2
 1
 1
 [Output]
 6
 */
// 시간복잡도: O(n * 2)
// 최악시간: 30,000
// 난이도: Gold 5
// Timer: 15m
// Url: https://www.acmicpc.net/problem/2240

#include <iostream>
#include <algorithm>

using namespace std;
int t, w;
int a[1001];
int d[1001][32];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t >> w;
    int cnt = 0;
    for(int i = 1; i <= t; i++) {
        cin >> a[i];
        if(a[i] == 1) cnt++;
        d[i][0] = cnt;
    }
    for(int i = 1; i <= t; i++)
        for(int j = 1; j <= w; j++)
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + (1 + j % 2 == a[i]);
    cout << *max_element(d[t], d[t] + w + 1);
    
    return 0;
}
