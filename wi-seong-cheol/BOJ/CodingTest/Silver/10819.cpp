//
//  10819.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/07.
//

/*
 [Input]
 6
 20 1 15 8 4 10
 [Output]
 62
 */
// 시간복잡도: O(2 ^ n)
// 최악시간: 256
// 난이도: Silver 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/10819

#include <iostream>
#include <algorithm>

using namespace std;
int n, ans;
int a[9];
int isused[9];

// 백트랙킹으로 정수의 순서를 조정
void solve(int k, int sum, int prev) {
    if(k == n) {
        ans = max(ans, sum);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!isused[i]) {
            isused[i] = true;
            if(k == 0)
                solve(k + 1, sum, a[i]);
            else
                solve(k + 1, sum + abs(prev - a[i]), a[i]);
            isused[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    solve(0, 0, 0);
    cout << ans;
    
    return 0;
}
