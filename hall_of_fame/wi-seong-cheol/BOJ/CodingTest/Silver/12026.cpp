//
//  12026.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/24.
//

/*
 [Input]
 15
 BJBOJOJOOJOBOOO
 [Output]
 52
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/12026

#include <iostream>
#include <algorithm>

using namespace std;
int n;
char a[1001];
int d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++) {
        char prev;
        if(a[i] == 'B') prev = 'J';
        else if(a[i] == 'O') prev = 'B';
        else prev = 'O';
        for(int j = 0; j < i; j++) {
            if(a[j] != prev) continue;
            if(d[j] == 0 && j != 0) continue;
            if(d[i] == 0)
                d[i] = d[j] + (i - j) * (i - j);
            else
                d[i] = min(d[i], d[j] + (i - j) * (i - j));
        }
    }
    if(d[n - 1] == 0) cout << -1;
    else cout << d[n - 1];
    
    return 0;
}
