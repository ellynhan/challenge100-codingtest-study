//
//  21758.cpp
//  main
//
//  Created by wi_seong on 2023/04/06.
//

/*
 [Input]
 3
 2 5 4
 [Output]
 10
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Gold 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/21758

#include <iostream>
#include <algorithm>

using namespace std;
int ans;
int n;
int a[100001];
int sum[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
    }
    for(int i = 2; i < n; i++) {    // 벌 / 벌 / 꿀통
        ans = max(ans, sum[n] - a[1] - a[i] + sum[n] - sum[i]);
    }
    for(int i = 2; i < n; i++) {    // 벌 / 꿀통 / 벌
        ans = max(ans, sum[i] - a[1] + sum[n - 1] - sum[i - 1]);
    }
    for(int i = 2; i < n; i++) {    // 꿀통 / 벌 / 벌
        ans = max(ans, sum[i - 1] + sum[n - 1] - a[i]);
    }
    cout << ans;
    
    return 0;
}
