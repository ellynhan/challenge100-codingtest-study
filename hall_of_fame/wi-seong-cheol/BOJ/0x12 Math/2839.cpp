//
//  2839.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 18
 [Output]
 4
 */
// 시간복잡도: O(n / 5)
// 최악시간: 1000
// 난이도: Silver 4
// Timer: 20m
// Url: https://www.acmicpc.net/problem/2839

#include <iostream>

using namespace std;
int n, cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i <= n / 5; i++)
        if((n - (5 * i)) % 3 == 0)
            cnt = i + (n - (5 * i)) / 3;
    
    if(cnt == 0) cout << -1;
    else cout << cnt;
    
    return 0;
}
