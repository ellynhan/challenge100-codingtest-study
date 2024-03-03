//
//  CHRISTMAS.cpp
//  main
//
//  Created by wi_seong on 1/19/24.
//

/*
 [Input]
 1
 6 4
 1 2 3 4 5 6
 [Output]
 3 1
 */
// 시간복잡도: O(n + k)
// 최악시간: 200,000
// 난이도: 중
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/CHRISTMAS

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int mod = 20091101;
int t, n, k;
int psum[100001];

void init() {
    memset(psum, 0, sizeof(psum));
}

int waysToBuy() {
    int ret = 0;
    vector<long long> count(k, 0);
    for(int i = 0; i <= n; i++) {
        count[psum[i]]++;
    }
    for(int i = 0; i < k; i++) {
        if(count[i] >= 2) {
            ret = (ret + ((count[i] * (count[i] - 1)) / 2)) % mod;
        }
    }
    return ret;
}

int maxBuys() {
    vector<int> ret(n + 1, 0);
    vector<int> prev(k, -1);
    for(int i = 0; i <= n; i++) {
        if(i > 0) ret[i] = ret[i - 1];
        else ret[i] = 0;
        int loc = prev[psum[i]];
        if(loc != -1) ret[i] = max(ret[i], ret[loc] + 1);
        prev[psum[i]] = i;
    }

    return ret.back();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            int num; cin >> num;
            psum[i] = (psum[i - 1] + num) % k;
        }
        cout << waysToBuy() << " " << maxBuys() << "\n";
    }

	return 0;
}
