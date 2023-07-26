//
//  22862.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 8 2
 1 2 3 4 5 6 7 8
 [Output]
 3
 */
// 시간복잡도: O(n)
// 최악시간: 2,000,000
// 난이도: Gold 5
// Timer: 10m
// Url: https://www.acmicpc.net/problem/22862

#include <iostream>
#include <algorithm>

using namespace std;
int n, k;
int a[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int en = 0;
    int ans = 0;
    int cnt = 0;
    if(a[0] % 2 != 0) cnt++;
    for(int st = 0; st < n; st++) {
        while(en < n - 1 && cnt + a[en + 1]%2 <= k) {
            en++;
            cnt += a[en] % 2;
        }
        ans = max(ans, en - st + 1 - cnt);
        cnt -= a[st] % 2;
    }
    cout << ans;
    
    return 0;
}
