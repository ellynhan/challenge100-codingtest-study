//
//  9372.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 2
 3 3
 1 2
 2 3
 1 3
 5 4
 2 1
 2 3
 4 3
 4 5
 [Output]
 2
 4
 */
// 시간복잡도: O(1)
// 최악시간: 1
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/9372

#include <iostream>

using namespace std;
int t, a, b, n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        cin >> n >> m;
        while(m--)
            cin >> a >> b;
        cout << (n - 1) << '\n';
    }
    
    return 0;
}
