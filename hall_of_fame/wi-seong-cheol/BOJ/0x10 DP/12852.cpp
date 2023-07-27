//
//  12852.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 2
 [Output]
 1
 2 1
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Silver 1
// Timer: 10m
// Url: https://www.acmicpc.net/problem/12852

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int d[1000001];
int pre[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 2; i <= n; i++) {
        d[i] = d[i - 1] + 1;
        pre[i] = i - 1;
        if(i % 2 == 0 && d[i] > d[i / 2] + 1) {
            d[i] = d[i / 2] + 1;
            pre[i] = i / 2;
        }
        if(i % 3 == 0 && d[i] > d[i / 3] + 1) {
            d[i] = d[i / 3] + 1;
            pre[i] = i / 3;
        }
    }
    cout << d[n] << '\n';
    int cur = n;
    while(1) {
        cout << cur << ' ';
        if(cur == 1) break;
        cur = pre[cur];
    }
    
    return 0;
}
