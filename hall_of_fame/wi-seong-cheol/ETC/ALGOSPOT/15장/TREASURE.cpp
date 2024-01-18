//
//  TREASURE.cpp
//  main
//
//  Created by wi_seong on 1/18/24.
//

/*
 [Input]
 2
 26 34 76 72 15
 41 52
 50 71
 42 87
 26 84
 16 58
 33 33
 51 23
 64 32
 73 17
 86 14
 91 38
 92 68
 82 79
 68 45
 61 58
 50 20 70 80 4
 86 50
 30 10
 90 50
 30 90
 [Output]
 1343.0948739496
 57.1428571429
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: 상
// Timer: 2h
// Url: https://algospot.com/judge/problem/read/TREASURE

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>

using namespace std;
struct vector2 {
    double x, y;
    explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
    
    bool operator == (const vector2& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    
    bool operator < (const vector2& rhs) const {
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }
    
    vector2 operator + (const vector2& rhs) const {
        return vector2(x + rhs.x, y + rhs.y);
    }
    
    vector2 operator - (const vector2& rhs) const {
        return vector2(x - rhs.x, y - rhs.y);
    }

    vector2 operator - () const {
        return vector2(-x, -y);
    }

    vector2 operator * (double rhs) const {
        return vector2(x * rhs, y * rhs);
    }

    double norm() const {
        return hypot(x, y);
    }

    vector2 normalize() const {
        return vector2(x / norm(), y / norm());
    }

    double polar() const {
        return fmod(atan2(y, x) + 2 * M_PI, 2 * M_PI);
    }

    double dot(const vector2& rhs) const {
        return x * rhs.x + y * rhs.y;
    }

    double cross(const vector2& rhs) const {
        return x * rhs.y - rhs.x * y;
    }

    vector2 project(const vector2& rhs) const {
        vector2 r = rhs.normalize();
        return r * r.dot(*this);
    }
};
typedef vector<vector2> polygon;
int t, n;

bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
    double det = (b - a).cross(d - c);
    if(det == 0) return false;
    p = a + (b - a) * ((c - a).cross(d - c) / det);
    return true;
}

double ccw(vector2 a, vector2 b) {
    return a.cross(b);
}

double ccw(vector2 a, vector2 b, vector2 c) {
    return ccw(b - a, c - a);
}

polygon cutPoly(const polygon& p, const vector2& a, const vector2& b) {
    int n = int(p.size());
    vector<bool> inside(n);
    for(int i = 0; i < n; i++)
        inside[i] = ccw(a, b, p[i]) >= 0;
    polygon ret;
    for(int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if(inside[i]) ret.push_back(p[i]);
        if(inside[i] != inside[j]) {
            vector2 cross;
            assert(lineIntersection(p[i], p[j], a, b, cross));
            ret.push_back(cross);
        }
    }
    return ret;
}

polygon intersection(const polygon& p, double x1, double y1, double x2, double y2) {
    vector2 a(x1, y1), b(x2, y1), c(x2, y2), d(x1, y2);
    polygon ret = cutPoly(p, a, b);
    ret = cutPoly(ret, b, c);
    ret = cutPoly(ret, c, d);
    ret = cutPoly(ret, d, a);
    return ret;
}

double area(const polygon& p) {
    double ret = 0;
    for(int i = 0; i < p.size(); i++) {
        int j = (i + 1) % p.size();
        ret += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return fabs(ret) / 2.0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.precision(10);
    cout << fixed;

    cin >> t;
    while(t--) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2 >> n;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);

        polygon p(n);
        for(int i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y;
        p = intersection(p, x1, y1, x2, y2);
        cout << area(p) << '\n';
    }

	return 0;
}
