//
//  3020.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/07.
//

/*
 [Input]
 6 7
 1
 5
 3
 3
 5
 1
 [Output]
 2 3
 */
// 시간복잡도: O(n)
// 최악시간: 2,000,000
// 난이도: Gold 5
// Timer: 20m
// Url: https://www.acmicpc.net/problem/3020

#include <iostream>
#include <algorithm>

using namespace std;
int n, h, st, en, len, mn, cnt;
int d[500001];

// dp로 구간의 합을 구함
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> h;
    for(int i = 0; i < n; i++) {
        cin >> len;
        if(i % 2 == 0) {    // 종유석
            st = h - len;
            en = h;
            d[st] += 1;
            d[en] -= 1;
        } else {            // 석순
            st = 0;
            en = len;
            d[st] += 1;
            d[en] -= 1;
        }
    }
    for(int i = 1; i < h; i++)
        d[i] += d[i - 1];
    mn = *min_element(d, d + h);
    for(int i = 0; i < h; i++)
        if(d[i] == mn) cnt++;
    cout << mn << ' ' << cnt;
    
    return 0;
}
