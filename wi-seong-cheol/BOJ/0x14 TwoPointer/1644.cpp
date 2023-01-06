//
//  .cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 20
 [Output]
 0
 */
// 시간복잡도: O(n)
// 최악시간: 4,000,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1644

#include <iostream>
#include <vector>

using namespace std;
#define ll long long
int n;
vector<bool> isPrime(4000001, true);
vector<int> prime;

void sieve() {
    isPrime[1] = false;
    for(int i = 2; i*i <= n; i++) {
        if(!isPrime[i]) continue;
        for(int j = i*i; j <= n; j += i)
            isPrime[j] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    sieve();
    for(int i = 1; i <= n; i++)
        if(isPrime[i])
            prime.push_back(i);
    
    int en = 0;
    ll sum = 0;
    int ans = 0;
    for(int st = 0; st < prime.size(); st++) {
        while(en < prime.size() && sum < n) {
            sum += prime[en];
            en++;
        }
        if(sum == n) ans++;
        sum -= prime[st];
    }
    cout << ans;
    
    return 0;
}
