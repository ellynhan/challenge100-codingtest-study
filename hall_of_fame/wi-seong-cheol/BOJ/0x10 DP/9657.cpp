//
//  9657.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 6
 [Output]
 SK
 */
// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: Silver 3
// Timer: 10m
// Url: https://www.acmicpc.net/problem/9657

#include <iostream>

using namespace std;
int n;
string ans[] = {"SK", "CY"};
int cand[] = {1, 3, 4};
int d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    d[1] = 0; d[2] = 1; d[3] = 0; d[4] = 0;
    for(int i = 5; i <= n; i++) {
        for(int j : cand) {
            if(d[i - j] == 1) {
                d[i] = 0;
                break;
            }
            else d[i] = 1;
        }
    }
    cout << ans[d[n]];
    
    return 0;
}
