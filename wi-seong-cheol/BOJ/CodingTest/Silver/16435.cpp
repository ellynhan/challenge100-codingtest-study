//
//  16435.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/24.
//

/*
 [Input]
 3 10
 10 11 13
 [Output]
 12
 */
// 시간복잡도: O(nlogn)
// 최악시간: 40,000
// 난이도: Silver 5
// Timer: 15m
// Url: https://www.acmicpc.net/problem/16435

#include <iostream>
#include <algorithm>

using namespace std;
int n, len;
int a[1001];
int d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> len;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        if(a[i] > len) break;
        len++;
    }
    cout << len;
    
    return 0;
}
