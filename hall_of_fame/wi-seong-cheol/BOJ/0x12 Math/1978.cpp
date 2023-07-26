//
//  1978.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 4
 1 3 5 7
 [Output]
 3
 */
// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: Silver 5
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1978

#include <iostream>
#include <vector>

using namespace std;
int n, x, cnt;
vector<bool> prime(1001, true);

void sieve() {
    prime[1] = false;
    for(int i = 2; i * i <= 1000; i++) {
        if(!prime[i]) continue;
        for(int j = i*i; j <= 1000; j += i)
            prime[j] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    sieve();
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(prime[x]) cnt++;
    }
    cout << cnt;
    
    return 0;
}
