//
//  DARPA.cpp
//  main
//
//  Created by wi_seong on 1/16/24.
//

/*
 [Input]
 3
 2 4
 80 100 120 140
 4 4
 80 100 120 140.00
 4 7
 0 70 90 120 200 210 220
 [Output]
 60.00
 20.00
 50.00
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 20,000
// 난이도: 중
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/DARPA

#include <iostream>
#include <vector>

using namespace std;
int t, n, m;
int ans;
vector<double> locations;

bool decision(const vector<double>& location, int cameras, double gap) {
    double limit = -1;
    int installed = 0;

    for(int i = 0; i < location.size(); i++) {
        if(limit <= location[i]) {
            limit = location[i] + gap;
            installed++;
        }
    }

    return installed >= cameras;
}

double optimize(const vector<double>& location, int cameras) {
    double lo = 0, hi = 241;

    for(int i = 0; i < 100; i++) {
        double mid = (lo + hi) / 2.0;
        if(decision(location, cameras, mid)) {
            lo = mid;
        } else {
            hi = mid;
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
        cin >> n >> m;
        locations.clear();
        for(int i = 0; i < m; i++) {
            double pos; cin >> pos;
            locations.push_back(pos);
        }

        cout << optimize(locations, n) << '\n';
    }

	return 0;
}
