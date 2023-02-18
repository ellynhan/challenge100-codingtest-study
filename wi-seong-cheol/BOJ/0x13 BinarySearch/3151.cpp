//
//  3151.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 10
 2 -5 2 3 -4 7 -4 0 1 -6
 [Output]
 6
 */
// 시간복잡도: O(n^2 * logn)
// 최악시간: 500,000,000
// 난이도: Gold 4
// Timer: 40m
// Url: https://www.acmicpc.net/problem/3151

#include <iostream>
#include <algorithm>

using namespace std;
int n;
long cnt;
int a[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            int tmp = (-1) * (a[i] + a[j]);
            long first = lower_bound(a + j + 1, a + n, tmp) - a;
            long last = upper_bound(a + j + 1, a + n, tmp) - a;
            cnt += last - first;
        }
    }
    cout << cnt;
    
    return 0;
}
