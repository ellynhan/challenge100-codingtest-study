//
//  1456.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 1 10
 [Output]
 3
 */
// 시간복잡도: O(nloglogn)
// 최악시간: 8,500,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1456

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MX 10000001
#define ll long long
ll n, m, ans;
bool vis[MX];
vector<int> prime;

void sieve() {
    for(int i = 2; i < MX; ++i) {
        if(vis[i]) continue;
        prime.push_back(i);
        for(int j = i + i; j < MX; j += i)
            vis[j] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    sieve();
    
    cin >> n >> m;
    
    for(int x: prime) {
        ll cur = 1LL * x;
        ll tmp = cur;
        while(tmp <= m / cur) {
            tmp *= cur;
            if (tmp >= n) ans++;
        }
    }
    cout << ans;
    
    return 0;
}
