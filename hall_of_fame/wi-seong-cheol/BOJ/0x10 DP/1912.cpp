//
//  1912.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 10
 10 -4 3 1 5 6 -35 12 21 -1
 [Output]
 33
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 2
// Timer: 5m
// Url: https://www.acmicpc.net/problem/1912

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int d[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> d[i];
    for(int i = 1; i < n; i++)
        d[i] += max(0, d[i - 1]);
    cout << *max_element(d, d + n);
    
    return 0;
}
