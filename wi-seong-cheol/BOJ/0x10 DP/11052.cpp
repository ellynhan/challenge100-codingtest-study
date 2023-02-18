//
//  11052.cpp
//  main
//
//  Created by wi_seong on 2022/12/24.
//

/*
 [Input]
 4
 1 5 6 7
 [Output]
 10
 */
// 시간복잡도: O(n)
// 최악시간: 500,500
// 난이도: Silver 1
// Timer: 20m
// Url: https://www.acmicpc.net/problem/11052

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> d[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            d[i] = max(d[i], d[i - j] + d[j]);
    cout << d[n];
    
    return 0;
}
