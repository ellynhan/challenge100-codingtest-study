//
//  1019.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 11
 [Output]
 1 4 1 1 1 1 1 1 1 1
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000,000
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1019

#include <iostream>

using namespace std;
int n;
int cnt[10];

void subCounting(int num, int tenPower) {
    while (num) {
        cnt[num % 10] += tenPower;
        num /= 10;
    }
}

void solve() {
    int start = 1;
    int tenPower = 1;
    
    while(start <= n) {
        while(0 != start % 10 && start <= n) {
            subCounting(start, tenPower);
            start++;
        }
        if(n < start) return;
        while(9 != n % 10 && start <= n) {
            subCounting(n, tenPower);
            n--;
        }
        start /= 10;
        n /= 10;
        for(int i = 0; i < 10; i++)
            cnt[i] += (n - start + 1) * tenPower;
        tenPower *= 10;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    solve();
    for(int i = 0; i < 10; i++)
        cout << cnt[i] << ' ';
    
    return 0;
}
