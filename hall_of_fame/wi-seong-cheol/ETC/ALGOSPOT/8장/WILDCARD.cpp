//
//  Wildcard.cpp
//  main
//
//  Created by wi_seong on 1/10/24.
//

/*
 [Input]
 2
 he?p
 3
 help
 heap
 helpp
 *p*
 3
 help
 papa
 hello
 [Output]
 heap
 help
 help
 papa
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000
// 난이도: 중
// Timer: 40m
// Url: https://algospot.com/judge/problem/read/WILDCARD

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int t, n;
string wildcard, filename;
int cache[101][101];

bool match(int w, int f) {
    int& ret = cache[w][f];
    if(ret != -1) return ret;

    if(w < wildcard.size() && f < filename.size()
       && (wildcard[w] == '?' || wildcard[w] == filename[f]))
        return ret = match(w + 1, f + 1);

    if(w == wildcard.size() && f == filename.size())
        return ret = 1;

    if(wildcard[w] == '*') {
        if(match(w + 1, f) || (f < filename.size() && match(w, f + 1)))
            return ret = 1;
    }

    return ret = 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    cin >> t;
    while(t--) {
        vector<string> ans;
        cin >> wildcard;
        cin >> n;

        while(n--) {
            cin >> filename;
            memset(cache, -1, sizeof(cache));
            if(match(0, 0) == 1)
                ans.push_back(filename);
        }

        sort(ans.begin(), ans.end());
        for(string s: ans)
            cout << s << '\n';
    }

	return 0;
}
