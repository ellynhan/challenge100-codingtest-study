//
//  OCR.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 1/13/24.
//

/*
 [Input]
 5 3
 I am a boy buy
 1.0 0.0 0.0 0.0 0.0
 0.1 0.6 0.1 0.1 0.1
 0.1 0.1 0.6 0.1 0.1
 0.1 0.1 0.1 0.6 0.1
 0.2 0.2 0.2 0.2 0.2
 0.2 0.2 0.2 0.2 0.2
 0.8 0.1 0.0 0.1 0.0
 0.1 0.7 0.0 0.2 0.0
 0.0 0.1 0.8 0.0 0.1
 0.0 0.0 0.0 0.5 0.5
 0.0 0.0 0.0 0.5 0.5
 4 I am a buy
 4 I I a boy
 4 I am am boy
 [Output]
 I am a boy
 I am a boy
 I am a boy
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 250,000
// 난이도: 상
// Timer: 2h
// Url: https://algospot.com/judge/problem/read/OCR

#include <iostream>
#include <cmath>

using namespace std;
int n, m, q;
int R[501];
double B[501];
double T[501][501];
double M[501][501];
double cache[501][501];
int choices[501][501];
string corpus[501];

void initCache() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= m; j++) {
            cache[i][j] = 1.0;
        }
    }
}

double recognize(int segment, int previousMatch) {
    if(segment == n) return 0;
    double &ret = cache[segment][previousMatch];
    if(ret != 1.0) return ret;
    int &choose = choices[segment][previousMatch];
    ret = -1e200;

    for(int thisMatch = 1; thisMatch <= m; thisMatch++) {
        double cand = T[previousMatch][thisMatch] + M[thisMatch][R[segment]] + recognize(segment + 1, thisMatch);
        if(ret < cand) {
            ret = cand;
            choose = thisMatch;
        }
    }
    return ret;
}

string reconstruct(int segment, int previousMatch) {
    int choose = choices[segment][previousMatch];
    string ret = corpus[choose];
    if(segment < n - 1) ret = ret + " " + reconstruct(segment + 1, choose);
    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
    cin >> m >> q;
    for(int i = 1; i <= m; i++) {
        cin >> corpus[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> B[i];
        B[i] = log(B[i]);
    }
    for(int i = 0; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            if(i == 0) T[i][j] = B[j];
            else {
                cin >> T[i][j];
                T[i][j] = log(T[i][j]);
            }
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> M[i][j];
            M[i][j] = log(M[i][j]);
        }
    }

    while(q--) {
        cin >> n;
        initCache();
        for(int i = 0; i < n; i++) {
            string s; cin >> s;
            for(int j = 0; j <= m; j++) {
                if(s == corpus[j]) {
                    R[i] = j;
                    break;
                }
            }
        }
        recognize(0, 0);
        cout << reconstruct(0, 0) << '\n';
    }

	return 0;
}
