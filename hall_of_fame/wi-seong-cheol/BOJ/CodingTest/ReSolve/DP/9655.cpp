//
//  9655.cpp
//  main
//
//  Created by wi_seong on 3/14/24.
//

/*
 [Input]
 5
 [Output]
 SK
 */
// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: Silver 5
// Timer: 4m
// Url: https://www.acmicpc.net/problem/9655

#include <iostream>
#include <cstring>

using namespace std;
int n;
int cache[1001];

int solve(int turn, int k) {
    if(k == 0) return turn % 2;
    int& ret = cache[k];
    if(ret != -1) return ret;

    if(k >= 3) {
        ret = solve(turn + 1, k - 3);
    }
    if(k >= 1) {
        ret = solve(turn + 1, k - 1);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(cache, -1, sizeof(cache));
    cin >> n;
    if(solve(0, n)) cout << "SK";
    else cout << "CY";

    return 0;
}
