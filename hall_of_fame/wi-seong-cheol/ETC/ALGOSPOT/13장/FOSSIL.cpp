//
//  FOSSIL.cpp
//  main
//
//  Created by wi_seong on 1/17/24.
//

/*
 [Input]
 2
 5 5
 35.74 35.85 69.64 50.00 73.52 82.55 43.50 92.22 17.67 76.18
 16.47 8.02 60.98 14.62 66.80 37.74 45.89 67.22 13.04 55.19
 4 3
 73.84 11.41 71.61 32.72 39.87 38.84 22.41 17.87
 75.13 51.64 47.72 87.34 15.97 64.56
 [Output]
 27.6529680365
 0.000000
 */
// 시간복잡도: O(n + m)
// 최악시간: 200
// 난이도: 상
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/FOSSIL

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define X first
#define Y second
int t, n, m;
vector<pair<double, double>> hull1, hull2;
vector<pair<pair<double, double>, pair<double, double>>> upper, lower;

void init() {
    hull1.resize(n);
    hull2.resize(m);
    upper.clear();
    lower.clear();
}

void decompose(const vector<pair<double, double>>& hull) {
    int n = int(hull.size());
    for(int i = 0; i < n; i++) {
        if(hull[i].Y < hull[(i + 1) % n].Y)
            lower.push_back({hull[i], hull[(i + 1) % n]});
        else if(hull[i].Y > hull[(i + 1) % n].Y)
            upper.push_back({hull[i], hull[(i + 1) % n]});
    }
}

double minX(vector<pair<double, double>>& hull) {
    double ret = 1e20;
    for(auto& p : hull)
        ret = min(ret, p.Y);
    return ret;
}

double maxX(vector<pair<double, double>>& hull) {
    double ret = -1e20;
    for(auto& p : hull)
        ret = max(ret, p.Y);
    return ret;
}

bool between(double x, const pair<double, double>& a, const pair<double, double>& b) {
    return (a.Y <= x && x <= b.Y) || (b.Y <= x && x <= a.Y);
}

double at(double x, const pair<double, double>& a, const pair<double, double>& b) {
    double dx = b.X - a.X, dy = b.Y - a.Y;
    if(fabs(dy) < 1e-9) return a.X;
    return a.X + dx * (x - a.Y) / dy;
}

double vertical(double x) {
    double minUp = 1e20, maxDown = -1e20;
    for(auto& p: upper)
        if(between(x, p.X, p.Y))
            minUp = min(minUp, at(x, p.X, p.Y));
    for(auto& p: lower)
        if(between(x, p.X, p.Y))
            maxDown = max(maxDown, at(x, p.X, p.Y));
    return minUp - maxDown;
}

double solve() {
    double lo = max(minX(hull1), minX(hull2));
    double hi = min(maxX(hull1), maxX(hull2));

    if(hi < lo) return 0;

    for(int i = 0; i < 100; i++) {
        double aab = (lo * 2 + hi) / 3.0;
        double abb = (lo + hi * 2) / 3.0;
        if(vertical(aab) < vertical(abb))
            lo = aab;
        else
            hi = abb;
    }

    return max(0.0, vertical(hi));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.precision(10);
    cout << fixed;

    cin >> t;
    while(t--) {
        cin >> n >> m;
        init();
        for(int i = 0; i < n; i++)
            cin >> hull1[i].Y >> hull1[i].X;
        for(int i = 0; i < m; i++)
            cin >> hull2[i].Y >> hull2[i].X;
        decompose(hull1);
        decompose(hull2);
        printf("%.10lf\n", max(0.0, solve()));
    }

	return 0;
}
