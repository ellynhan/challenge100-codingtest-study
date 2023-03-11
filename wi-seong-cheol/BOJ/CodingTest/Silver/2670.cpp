//
//  2670.cpp
//  main
//
//  Created by wi_seong on 2023/02/08.
//

/*
 [Input]
 8
 1.1
 0.7
 1.3
 0.9
 1.4
 0.8
 0.7
 1.4
 [Output]
 1.638
 */
// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: Silver 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2670

#include <iostream>
#include <algorithm>

using namespace std;
int n;
double a[10001];
double d[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << fixed;
    cout.precision(3);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        d[i] = a[i];
    }
    for(int i = 0; i < n; i++)
        d[i] = max(d[i], d[i - 1] * a[i]);
    
    cout << *max_element(d, d + n);
    
    return 0;
}
