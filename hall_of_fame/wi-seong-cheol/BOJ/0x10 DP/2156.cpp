//
//  1463.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 6
 6
 10
 13
 9
 8
 1
 [Output]
 33
 */
// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: Silver 1
// Timer: 10m
// Url: https://www.acmicpc.net/problem/2156

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[10001];
int d[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    
    d[1] = arr[1]; d[2] = arr[1] + arr[2];
    for(int i = 3; i <= n; i++)
        d[i] = max({d[i - 1], d[i - 2] + arr[i], d[i - 3] + arr[i - 1] + arr[i]});
    
    cout << d[n];
    return 0;
}
