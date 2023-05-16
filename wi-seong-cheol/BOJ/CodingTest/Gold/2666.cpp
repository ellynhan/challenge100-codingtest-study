//
//  2666.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/18.
//

/*
 [Input]
 7
 2 5
 4
 3
 1
 6
 5
 [Output]
 5
 */
// 시간복잡도: O(n)
// 최악시간: 20
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2666

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m, p1, p2;
int a[21];
int d[21][21][21];

int solve(int p1, int p2, int cnt) {
    if(cnt == m + 1) return 0;
    
    int& ret = d[p1][p2][cnt];
    if(ret != -1) return ret;
    ret = 0;
    ret = min(abs(a[cnt] - p1) + solve(a[cnt], p2, cnt + 1), abs(a[cnt] - p2) + solve(p1, a[cnt], cnt + 1));
    
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    memset(d, -1, sizeof(d));
    cin >> n >> p1 >> p2 >> m;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    cout << solve(p1, p2, 1);
    
    return 0;
}
