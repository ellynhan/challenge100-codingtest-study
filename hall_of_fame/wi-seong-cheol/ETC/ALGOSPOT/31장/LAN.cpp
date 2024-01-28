//
//  LAN.cpp
//  main
//
//  Created by wi_seong on 1/28/24.
//

/*
 [Input]
 2
 3 1
 0 0 1
 0 1 2
 0 1
 10 5
 -7 -7 10 -4 10 -4 -5 0 -10 -6
 6 8 -5 3 -4 6 -10 4 -7 10
 9 7
 7 3
 9 7
 5 0
 8 6
 [Output]
 1.4142135624
 29.7042202421
 */
// 시간복잡도: O(V ^ 2 + E)
// 최악시간: 252,000
// 난이도: 하
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/LAN

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int INF = 987654321;
const int MXN = 501;
int t, V, E, u, v;
vector<vector<double>> dist;
int x[MXN], y[MXN];

double prim() {
    vector<bool> added(V, false);
    vector<double> minWeight(V, INF);
    double ret = 0;
    minWeight[0] = 0;

    for(int iter = 0; iter < V; iter++) {
        int u = -1;
        for(int v = 0; v < V; v++) {
            if(!added[v] && (u == -1 || minWeight[u] > minWeight[v])) {
                u = v;
            }
        }

        ret += minWeight[u];
        added[u] = true;

        for(int v = 0; v < V; v++) {
            double weight = dist[u][v];
            if(!added[v] && minWeight[v] > weight) {
                minWeight[v] = weight;
            }
        }
    }

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.precision(10);
    cout << fixed;

    cin >> t;
    while(t--) {
        cin >> V >> E;
        dist = vector<vector<double>>(V, vector<double>(V, -1));
        for(int i = 0; i < V; i++) {
            cin >> x[i];
        }
        for(int i = 0; i < V; i++) {
            cin >> y[i];
        }
        for(int i = 0; i < E; i++) {
            cin >> u >> v;
            dist[u][v] = dist[v][u] = 0;
        }
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(dist[i][j] == -1) {
                    dist[i][j] = dist[j][i] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
                }
            }
        }

        cout << prim() << '\n';
    }

	return 0;
}
