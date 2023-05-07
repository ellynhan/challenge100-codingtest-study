//
//  12851.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/13.
//

/*
 [Input]
 5 17
 [Output]
 4
 2
 */
// 시간복잡도: O(n)
// 최악시간: 200,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/12851

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define ll long long
const int MX = 200000;
int n, m;
ll cnt[MX + 1];
ll dist[MX + 1];

bool OOB(int x) { return x < 0 || x >= MX; }

void bfs() {
    queue<int> Q;
    Q.push(n);
    dist[n] = 0;
    cnt[n] = 1;

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if(cur == m) return;
        for(int nxt: {cur - 1, cur * 2, cur + 1}) {
            if(OOB(nxt)) continue;
            if(dist[nxt] == dist[cur] + 1) {
                cnt[nxt] += cnt[cur];
            }
            else if(dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                cnt[nxt] += cnt[cur];
                Q.push(nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(dist, dist + MX, -1);
    cin >> n >> m;
    bfs();
    cout << dist[m] << '\n' << cnt[m];

    return 0;
}
