//
//  .cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 5 4
 2
 8
 10
 7
 [Output]
 7 21
 */
// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1246

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int arr[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> arr[i];
    sort(arr, arr + m);
    int ans = 0;
    int price = 0;
    for(int i = 0; i < m; i++) {
        int cnt = (m - i) <= n ? (m - i) : n;
        if(ans < arr[i] * cnt) {
            price = arr[i];
            ans = arr[i] * cnt;
        }
    }
    cout << price << ' ' << ans;
    
    return 0;
}
