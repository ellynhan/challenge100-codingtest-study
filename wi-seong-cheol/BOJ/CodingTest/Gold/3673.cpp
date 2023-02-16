//
//  3673.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/16.
//

/*
 [Input]
 2
 7 3
 1 2 3
 4 8
 2 1 2 1 1 2 1 2
 [Output]
 0
 6
 */
// 시간복잡도: O(n)
// 최악시간: 10,000,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/3673

#include <iostream>
#include <cstring>

using namespace std;
#define ll long long
int t, d, n;
ll x, sum, ans;
int cnt[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        cin >> d >> n;
        memset(cnt, 0, sizeof(cnt));
        cnt[0]++;
        sum = ans = 0;
        while(n--) {
            cin >> x;
            sum += x;
            sum %= d;
            ans += cnt[sum]++;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
