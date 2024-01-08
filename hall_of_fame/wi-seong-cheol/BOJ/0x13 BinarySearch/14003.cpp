//
//  14003.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 1/8/24.
//

/*
 [Input]
 16
 -60 -41 -100 8 -8 -52 -62 -61 -76 -52 -52 14 -11 -2 -54 46
 [Output]
 7
 -100 -62 -61 -52 -11 -2 46
 */
// 시간복잡도: O(nlogn)
// 최악시간: 6'000'000
// 난이도: Platinum 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/14003

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> arr, tmp, idx, ans;

void solve() {
    for(int i = 0; i < n; i++) {
        if(tmp.empty() || tmp.back() < arr[i]) {
            tmp.push_back(arr[i]);
            idx.push_back(int(tmp.size() - 1));
        } else {
            int pos = int(lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin());
            tmp[pos] = arr[i];
            idx.push_back(pos);
        }
    }

    for(int i = n - 1, j = int(tmp.size() - 1); i >= 0; i--) {
        if(idx[i] == j) {
            ans.push_back(arr[i]);
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    solve();

    cout << ans.size() << '\n';
    for(int x: ans)
        cout << x << ' ';

	return 0;
}
