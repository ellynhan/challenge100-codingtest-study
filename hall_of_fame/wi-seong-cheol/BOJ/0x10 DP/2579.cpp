//
//  2579.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 6
 10
 20
 15
 25
 10
 20
 [Output]
 75
 */
// 시간복잡도: O(n)
// 최악시간: 300
// 난이도: Silver 3
// Timer: 10m
// Url: https://www.acmicpc.net/problem/2579

#include <iostream>
#include <algorithm>

using namespace std;
int n, sum;
int arr[301];
int d[301];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    d[0] = arr[0];
    d[1] = arr[1];
    d[2] = arr[2];
    for(int i = 3; i < n - 1; i++) {
        d[i] = arr[i] + min(d[i - 2], d[i - 3]);
    }
    cout << sum - min(d[n - 2], d[n - 3]);
    return 0;
}
