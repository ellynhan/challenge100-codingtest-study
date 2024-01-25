//
//  DRANGON.cpp
//  main
//
//  Created by wi_seong on 1/15/24.
//

/*
 [Input]
 4
 0 1 2
 1 1 5
 2 6 5
 42 764853475 30
 [Output]
 FX
 FX+YF
 +FX-Y
 FX-YF-FX+YF+FX-YF-FX+YF-FX-YF-
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 2,500
// 난이도: 중
// Timer: 1시간
// Url: https://algospot.com/judge/problem/read/DRAGON

#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1000000000 + 1;
const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";
int t, n, p, l;
int length[51];

void precalc() {
    length[0] = 1;
    for(int i = 1; i <= 50; i++) {
        length[i] = min(MAX, length[i - 1] * 2 + 2);
    }
}

char expand(const string& dragonCurve, int generations, int skip) {
    if(generations == 0) {
        return dragonCurve[skip];
    }
    for(int i = 0; i < dragonCurve.size(); i++) {
        if(dragonCurve[i] == 'X' || dragonCurve[i] == 'Y') {
            if(skip >= length[generations]) {
                skip -= length[generations];
            } else if(dragonCurve[i] == 'X') {
                return expand(EXPAND_X, generations - 1, skip);
            } else {
                return expand(EXPAND_Y, generations - 1, skip);
            }
        } else if(skip > 0) {
            --skip;
        } else {
            return dragonCurve[i];
        }
    }
    return '#';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    precalc();
    cin >> t;
    while(t--) {
        cin >> n >> p >> l;
        for (int i = 0; i < l; ++i)
            cout << expand("FX", n, p + i - 1);
        cout << '\n';
    }

	return 0;
}
