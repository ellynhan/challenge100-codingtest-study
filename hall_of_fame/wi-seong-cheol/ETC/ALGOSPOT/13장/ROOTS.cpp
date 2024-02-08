//
//  ROOTS.cpp
//  main
//
//  Created by wi_seong on 1/17/24.
//

/*
 [Input]
 2
 3
 1.00 -6.00 11.00 -6.00
 2
 1.00 -12.50 31.50
 [Output]
 1.0000000000 2.0000000000 3.0000000000
 3.5000000000 9.0000000000
 */
// 시간복잡도: O((n ^ 3)logn)
// 최악시간: 15,625
// 난이도: 중
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/ROOTS

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
const double L = 25;
int t, n;
vector<double> poly;

vector<double> differentiate(const vector<double>& poly) {
    int n = int(poly.size() - 1);
    vector<double> ret(n);
    for(int i = 1; i <= n; i++)
        ret[i - 1] = i * poly[i];
    return ret;
}

vector<double> solveNaive(const vector<double>& poly) {
    int n = int(poly.size() - 1);
    if(n == 1) {
        double a = poly[1], b = poly[0];
        if(fabs(a) < 1e-8) return vector<double>();
        return vector<double>(1, -b / a);
    }
    double a = poly[2], b = poly[1], c = poly[0];
    double d = b * b - 4 * a * c;
    if(d < 0) return vector<double>();
    if(d == 0) return vector<double>(1, -b / (2 * a));
    vector<double> ret;
    ret.push_back((-b - sqrt(d)) / (2 * a));
    ret.push_back((-b + sqrt(d)) / (2 * a));
    sort(ret.begin(), ret.end());
    return ret;
}

double evaluate(const vector<double>& poly, double x) {
    int n = int(poly.size() - 1);
    double ret = 0;
    for(int i = 0; i <= n; i++)
        ret += pow(x, i) * poly[i];
    return ret;
}

vector<double> solve(const vector<double>& poly) {
    int n = int(poly.size() - 1);
    if(n <= 2) return solveNaive(poly);

    vector<double> derivative = differentiate(poly);
    vector<double> sols = solve(derivative);

    sols.insert(sols.begin(), -L-1);
    sols.insert(sols.end(), L+1);
    vector<double> ret;

    for(int i = 0; i + 1 < sols.size(); i++) {
        double x1 = sols[i], x2 = sols[i + 1];
        double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);
        if(y1 * y2 > 0) continue;
        if(y1 > y2) { swap(y1, y2); swap(x1, x2); }
        for(int iter = 0; iter < 100; iter++) {
            double mx = (x1 + x2) / 2;
            double my = evaluate(poly, mx);
            if(y1 * my > 0) {
                y1 = my;
                x1 = mx;
            } else {
                y2 = my;
                x2 = mx;
            }
        }
        ret.push_back((x1 + x2) / 2);
    }
    sort(ret.begin(), ret.end());

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.precision(10);
    cout << fixed;

    cin >> t;
    while(t--) {
        cin >> n;
        poly.resize(n + 1);
        for(int i = 0; i <= n; i++)
            cin >> poly[n - i];
        vector<double> ans = solve(poly);
        for(double x: ans)
            cout << x << ' ';
        cout << '\n';
    }

	return 0;
}
