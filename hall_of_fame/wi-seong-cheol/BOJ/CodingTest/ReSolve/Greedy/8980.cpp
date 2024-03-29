//
//  8980.cpp
//  main
//
//  Created by wi_seong on 3/19/24.
//

/*
 [Input]
 6 60
 5
 1 2 30
 2 5 70
 5 6 60
 3 4 40
 1 6 40
 [Output]
 150
 */
// 시간복잡도: O(n * m)
// 최악시간: 20,000,000
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/8980

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Box {
    int st, en, w;
};
int n, c, m;
int ans;
int truck[2001];
vector<Box> box;

bool cmp(Box a, Box b) {
    return a.en < b.en;
}

void solve() {
    for(int i = 0; i < m; i++) {
        int mini = truck[box[i].st];
        for(int j = box[i].st + 1; j < box[i].en; j++) {
            mini = min(mini, truck[j]);
        }
        int cnt = box[i].w;
        if(mini < cnt)
            cnt = mini;
        ans += cnt;
        for(int j = box[i].st; j < box[i].en; j++) {
            truck[j] -= cnt;
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> c >> m;
    fill(truck, truck + n + 1, c);
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        box.push_back({a, b, w});
    }

    sort(box.begin(), box.end(), cmp);
    solve();
    cout << ans;

	return 0;
}
