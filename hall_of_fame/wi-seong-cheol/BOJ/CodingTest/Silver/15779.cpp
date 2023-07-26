//
//  15779.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/16.
//

/*
 [Input]
 5
 1 3 4 2 5
 [Output]
 2
 */
// 시간복잡도: O(n)
// 최악시간: 5,000
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/15779

#include <iostream>
#include <algorithm>

using namespace std;
int n, ans;
int a[5001];
int len[5001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 2; i < n; i++) {
        if(a[i - 2] <= a[i - 1] && a[i - 1] <= a[i]) continue;
        if(a[i - 2] >= a[i - 1] && a[i - 1] >= a[i]) continue;
        len[i] = len[i - 1] + 1;
    }
    cout << *max_element(len, len + n) + 2;
    
    return 0;
}
