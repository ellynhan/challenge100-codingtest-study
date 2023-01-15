//
//  9084.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 3
 2
 1 2
 1000
 3
 1 5 10
 100
 2
 5 7
 22
 [Output]
 501
 121
 1
 */
// 시간복잡도: O(n * m)
// 최악시간: 200,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/9084

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int a[21];
int d[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        cin >> m;
        fill(d, d + 10001, 0);
        d[0] = 1;
        for(int i = 0; i < n; i++)
            for(int j = a[i]; j <= m; j++)
                d[j] += d[j - a[i]];
        cout << d[m] << '\n';
    }
    
    return 0;
}
