//
//  PACKING.cpp
//  main
//
//  Created by wi_seong on 1/12/24.
//

/*
 [Input]
 2
 6 10
 laptop 4 7
 camera 2 10
 xbox 6 6
 grinder 4 7
 dumbell 2 5
 encyclopedia 10 4
 6 17
 laptop 4 7
 camera 2 10
 xbox 6 6
 grinder 4 7
 dumbell 2 5
 encyclopedia 10 4
 [Output]
 24 3
 laptop
 camera
 grinder
 30 4
 laptop
 camera
 xbox
 grinder
 */
// 시간복잡도: O(n * w)
// 최악시간: 100,000
// 난이도: 중
// Timer: 40m
// Url: https://algospot.com/judge/problem/read/PACKING

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
#define X first
#define Y second
int t, n, w;
string name[101];
pair<int, int> item[101];
int cache[101][1001];
int choices[1001];

void init() {
    memset(cache, -1, sizeof(cache));
}

int pack(int idx, int capacity) {
    if(idx == n) return 0;
    int &ret = cache[idx][capacity];
    if(ret != -1) return ret;

    ret = pack(idx + 1, capacity);
    if(capacity >= item[idx].X)
        ret = max(ret, pack(idx + 1, capacity - item[idx].X) + item[idx].Y);

    return ret;
}

void reconstruct(int idx, int capacity, vector<string> &picked) {
    if(idx == n) return;
    if(pack(idx, capacity) == pack(idx + 1, capacity)) {
        reconstruct(idx + 1, capacity, picked);
    } else {
        picked.push_back(name[idx]);
        reconstruct(idx + 1, capacity - item[idx].X, picked);
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        init();
        cin >> n >> w;
        for(int i = 0; i < n; i++) {
            cin >> name[i] >> item[i].X >> item[i].Y;
        }
        cout << pack(0, w) << ' ';
        vector<string> picked;
        reconstruct(0, w, picked);
        cout << picked.size() << '\n';
        for(auto p: picked) cout << p << '\n';
    }

	return 0;
}
