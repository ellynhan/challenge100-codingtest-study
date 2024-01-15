//
//  MINASTIRITH.cpp
//  main
//
//  Created by wi_seong on 1/15/24.
//

/*
 [Input]
 3
 10
 7.02066050 -3.83540431 4.0
 -7.23257714 -3.41903904 2.0
 0.00000000 -8.00000000 8.0
 -8.00000000 -0.00000000 4.8
 -6.47213595 4.70228202 3.2
 -4.70228202 6.47213595 4.8
 7.60845213 -2.47213595 1.6
 -2.47213595 -7.60845213 8.8
 6.47213595 4.70228202 7.6
 -0.00000000 8.00000000 4.8
 4
 8.00000000 0.00000000 8.00
 0.00000000 -8.00000000 8.00
 -8.00000000 -0.00000000 8.00
 1.25147572 7.90150672 5.40
 1
 8 0 15.99
 [Output]
 5
 4
 IMPOSSIBLE
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000
// 난이도: 상
// Timer: 2h
// Url: https://algospot.com/judge/problem/read/MINASTIRITH

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define X first
#define Y second
#define INF 987654321
const double pi = 2.0 * acos(0);
int t, n;
double y[100], x[100], r[100];
pair<double,double> rangeArray[100];

void convertToRange() {
    for(int i = 0; i < n; i++) {
        double loc = fmod(2 * pi + atan2(y[i], x[i]), 2 * pi);
        double range = 2.0 * asin(r[i] / 2.0 / 8.0);
        rangeArray[i] = make_pair(loc - range, loc + range);
    }
}

int solveLinear(double begin, double end) {
    int used = 0, idx = 0;

    while(begin < end) {
        double maxCover = -1;
        while(idx < n && rangeArray[idx].X <= begin) {
            maxCover = max(maxCover, rangeArray[idx].Y);
            ++idx;
        }
        if(maxCover <= begin)
            return INF;
        begin = maxCover;
        ++used;
    }
    return used;
}

int solveCircular() {
    int ret = INF;
    sort(rangeArray, rangeArray+n);

    for(int i = 0; i < n; i++)
        if(rangeArray[i].X <= 0 || rangeArray[i].Y >= 2 * pi) {
            double begin = fmod(rangeArray[i].Y, 2 * pi);
            double end = fmod(rangeArray[i].X + 2 * pi, 2 * pi);
            ret = min(ret, 1 + solveLinear(begin, end));
        }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> y[i] >> x[i] >> r[i];
        }
        convertToRange();
        int ret = solveCircular();
        if(ret == INF)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << ret << endl;
    }
}

