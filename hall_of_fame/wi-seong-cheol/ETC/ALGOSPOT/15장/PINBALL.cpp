//
//  PINBALL.cpp
//  main
//
//  Created by wi_seong on 1/18/24.
//

/*
 [Input]
 1
 5 5 1 1 5
 22 40 12
 61 26 20
 19 78 21
 51 86 7
 84 57 15
 [Output]
 0 1 2 1 2 0 3 4
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000
// 난이도: 상
// Timer: 2h
// Url: https://algospot.com/judge/problem/read/PINBALL

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
const double EPSILON = 1e-9;
const double INFTY = 1e200;

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

int t, n;
vector2 center[50];
int radius[50];

vector<double> solve2(double a, double b, double c) {
    double d = b * b - 4 * a * c;
    if(d < -EPSILON)
        return vector<double>();
    if(d < EPSILON)
        return vector<double>(1, -b / (2 * a));
    vector<double> ret;
    ret.push_back((-b - sqrt(d)) / (2 * a));
    ret.push_back((-b + sqrt(d)) / (2 * a));
    return ret;
}

double hitCircle(vector2 here, vector2 dir, vector2 center, int radius) {
    double a = dir.dot(dir);
    double b = 2 * dir.dot(here - center);
    double c = center.dot(center) + here.dot(here) - 2 * here.dot(center) - radius * radius;
    vector<double> sols = solve2(a, b, c);
    if(sols.empty() || sols[0] < EPSILON) return INFTY;
    return sols[0];
}

vector2 reflect(vector2 dir, vector2 center, vector2 contact) {
    return (dir - dir.project(contact - center) * 2).normalize();
}

void simulate(vector2 here, vector2 dir) {
    dir = dir.normalize();
    int hitCount = 0;
    while(hitCount < 100) {
        int circle = -1;
        double time = INFTY * 0.5;
        for(int i = 0; i < n; i++) {
            double cand = hitCircle(here, dir, center[i], radius[i] + 1);
            if(cand < time) {
                time = cand;
                circle = i;
            }
        }
        if(circle == -1) break;
        if(hitCount++) cout << " ";
        cout << circle;
        vector2 contact = here + dir * time;
        dir = reflect(dir, center[circle], contact);
        here = contact;
    }
    cout << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        int x, y, dx, dy;
        cin >> x >> y >> dx >> dy >> n;
        vector2 here, dir;
        here = vector2(x, y);
        dir = vector2(dx, dy).normalize();
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y >> radius[i];
            center[i] = vector2(x, y);
        }

        simulate(here, dir);
    }

	return 0;
}
