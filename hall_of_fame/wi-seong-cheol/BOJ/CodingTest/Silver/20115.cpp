//
//  20115.cpp
//  main
//
//  Created by wi_seong on 2023/02/10.
//

/*
 [Input]
 5
 3 2 10 9 6
 [Output]
 20
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Silver 3
// Timer: 10m
// Url: https://www.acmicpc.net/problem/20115

#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
int n;
double ans;
double a[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << fixed;
    cout.precision(5);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= 2;
    }
    sort(a, a + n);
    for(int i = 0; i < n - 1; i++)
        ans += a[i] / 2;
    ans += a[n - 1];
    cout << ans / 2;
    
    return 0;
}
