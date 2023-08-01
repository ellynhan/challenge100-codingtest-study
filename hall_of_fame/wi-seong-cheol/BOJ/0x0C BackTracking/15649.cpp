//
//  15649.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/22.
//

/*
 [Input]
 3 1
 [Output]
 1
 2
 3
 */
// 시간복잡도: O(n ^ n)
// 최악시간: 16,777,216
// 난이도: Silver 3
// Timer: 7m
// Url: https://www.acmicpc.net/problem/15649

#include <iostream>

using namespace std;
int n, m;
int arr[10];
bool isused[10];

void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    
    for(int i = 1; i <= n; i++) {
        if(!isused[i]) {
            isused[i] = true;
            arr[k] = i;
            func(k + 1);
            isused[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    func(0);
    
    return 0;
}
