//
//  20304.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 10
 2
 3 4
 [Output]
 2
 */
// 시간복잡도: O(n * m)
// 최악시간: 2,000,000
// 난이도: Platinum 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/20304

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n, m;
int max_bit_size = 0;
int p[100001];
int discovered[1000001];
int depth[1000001];

void make_max_bit_size() {
    int tmp = n;
    
    while(1) {
        if(tmp / 2 != 0) {
            max_bit_size++;
            tmp /= 2;
        } else {
            max_bit_size++;
            break;
        }
    }
}

int solve() {
    queue<int> Q;
    for(int i = 0; i < m; i++) {
        Q.push(p[i]);
        discovered[p[i]] = 1;
    }
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int i = 0; i < max_bit_size; i++) {
            int nxt = (cur ^ (1 << i));
            if(nxt > n || discovered[nxt] != 0) continue;
            discovered[nxt] = 1;
            depth[nxt] = depth[cur] + 1;
            Q.push(nxt);
        }
    }
    
    int ret = -1;
    for(int i = 0; i <= n; i++)
        ret = max(ret, depth[i]);
    
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> p[i];
    make_max_bit_size();
    cout << max_bit_size;
    cout << solve();
    
    return 0;
}
