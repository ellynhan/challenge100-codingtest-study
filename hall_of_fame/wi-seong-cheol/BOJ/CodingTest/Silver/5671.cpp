//
//  5671.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/13.
//

/*
 [Input]
 87 104
 989 1022
 22 25
 1234 1234
 [Output]
 14
 0
 3
 1
 */
// 시간복잡도: O(n^len(n))
// 최악시간: 20,000
// 난이도: Silver 5
// Timer: 10m
// Url: https://www.acmicpc.net/problem/5671

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int number[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> n >> m) {
        int ans = 0;
        for(int i = n; i <= m; i++) {
            fill(number, number + 10, 0);
            int tmp = i;
            bool chk = false;
            while(tmp) {
                if(number[tmp % 10]) {
                    chk = true;
                    break;
                }
                number[tmp % 10]++;
                tmp /= 10;
            }
            if(chk) continue;
            ans++;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
