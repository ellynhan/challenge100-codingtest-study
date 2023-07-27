//
//  14916.cpp
//  main
//
//  Created by wi_seong on 2023/02/09.
//

/*
 [Input]
 14
 [Output]
 4
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 5
// Timer: 15m
// Url: https://www.acmicpc.net/problem/14916

#include <iostream>

using namespace std;
int n, cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    while(n) {
        if(n == 1) break;
        if(n % 5 == 0) {
            cnt += n / 5;
            n %= 5;
        } else {
            cnt++;
            n -= 2;
        }
    }
    
    if(n == 1) cout << -1;
    else cout << cnt;
    
    return 0;
}
