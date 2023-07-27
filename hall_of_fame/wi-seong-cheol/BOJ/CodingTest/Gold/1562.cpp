//
//  1562.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/18.
//

/*
 [Input]
 10
 [Output]
 1
 */
// 시간복잡도: O(n)
// 최악시간: 100
// 난이도: Gold 1
// Timer: 40m
// Url: https://www.acmicpc.net/problem/1562

#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
const int MAX = 1023;
const ll mod = 1e9;
int n;
ll ans;
ll d[101][11][(1<<10) + 1];
int dx[] = {-1, 1};

ll solve(int k, int cur, int state) {
    if(k == n - 1) {
        if(state == MAX) return 1;
        else return 0;
    }

    ll& ret = d[k][cur][state];
    if(ret != -1) return ret;
    ret = 0;

    for(int i = 0; i < 2; i++){
        int nxt = cur + dx[i];
        if(nxt == 10 || nxt == -1) continue;
        ret += solve(k + 1, nxt, state | 1 << nxt);
    }

    return ret % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    memset(d, -1, sizeof(d));
    cin >> n;
    for(int i = 1; i < 10; i++)
        ans += solve(0, i, 1 << i);
    cout << ans % mod;
    
    return 0;
}
