//
//  2293.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 3 10
 1
 2
 5
 [Output]
 10
 */
// 시간복잡도: O(n * k)
// 최악시간: 1,000,000
// 난이도: Gold 5
// Timer: 20m
// Url: https://www.acmicpc.net/problem/2293

#include <iostream>

using namespace std;
int n, k;
int arr[101];
int d[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    d[0] = 1;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        for(int j = arr[i]; j <= k; j++)
            d[j] += d[j - arr[i]];
    cout << d[k];
    
    return 0;
}
