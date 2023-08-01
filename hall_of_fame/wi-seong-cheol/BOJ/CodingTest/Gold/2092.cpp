//
//  2092.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/21.
//

/*
 [Input]
 3 5 2 3
 1 2 2 1 3
 [Output]
 10
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 160,000,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2092

#include <iostream>
#include <algorithm>

using namespace std;
const int mod = 1000000;
int ans;
int T, A, S, B;
int a[201];
int d[201][4001];

void solve() {
    d[0][0] = 1;

    for(int i = 1; i <= T; i++) {
        for(int j = 0; j <= A; j++) {
            for(int k = 0; k <= a[i] && j >= k; k++) {
                d[i][j] = (d[i][j] + d[i - 1][j - k]) % mod;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T >> A >> S >> B;
    for(int i = 0; i < A; i++) {
        int num; cin >> num;
        a[num]++;
    }
    solve();
    for(int i = S; i <= B; i++)
        ans = (ans + d[T][i]) % mod;
    cout << ans;

    return 0;
}
