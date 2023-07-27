//
//  2230.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 3 3
 1
 5
 3
 [Output]
 4
 */
// 시간복잡도: O(n)
// 최악시간: 200,000
// 난이도: Gold 5
// Timer: 10m
// Url: https://www.acmicpc.net/problem/2230

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int ans = 0x7fffffff;
int a[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int en = 0;
    for(int st = 0; st < n; st++) {
        while(en < n && a[en] - a[st] < m) en++;
        if(en == n) break;
        ans = min(ans, a[en] - a[st]);
    }
    cout << ans;
    
    return 0;
}
