//
//  2568.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 1/8/24.
//

/*
 [Input]
 8
 1 8
 3 9
 2 2
 4 1
 6 4
 10 10
 9 7
 7 6
 [Output]
 3
 1
 2
 3
 */
// 시간복잡도: O(nlogm)
// 최악시간: 2,500,000
// 난이도: Platinum 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2568

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n;
vector<int> ans;
vector<pair<int, int>> a;
vector<int> idx;

void solve() {
    vector<int> lis;
    for(int i = 0; i < n; i++) {
        if(lis.empty() || lis.back() < a[i].Y) {
            lis.push_back(a[i].Y);
            idx.push_back(int(lis.size()) - 1);
        } else {
            int pos = int(lower_bound(lis.begin(), lis.end(), a[i].Y) - lis.begin());
            lis[pos] = a[i].Y;
            idx.push_back(pos);
        }
    }

    for(int i = n - 1, j = int(lis.size() - 1); i >= 0; i--) {
        if(idx[i] == j) {
            j--;
        } else {
            ans.push_back(a[i].X);
        }
    }
    reverse(ans.begin(), ans.end());
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());

    solve();

    cout << ans.size() << '\n';
    for(int x: ans)
        cout << x << '\n';

	return 0;
}
