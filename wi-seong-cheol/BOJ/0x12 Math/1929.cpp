//
//  1929.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 3 16
 [Output]
 3
 5
 7
 11
 13
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Silver 3
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1929

#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<bool> prime(1000001, true);

void sieve() {
    prime[1] = false;
    for(int i = 2; i*i <= m; i++) {
        if(!prime[i]) continue;
        for(int j = i*i; j <= m; j += i)
            prime[j] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    sieve();
    for(int i = n ; i <= m; i++)
        if(prime[i])
            cout << i << '\n';
    
    return 0;
}
