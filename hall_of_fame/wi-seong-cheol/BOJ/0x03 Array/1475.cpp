//
//  1475.cpp
//  AlgorithmChallenge
//
//  Created by wi_seong on 2022/11/06.
//

/*
 [Input]
 9999
 [Output]
 2
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Silver 5
// Timer: 5m
// Url: https://www.acmicpc.net/problem/1475

#include <iostream>
#include <algorithm>

using namespace std;

int ans;
int arr[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    while(n) {
        arr[n % 10]++;
        n /= 10;
    }
        
    for(int i = 0; i < 10; i++) {
        if(i == 6 || i == 9) continue;
        ans = max(ans, arr[i]);
    }
    cout << max(ans, (arr[6] + arr[9] + 1) / 2);
    
    return 0;
}
