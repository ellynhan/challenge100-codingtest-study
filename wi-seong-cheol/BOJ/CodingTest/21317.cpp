//
//  21317.cpp
//  main
//
//  Created by wi_seong on 2023/02/08.
//

/*
 [Input]
 5
 1 2
 2 3
 4 5
 6 7
 4
 [Output]
 5
 */
// 시간복잡도: O(n)
// 최악시간: 20
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/21317

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
int n, k;
int d[21][2];
int smallJump[21];
int bigJump[21];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i < n; i++)
        cin >> smallJump[i] >> bigJump[i];
    cin >> k;
    for(int i = 0; i <= n; i++)
        d[i][0] = d[i][1] = INF;
    d[1][0] = 0;
    d[2][0] = smallJump[1];
    d[3][0] = min(d[2][0] + smallJump[2], bigJump[1]);
    for(int i = 4; i <= n; i++) {
        d[i][0] = min(d[i - 1][0] + smallJump[i - 1], d[i - 2][0] + bigJump[i - 2]);
        d[i][1] = min({d[i - 1][1] + smallJump[i - 1], d[i - 2][1] + bigJump[i - 2], d[i - 3][0] + k});
    }
    cout << min(d[n][0], d[n][1]);

    return 0;
}
