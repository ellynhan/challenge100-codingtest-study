//
//  2208.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/08.
//

/*
 [Input]
 8 4
 -1
 -1
 1
 1
 1
 1
 -1
 2
 [Output]
 5
 */
// 시간복잡도: O(n)
// 최악시간: 300,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2208

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int a[100001];
int bucket[100001];
int d[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    int added = 0;
    for(int i = 1; i <= m; i++)
        added += a[i];
    
    bucket[m] = added;
    d[m] = added;
    
    int ans = added;
    
    for(int i = m + 1; i <= n; i++)
        bucket[i] = bucket[i - 1] - a[i - m] + a[i];
    
    for(int i = m + 1; i <= n; i++) {
        d[i] = max(d[i - 1] + a[i], bucket[i]);
        ans = max(d[i], ans);
    }
    if(ans < 0) ans = 0;
    cout << ans;
    
    return 0;
}
