//
//  ZIMBABWE.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 1/21/24.
//

/*
 [Input]
 4
 321 3
 123 3
 422 2
 12738173912 7
 [Output]
 5
 0
 2
 11033
 */
// 시간복잡도: O(n * m * 2 ^ n)
// 최악시간: 4,587,520
// 난이도: 상
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/ZIMBABWE

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int MOD = 1e9 + 7;
int t, n, m;
string e, digits;
int cache[1 << 14][20][2];

int price(int index, int taken, int mod, int less) {
    if(index == n)
        return (less && mod == 0) ? 1 : 0;
    int& ret = cache[taken][mod][less];
    if(ret != -1) return ret;

    ret = 0;
    for(int next = 0; next < n; next++) {
        if((taken & (1 << next)) == 0) {
            if(!less && e[index] < digits[next]) continue;
            if(next > 0 && digits[next - 1] == digits[next] && (taken & (1 << (next - 1))) == 0) continue;
            int nextTaken = taken | (1 << next);
            int nextMod = (mod * 10 + digits[next] - '0') % m;
            int nextLess = less || e[index] > digits[next];
            ret += price(index + 1, nextTaken, nextMod, nextLess);
            ret %= MOD;
        }
    }

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> e >> m;
        n = int(e.size());
        digits = e;
        sort(digits.begin(), digits.end());

        memset(cache, -1, sizeof(cache));
        cout << price(0, 0, 0, 0) << '\n';
    }

	return 0;
}
