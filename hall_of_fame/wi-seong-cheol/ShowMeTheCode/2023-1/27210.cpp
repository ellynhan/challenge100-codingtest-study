//
//  27210.cpp
//  main
//
//  Created by wi_seong on 2023/01/14.
//

/*
 [Input]
 10
 1 2 1 1 2 2 2 2 1 1
 [Output]
 4
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Gold 5
// Timer: 4h
// Url: https://www.acmicpc.net/problem/27210

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int a[100001];
int d[100001][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(a[0] == 1)
        d[0][0] = 1;
    else
        d[0][1] = 1;
    int ans = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] == 1) {
            d[i][0] = d[i - 1][0] + 1;
            d[i][1] = max(0, d[i - 1][1] - 1);
        } else {
            d[i][1] = d[i - 1][1] + 1;
            d[i][0] = max(0, d[i - 1][0] - 1);
        }
        ans = max(ans, abs(d[i][0] - d[i][1]));
    }
    cout << ans << '\n';

    return 0;
}
