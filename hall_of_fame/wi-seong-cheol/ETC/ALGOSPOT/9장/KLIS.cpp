//
//  KLIS.cpp
//  main
//
//  Created by wi_seong on 1/15/24.
//

/*
 [Input]
 3
 9 2
 1 9 7 4 2 6 3 11 10
 8 4
 2 1 4 3 6 5 8 7
 8 2
 5 6 7 8 1 2 3 4
 [Output]
 4
 1 2 3 11
 4
 1 3 6 8
 4
 5 6 7 8
 */
// 시간복잡도: O(n ^ 2 * log n)
// 최악시간: 500,000
// 난이도: 중
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/KLIS

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
#define ll long long
const int MAX = 2000000000 + 1;
int t, n, k;
int cacheLen[501], cacheCnt[501], S[501];

void init() {
    memset(cacheLen, -1, sizeof(cacheLen));
    memset(cacheCnt, -1, sizeof(cacheCnt));
}

int lis3(int st) {
    int& ret = cacheLen[st + 1];
    if(ret != -1) return ret;
    
    ret = 1;
    for(int i = st + 1; i < n; i++) {
        if(st == -1 || S[st] < S[i]) {
            ret = max(ret, lis3(i) + 1);
        }
    }
    return ret;
}

int count(int st) {
    if(lis3(st) == 1) return 1;
    int &ret = cacheCnt[st + 1];
    if(ret != -1) return ret;

    ret = 0;
    for(int next = st + 1; next < n; next++) {
        if((st == -1 || S[st] < S[next]) && lis3(st) == lis3(next) + 1) {
            ret = int(min<ll>(MAX, (ll)ret + count(next)));
        }
    }
    return ret;
}

void reconstruct(int st, int skip, vector<int>& lis) {
    if(st != -1) lis.push_back(S[st]);
    vector<pair<int, int>> followers;
    for(int next = st + 1; next < n; next++) {
        if((st == -1 || S[st] < S[next]) && lis3(st) == lis3(next) + 1) {
            followers.push_back(make_pair(S[next], next));
        }
    }
    sort(followers.begin(), followers.end());
    for(int i = 0; i < followers.size(); i++) {
        int idx = followers[i].second;
        int cnt = count(idx);
        if(cnt <= skip) skip -= cnt;
        else {
            reconstruct(idx, skip, lis);
            break;
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            cin >> S[i];
        }
        init();
        cout << lis3(-1) - 1 << endl;
        vector<int> lis;
        reconstruct(-1, k - 1, lis);
        for(int val: lis) {
            cout << val << " ";
        }
        cout << '\n';
    }

	return 0;
}
