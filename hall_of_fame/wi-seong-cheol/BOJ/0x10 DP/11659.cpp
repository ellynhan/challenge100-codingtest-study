//
//  11659.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 5 3
 5 4 3 2 1
 1 3
 2 4
 5 5
 [Output]
 12
 9
 1
 */
// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: Silver 3
// Timer: 2m
// Url: https://www.acmicpc.net/problem/11659

#include <iostream>

using namespace std;
int n, m;
int d[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        d[i] = d[i - 1] + x;
    }
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        cout << d[b] - d[a - 1] << '\n';
    }
    
    return 0;
}
