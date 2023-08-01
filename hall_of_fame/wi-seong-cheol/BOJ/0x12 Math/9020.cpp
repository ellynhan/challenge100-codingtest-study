//
//  9020.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 3
 8
 10
 16
 [Output]
 3 5
 5 5
 5 11
 */
// 시간복잡도: O(nloglogn)
// 최악시간: 600
// 난이도: Silver 2
// Timer: 10m
// Url: https://www.acmicpc.net/problem/9020

#include <iostream>
#include <vector>

using namespace std;
#define MX 10001
int t, n;
vector<bool> isPrime(MX, true);

void sieve() {
    for(int i = 2; i < MX; i++) {
        if(!isPrime[i]) continue;
        for(int j = i * i; j < MX; j += i)
            isPrime[j] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    sieve();
    cin >> t;
    while(t--) {
        cin >> n;
        for(int a = n / 2; a >= 2; a--) {
            int b = n - a;
            if(isPrime[a] && isPrime[b]) {
                cout << a << ' ' << b << '\n';
                break;
            }
        }
    }
    
    return 0;
}
