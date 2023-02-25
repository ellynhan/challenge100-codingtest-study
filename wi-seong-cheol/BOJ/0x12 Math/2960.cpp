//
//  2960.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 15
 [Output]
 12
 */
// 시간복잡도: O(n^2)
// 최악시간: 1,000,000
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/2960

#include <iostream>
#include <vector>

using namespace std;
int n, k;
vector<bool> isPrime(1001, true);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    
    for(int i = 2; i <= n; i++) {
        if(!isPrime[i]) continue;
        for(int j = i; j <= n; j += i) {
            if(!isPrime[j]) continue;
            k--;
            isPrime[j] = false;
            if(k == 0) {
                cout << j;
                return 0;
            }
        }
    }
    
    return 0;
}
