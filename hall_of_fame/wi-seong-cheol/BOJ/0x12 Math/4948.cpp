//
//  4948.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 1
 10
 13
 100
 1000
 10000
 100000
 0
 [Output]
 1
 4
 3
 21
 135
 1033
 8392
 */
// 시간복잡도: O(nloglogn)
// 최악시간: 175,000
// 난이도: Silver 2
// Timer: 10m
// Url: https://www.acmicpc.net/problem/4948

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 250000;
int n;
vector<bool> isPrime(SIZE, true);

void sieve() {
    isPrime[1] = false;
    for(int i = 2; i * i < SIZE; i++) {
        if(!isPrime[i]) continue;
        for(int j = i * i; j < SIZE; j += i)
            isPrime[j] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    sieve();
    while(1) {
        cin >> n;
        if(n == 0) break;
        int ans = 0;
        for(int i = n + 1; i <= 2 * n; i++)
            if(isPrime[i]) ans++;
        cout << ans << '\n';
    }
    
    return 0;
}
