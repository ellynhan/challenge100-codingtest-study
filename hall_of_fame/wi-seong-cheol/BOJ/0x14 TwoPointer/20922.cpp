//
//  20922.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 9 2
 3 2 5 5 6 4 4 5 7
 [Output]
 7
 */
// 시간복잡도: O(n)
// 최악시간: 200,000
// 난이도: Silver 1
// Timer: 10m
// Url: https://www.acmicpc.net/problem/20922

#include <iostream>
#include <algorithm>

using namespace std;
int n, k;
int a[200001];
int check[200001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    int en = 0;
    int ans = 0;
    for(int st = 0; st < n; st++) {
        while(en < n && check[a[en]] + 1 <= k) {
            check[a[en++]]++;
        }
        ans = max(ans, en - st);
        check[a[st]]--;
    }
    cout << ans;
    
    return 0;
}
