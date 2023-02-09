//
//  1010.cpp
//  main
//
//  Created by wi_seong on 2023/02/08.
//

/*
 [Input]
 3
 2 2
 1 5
 13 29
 [Output]
 1
 5
 67863915
 */
// 시간복잡도: O(n)
// 최악시간: 30
// 난이도: Silver 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1010

#include <iostream>

using namespace std;
int t, n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        cin >> n >> m;
        int res = 1;
        int tmp = 1;
        
        for(int i = m; i > m - n; i--) {
            res *= i;
            res /= tmp++;
        }
        cout << res << '\n';
    }
    
    return 0;
}
