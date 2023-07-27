//
//  1806.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 10 15
 5 1 3 5 10 7 4 9 2 8
 [Output]
 2
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Gold 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1806

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int a[100001];
int ans = 0x7fffffff;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int en = 0;
    int sum = a[0];
    for(int st = 0; st < n; st++) {
        while(en < n && sum < m) {
            en++;
            if(en != n) sum += a[en];
        }
        if(en == n) break;
        ans = min(ans, en - st + 1);
        sum -= a[st];
    }
    if(ans == 0x7fffffff) ans = 0;
    cout << ans;
    
    return 0;
}
