//
//  17103.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 1
 1000000
 [Output]
 5402
 */
// 시간복잡도: O(nloglogn)
// 최악시간: 700,000
// 난이도: Silver 2
// Timer: 10m
// Url: https://www.acmicpc.net/problem/17103

#include <iostream>
#include <vector>

using namespace std;
#define MX 1000001
int t, n;
vector<bool> isPrime(MX, true);

void sieve() {
    isPrime[1] = false;
    for(int i = 2; i < MX; i++) {
        if(!isPrime[i]) continue;
        for(int j = i + i; j <= MX; j += i)
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
        int ans = 0;
        for(int i = 2; i <= n / 2; i++)
            if(isPrime[i] && isPrime[n - i]) ans++;
        cout << ans << '\n';
    }
    
    return 0;
}
