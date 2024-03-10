//
//  1789.cpp
//  main
//
//  Created by wi_seong on 3/7/24.
//

/*
 [Input]
 200
 [Output]
 19
 */
// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: Silver 5
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1789

#include <iostream>

using namespace std;
long long s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    int cnt = 0;
    int val = 1;
    while(true) {
        if(s - val < 0) break;
        s -= val++;
        cnt++;
    }
    cout << cnt;

    return 0;
}
