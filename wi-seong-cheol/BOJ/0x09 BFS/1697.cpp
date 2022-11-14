//
//  1697.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 5 17
 [Output]
 4
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 1
// Timer: 17m
// Url: https://www.acmicpc.net/problem/

#include <iostream>
#include <queue>

using namespace std;
int n, m;
int t[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    fill(t, t + 100001, -1);
    t[n] = 0;
    queue<int> Q;
    Q.push(n);
    while(t[m] == -1) {
        int cur = Q.front(); Q.pop();
        for(int nx: {cur-1, cur+1, 2*cur}){
            if(nx < 0 || nx > 100000 || t[nx] != -1) continue;
            Q.push(nx);
            t[nx] = t[cur] + 1;
        }
    }
    cout << t[m];
    
    return 0;
}
