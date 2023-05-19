//
//  1940.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/06.
//

/*
 [Input]
 3
 4
 1 2 3
 [Output]
 1
 */
// 시간복잡도: O(n)
// 최악시간: 15,000
// 난이도: Silver 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1940

#include <iostream>
#include <algorithm>

using namespace std;
int ans;
int n, m;
int a[15001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int st = 0;
    int en = n - 1;
    while(st < en) {
        if(a[st] + a[en] == m) ans++;
        if(a[st] + a[en] < m) st++;
        else en--;
    }
    cout << ans;
    
    return 0;
}
