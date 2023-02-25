//
//  2294.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 3 15
 1
 5
 12
 [Output]
 3
 */
// 시간복잡도: O(n^2)
// 최악시간: 100,000,000
// 난이도: Gold 5
// Timer: 20m
// Url: https://www.acmicpc.net/problem/2294

#include <iostream>
#include <algorithm>

using namespace std;
int n, k;
int a[10001];
int d[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    fill(d, d + k + 1, 10001);
    d[0] = 0;
    for(int i = 0; i < n; i++)
        for(int j = a[i]; j <= k; j++)
            d[j] = min(d[j], d[j - a[i]] + 1);
    cout << (d[k] == 10001 ? -1 : d[k]);
    
    return 0;
}
