//
//  2228.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/08.
//

/*
 [Input]
 6 2
 -1
 3
 1
 2
 4
 -1
 [Output]
 9
 */
// 시간복잡도: O(n * m)
// 최악시간: 5,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2228

#include <iostream>
#include <cstring>

using namespace std;
#define MIN -3276800
int n, m;
int a[101], d[101][51];

int solve(int n, int m) {
    if(m == 0) return 0;
    if(n <= 0) return MIN;
    if(d[n][m] != -1) return d[n][m];
    
    int sum = 0;
    d[n][m] = solve(n - 1, m);
    for (int i = n; i > 0; i--){
        sum += a[i];
        int tmp = solve(i - 2, m - 1) + sum;
        d[n][m] = max(d[n][m], tmp);
    }
    return d[n][m];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    memset(d, -1, sizeof(d));
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << solve(n, m);
    
    return 0;
}
