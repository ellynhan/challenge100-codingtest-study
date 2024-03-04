//
//  3392.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2/21/24.
//

/*
 [Input]
 2
 10 10 20 20
 15 15 25 30
 [Output]
 225
 */
// 시간복잡도: O(n)
// 최악시간: 120,000
// 난이도: Platinum 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/3392

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int, int> tp;
const int MAXN = 30002;
int n, ans;
int cnt[MAXN << 2], tree[MAXN << 2];
vector<tp> edge;

void update(int node, int nl, int nr, int ql, int qr, int val) {
    if(qr < nl || nr < ql) return;
    if(ql <= nl && nr <= qr) tree[node] += val;
    else {
        int mid = (nl + nr) / 2;
        update(node * 2, nl, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, nr, ql, qr, val);
    }
    cnt[node] = tree[node] ? nr - nl + 1 : nl ^ nr ? cnt[node * 2] + cnt[node * 2 + 1] : 0;
}

void update(int ql, int qr, int val) {
    update(1, 0, MAXN, ql, qr - 1, val);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        edge.emplace_back(a, b, d, 1);
        edge.emplace_back(c, b, d, -1);
    }
    sort(edge.begin(), edge.end());

    int prv = 0;
    for(int i = 0; i < n * 2; i++) {
        auto [x, y1, y2, val] = edge[i];
        if(i) ans += (x - prv) * cnt[1];
        prv = x;
        update(y1, y2, val);
    }
    cout << ans;

    return 0;
}
