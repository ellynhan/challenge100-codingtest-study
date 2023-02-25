//
//  1476.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 15 28 19
 [Output]
 7980
 */
// 시간복잡도: O(logn)
// 최악시간: 5
// 난이도: Silver 5
// Timer: 20m
// Url: https://www.acmicpc.net/problem/1476

#include <iostream>
#include <numeric>

using namespace std;
int e, s, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> e >> s >> m;
    e--; s--; m--;
    int i = e;
    while(i % 28 != s) i += 15;
    int l = lcm(15, 28);
    while(i % 19 != m) i += l;
    cout << i + 1;
    
    return 0;
}
