//
//  NUMB3RS.cpp
//  main
//
//  Created by wi_seong on 1/11/24.
//

/*
 [Input]
 2
 5 2 0
 0 1 1 1 0
 1 0 0 0 1
 1 0 0 0 0
 1 0 0 0 0
 0 1 0 0 0
 3
 0 2 4
 8 2 3
 0 1 1 1 0 0 0 0
 1 0 0 1 0 0 0 0
 1 0 0 1 0 0 0 0
 1 1 1 0 1 1 0 0
 0 0 0 1 0 0 1 1
 0 0 0 1 0 0 0 1
 0 0 0 0 1 0 0 0
 0 0 0 0 1 1 0 0
 4
 3 1 2 6
 [Output]
 0.83333333 0.00000000 0.16666667
 0.43333333 0.06666667 0.06666667 0.06666667
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 250,000
// 난이도: 중
// Timer: 40m
// Url: https://algospot.com/judge/problem/read/NUMB3RS

#include <iostream>

using namespace std;
int c, n, d, p, t, x;
int board[51][51];
int cntDegree[51];
double cache[101][51];

void init() {
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 51; j++) {
            cache[i][j] = -1;
        }
    }
}

void precalc() {
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 1)
                cnt++;
        }
        cntDegree[i] = cnt;
    }
}

double solve(int days, int here) {
    if(days == 0) return (here == p ? 1.0 : 0.0);
    double &ret = cache[days][here];
    if(ret > -0.5) return ret;

    ret = 0;
    for(int there = 0; there < n; there++) {
        if(board[here][there] == 1)
            ret += solve(days - 1, there) / cntDegree[there];
    }

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.precision(8);

    cin >> c;
    while(c--) {
        cin >> n >> d >> p;
        init();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cin >> board[i][j];
        }
        precalc();

        cin >> t;
        while(t--) {
            cin >> x;
            cout << solve(d, x) << ' ';
        }
        cout << '\n';
    }

	return 0;
}
