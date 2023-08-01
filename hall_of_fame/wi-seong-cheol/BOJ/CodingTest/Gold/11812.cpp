//
//  11812.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/22.
//

/*
 [Input]
 7 2 3
 1 2
 2 1
 4 7
 [Output]
 1
 1
 4
 */
// 시간복잡도: O(q log_k n)
// 최악시간: 400,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/11812

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, k, q;
    cin >> n >> k >> q;

    while(q--) {
        long long x, y;
        cin >> x >> y;

        if (k == 1) {
            cout << abs(x - y) << '\n';
        } else {
            int cnt = 0;
            while(y != x) {
                if(y > x) {
                    y = (y - 2) / k + 1;
                } else {
                    x = (x - 2) / k + 1;
                }
                ++cnt;
            }
            cout << cnt << '\n';
        }
    }

    return 0;
}
