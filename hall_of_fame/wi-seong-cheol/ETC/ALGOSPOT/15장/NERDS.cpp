//
//  NERDS.cpp
//  main
//
//  Created by wi_seong on 1/18/24.
//

/*
 [Input]
 3
 8
 1 2 3
 1 3 4
 1 4 5
 1 2 5
 0 4 1
 0 5 5
 0 3 3
 0 4 4
 6
 1 1 5
 1 5 1
 1 1 1
 0 2 2
 0 4 1
 0 1 4
 6
 1 10 10
 0 10 10
 1 5 15
 1 5 5
 0 15 15
 0 15 5
 [Output]
 THEORY HOLDS
 THEORY IS INVALID
 THEORY IS INVALID
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 25,000,000
// 난이도: 중
// Timer: 2h
// Url: https://algospot.com/judge/problem/read/NERDS

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

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
        double n = norm();
        return vector2(x / n, y / n);
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

double ccw(vector2 a, vector2 b) {
    return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b) {
    return ccw(a - p, b - p);
}

polygon giftWrap(const vector<vector2>& points) {
    int n = int(points.size());
    polygon hull;

    vector2 pivot = *min_element(points.begin(), points.end());
    hull.push_back(pivot);
    while(true) {
        vector2 ph = hull.back(), next = points[0];
        for(int i = 1; i < n; i++) {
            double cross = ccw(ph, next, points[i]);
            double dist = (next - ph).norm() - (points[i] - ph).norm();
            if(cross > 0 || (cross == 0 && dist < 0))
                next = points[i];
        }

        if(next == pivot) break;
        hull.push_back(next);
    }
    return hull;
}

bool isInside(vector2 q, const polygon& p) {
    int crosses = 0;
    for(int i = 0; i < int(p.size()); i++) {
        int j = (i + 1) % int(p.size());
        if((p[i].y > q.y) != (p[j].y > q.y)) {
            double atX = (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y) + p[i].x;
            if(q.x < atX) crosses++;
        }
    }
    return crosses % 2 > 0;
}

double disjoint(double a, double b, double c, double d) {
    if(a > b) swap(a, b);
    if(c > d) swap(c, d);
    return b < c || d < a;
}

bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
    double ab = ccw(a, b, c) * ccw(a, b, d);
    double cd = ccw(c, d, a) * ccw(c, d, b);
    if(ab == 0 && cd == 0) {
        return !disjoint(a.x, b.x, c.x, d.x) &&
            !disjoint(a.y, b.y, c.y, d.y);
    }
    return ab <= 0 && cd <= 0;
}

bool polygonIntersects(const polygon& p, const polygon& q) {
    int n = int(p.size()), m = int(q.size());
    if(isInside(p[0], q) || isInside(q[0], p)) return true;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(segmentIntersects(p[i], p[(i + 1) % n], q[j], q[(j + 1) % m]))
                return true;
    return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        polygon inputs[2];
        cin >> n;
        for(int i = 0; i < n; i++) {
            int type, x, y;
            cin >> type >> x >> y;
            inputs[type].push_back(vector2(x, y));
        }
        polygon hulls[2];
        for(int i = 0; i < 2; i++)
            hulls[i] = giftWrap(inputs[i]);
        if(polygonIntersects(hulls[0], hulls[1]))
            cout << "THEORY IS INVALID\n";
        else
            cout << "THEORY HOLDS\n";
    }

	return 0;
}
