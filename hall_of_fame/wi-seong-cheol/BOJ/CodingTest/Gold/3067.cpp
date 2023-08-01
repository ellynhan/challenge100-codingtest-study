//
//  3067.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/13.
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
// 시간복잡도: O(n ^ 2)
// 최악시간: 100,000,000
// 난이도: Gold 5
// Timer: 40m
// Url: https://www.acmicpc.net/problem/3067

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int t, n, m;
vector<int> coin;
int d[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        coin.clear();
        coin.resize(n);
        for(int i = 0; i < n; i++)
            cin >> coin[i];
        cin >> m;
        fill(d, d + m + 1, 0);
        d[0] = 1;
        for(int i = 0; i < n; i++)
            for(int j = coin[i]; j <= m; j++)
                d[j] += d[j - coin[i]];
        cout << d[m] << '\n';
    }
    
    return 0;
}
