//
//  1817.cpp
//  main
//
//  Created by wi_seong on 2023/02/25.
//

/*
 [Input]
 11 12
 12 1 11 2 10 3 4 5 6 6 1
 [Output]
 6
 */
// 시간복잡도: O(n)
// 최악시간: 50
// 난이도: Silver 5
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1817

#include <iostream>

using namespace std;
int n, m, x, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(sum + x > m) {
            ans++;
            sum = 0;
        }
        sum += x;
    }
    if(sum != 0) ans++;
    cout << ans;
    
    return 0;
}
