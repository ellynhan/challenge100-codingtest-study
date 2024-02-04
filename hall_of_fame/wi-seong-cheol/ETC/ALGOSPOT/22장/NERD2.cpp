//
//  NERD2.cpp
//  main
//
//  Created by wi_seong on 1/22/24.
//

/*
 [Input]
 2
 4
 72 50
 57 67
 74 55
 64 60
 5
 1 5
 2 4
 3 3
 4 2
 5 1
 [Output]
 8
 15
 */
// 시간복잡도: O(nlogn)
// 최악시간: 200,000
// 난이도: 중
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/NERD2

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
int t, n;
map<int, int> coords;

bool isDominated(int x, int y) {
    map<int, int>::iterator it = coords.lower_bound(x);
    if(it == coords.end()) return false;
    return y < it->second;
}

void removeDominated(int x, int y) {
    map<int, int>::iterator it = coords.lower_bound(x);
    if(it == coords.begin()) return;
    --it;
    while(true) {
        if(it->second > y) break;
        if(it == coords.begin()) {
            coords.erase(it);
            break;
        } else {
            map<int, int>::iterator jt = it;
            --jt;
            coords.erase(it);
            it = jt;
        }
    }
}

int registered(int x, int y) {
    if(isDominated(x, y)) return int(coords.size());
    removeDominated(x, y);
    coords[x] = y;
    return int(coords.size());
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        coords.clear();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            ans += registered(x, y);
        }
        cout << ans << '\n';
    }

	return 0;
}
