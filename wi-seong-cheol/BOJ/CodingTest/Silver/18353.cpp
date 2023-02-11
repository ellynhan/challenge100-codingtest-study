//
//  18353.cpp
//  main
//
//  Created by wi_seong on 2023/02/11.
//

/*
 [Input]
 7
 15 11 4 8 5 2 4
 [Output]
 2
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 4,000,000
// 난이도: Silver 2
// Timer: 20m
// Url: https://www.acmicpc.net/problem/18353

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int a[2001];
int d[2001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        d[i] = 1;
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            if(a[j] > a[i])
                d[j] = max(d[j], d[i] + 1);
        }
    }
    cout << n - *max_element(d, d + n);
    
    return 0;
}
