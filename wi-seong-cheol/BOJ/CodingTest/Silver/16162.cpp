//
//  16162.cpp
//  main
//
//  Created by wi_seong on 2023/02/25.
//

/*
 [Input]
 3 1 2
 [Output]
 1 3 5
 */
// 시간복잡도: O(n^2)
// 최악시간: 400,000,000
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/16162

#include <iostream>

using namespace std;
int n, st, d;
int a[20001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> st >> d;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] != st) continue;
        ans++;
        int nxt = a[i] + d;
        for(int j = i + 1; j < n; j++) {
            if(a[j] == nxt) {
                ans++;
                nxt += d;
            }
        }
        if(a[i] == st) break;
    }
    cout << ans;
    
    return 0;
}
