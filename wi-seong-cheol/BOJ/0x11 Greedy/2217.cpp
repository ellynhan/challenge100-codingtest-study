//
//  .cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 2
 10
 15
 [Output]
 20
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 4
// Timer: 15m
// Url: https://www.acmicpc.net/problem/2217

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n, greater<int>());
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, arr[i] * (i + 1));
    cout << ans;
    
    return 0;
}
