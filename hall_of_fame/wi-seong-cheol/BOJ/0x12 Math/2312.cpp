//
//  2312.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 2
 6
 24
 [Output]
 2 1
 3 1
 2 3
 3 1
 */
// 시간복잡도: O(nloglogn)
// 최악시간: 100,000
// 난이도: Silver 3
// Timer: 10m
// Url: https://www.acmicpc.net/problem/2312

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 100001;
int n;
vector<bool> isPrime(SIZE, true);
vector<int> prime;

void sieve() {
    isPrime[1] = false;
    for(int i = 2; i*i < SIZE; i++) {
        if(!isPrime[i]) continue;
        for(int j = i*i; j < SIZE; j += i)
            isPrime[j] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    sieve();
    for(int i = 2; i < SIZE; i++)
        prime.push_back(i);
    while(t--) {
        cin >> n;
        for(int i = 0; i < prime.size(); i++) {
            if(n % prime[i] == 0) {
                int cnt = 0;
                while(n % prime[i] == 0) {
                    n /= prime[i];
                    cnt++;
                }
                cout << prime[i] << ' ' << cnt << '\n';
            }
        }
    }
    
    return 0;
}
