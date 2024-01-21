//
//  ARTIC.cpp
//  main
//
//  Created by wi_seong on 1/16/24.
//

/*
 [Input]
 2
 5
 0 0
 1 0
 1 1
 1 2
 0 2
 6
 1.0 1.0
 30.91 8
 4.0 7.64
 21.12 6.0
 11.39 3.0
 5.31 11.0
 [Output]
 1.00
 10.18
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000
// 난이도: 하
// Timer: 40m
// Url: https://algospot.com/judge/problem/read/ARCTIC

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;
#define X first
#define Y second
int t, n;
vector<pair<double, double>> locations;
double dist[101][101];

void init() {
    locations.clear();
    memset(dist, 0, sizeof(dist));
}

void precalc() {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            dist[i][j] = dist[j][i] = hypot(locations[i].X - locations[j].X,
                                            locations[i].Y - locations[j].Y);
        }
    }
}

bool decision(double d) {
    queue<int> Q;
    vector<bool> visited(n, false);
    Q.push(0);
    visited[0] = true;

    int seen = 0;
    while(!Q.empty()) {
        int here = Q.front(); Q.pop();
        seen++;
        for(int there = 0; there < n; there++) {
            if(visited[there] || dist[here][there] > d) continue;
            visited[there] = true;
            Q.push(there);
        }
    }

    return seen == n;
}

double solve() {
    double lo = 0, hi = 1416.00;

    for(int i = 0; i < 100; i++) {
        double mid = (lo + hi) / 2.0;
        if(decision(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    return hi;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.precision(2);
    cout << fixed;

    cin >> t;
    while(t--) {
        cin >> n;
        init();
        for(int i = 0; i < n; i++) {
            double x, y; cin >> x >> y;
            locations.push_back({x, y});
        }
        precalc();
        cout << solve() << "\n";
    }

	return 0;
}
