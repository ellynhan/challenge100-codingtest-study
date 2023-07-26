//
//  10942.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 7
 1 2 1 3 1 2 1
 4
 1 3
 2 5
 3 3
 5 7
 [Output]
 1
 0
 1
 1
 */
// 시간복잡도: O(nm)
// 최악시간: 4,000,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/10942

#include <iostream>

using namespace std;
int n, m, st, en;
int a[2001];
int d[2001][2001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i][i] = 1;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= n - i; j++) {
            if(a[j] == a[j + i] && (i == 1 || d[j + 1][j + i - 1] == 1))
                d[j][j + i] = 1;
        }
    }
    cin >> m;
    while(m--) {
        cin >> st >> en;
        cout << d[st][en] << '\n';
    }
    
    return 0;
}
