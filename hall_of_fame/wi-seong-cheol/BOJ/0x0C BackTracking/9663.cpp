//
//  9663.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/22.
//

/*
 [Input]
 8
 [Output]
 92
 */
// 시간복잡도: O(n^n)
// 최악시간: 4.3789389e+17
// 난이도: Gold 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/9663

#include <iostream>

using namespace std;
int ans, n;
bool isused1[40];
bool isused2[40];
bool isused3[40];

void func(int k) {
    if(k == n) {
        ans++;
        return;
    }
    
    for(int i = 0; i < n; i++) {
        if(isused1[i] || isused2[k + i] || isused3[k - i + n - 1]) continue;
        isused1[i] = true;
        isused2[k + i] = true;
        isused3[k - i + n - 1] = true;
        func(k + 1);
        isused1[i] = false;
        isused2[k + i] = false;
        isused3[k - i + n - 1] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    func(0);
    cout << ans;
    
    return 0;
}
