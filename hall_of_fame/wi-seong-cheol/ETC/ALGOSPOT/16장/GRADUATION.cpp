//
//  GRADUATION.cpp
//  main
//
//  Created by wi_seong on 1/19/24.
//

/*
 [Input]
 2
 4 4 4 4
 0
 1 0
 3 0 1 3
 0
 4 0 1 2 3
 4 0 1 2 3
 3 0 1 3
 4 0 1 2 3
 4 2 2 4
 1 1
 0
 1 3
 1 2
 3 0 2 3
 3 1 2 3
 [Output]
 3
 IMPOSSIBLE
 */
// 시간복잡도: O(m * 2 ^ (n + c)
// 최악시간: 41,943,040
// 난이도: 중
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/GRADUATION

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int INF = 987654321;
int t, n, k, m, l;
int pre[20], classes[10], cache[10][1 << 20];

void init() {
    memset(pre, 0, sizeof(pre));
    memset(classes, 0, sizeof(classes));
    memset(cache, -1, sizeof(cache));
}

int bitCount(int n) {
    return __builtin_popcount(n);
}

int graduate(int semester, int taken) {
    if(bitCount(taken) >= k) return 0;
    if(semester == m) return INF;

    int& ret = cache[semester][taken];
    if(ret != -1) return ret;
    ret = INF;

    int canTake = (classes[semester] & ~taken);

    for(int i = 0; i < n; i++) {
        if((canTake & (1 << i)) && (taken & pre[i]) != pre[i]) {
            canTake &= ~(1 << i);
        }
    }

    for(int take = canTake; take > 0; take = ((take - 1) & canTake)) {
        if(bitCount(take) > l) continue;
        ret = min(ret, graduate(semester + 1, taken | take) + 1);
    }

    ret = min(ret, graduate(semester + 1, taken));
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k >> m >> l;
        init();
        for(int i = 0; i < n; i++) {
            int r; cin >> r;
            for(int j = 0; j < r; j++) {
                int c; cin >> c;
                pre[i] |= (1 << c);
            }
        }
        for(int i = 0; i < m; i++) {
            int r; cin >> r;
            for(int j = 0; j < r; j++) {
                int c; cin >> c;
                classes[i] |= (1 << c);
            }
        }
        int ans = graduate(0, 0);

        if(ans >= INF) cout << "IMPOSSIBLE" << '\n';
        else cout << ans << '\n';
    }
}
