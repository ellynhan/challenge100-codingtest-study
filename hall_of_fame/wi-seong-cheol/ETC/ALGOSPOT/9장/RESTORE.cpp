//
//  RESTORE.cpp
//  main
//
//  Created by wi_seong on 1/21/24.
//

/*
 [Input]
 3
 3
 geo
 oji
 jing
 2
 world
 hello
 3
 abrac
 cadabra
 dabr
 [Output]
 geojing
 helloworld
 cadabrac
 */
// 시간복잡도: O(k ^ 2)
// 최악시간: 225
// 난이도: 중
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/RESTORE

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int MXN = 15;
int t, k;
string words[MXN];
int overlap[MXN][MXN];
int cache[MXN][1 << MXN];

int getOverlap(string& a, string& b) {
    int ret = 0;
    for(int i = 1; i <= min(a.size(), b.size()); i++) {
        if(a.substr(a.size() - i) == b.substr(0, i))
            ret = i;
    }
    return ret;
}

void precalc() {
    for(int i = 0; i <= k; i++) {
        for(int j = 0; j <= k; j++) {
            if(i == j) continue;
            overlap[i][j] = getOverlap(words[i], words[j]);
        }
    }
}

int restore(int last, int used) {
    if(used == (1 << k) - 1) return 0;
    int& ret = cache[last][used];
    if(ret != -1) return ret;
    ret = 0;
    
    for(int next = 0; next < k; next++) {
        if(used & (1 << next)) continue;
        int cand = overlap[last][next] + restore(next, used + (1 << next));
        ret = max(ret, cand);
    }

    return ret;
}

string reconstruct(int last, int used) {
    if(used == (1 << k) - 1) return "";
    for(int next = 0; next < k; next++) {
        if(used & (1 << next)) continue;
        int ifUsed = restore(next, used + (1 << next)) + overlap[last][next];
        if(restore(last, used) == ifUsed)
            return words[next].substr(overlap[last][next]) + reconstruct(next, used + (1 << next));
    }
    return "****oops****";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> k;
        for(int i = 0; i < k; i++) {
            cin >> words[i];
        }
        while(true) {
            bool removed = false;
            for(int i = 0; i < k && !removed; i++)
                for(int j = 0; j < k; j++)
                    if(i != j && words[i].find(words[j]) != -1) {
                        words[j] = words[k-1];
                        --k;
                        removed = true;
                    }

            if(!removed) break;
        }
        words[k] = "";
        sort(words, words + k);
        precalc();
        memset(cache, -1, sizeof(cache));
        restore(k, 0);
        cout << reconstruct(k, 0) << "\n";
    }

	return 0;
}
