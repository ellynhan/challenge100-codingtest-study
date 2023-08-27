#include <bits/stdc++.h>

#define MAX 1001

using namespace std;

int arr[MAX];
map<int, int> result;
map<int, int> cost;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N, K, W;
        cin >> N >> K;

        vector<vector<int>> v(N + 1);
        queue<int> q;

        for (int j = 1; j <= N; j++) {
            int n;
            cin >> n;

            cost[j] = n;
            result[j] = n;
        }

        for (int j = 0; j < K; j++) {
            int x, y;
            cin >> x >> y;

            v[x].emplace_back(y);
            arr[y]++;
        }

        cin >> W;

        for (int j = 1; j <= N; j++) {
            if (j == W) continue;
            if (arr[j] != 0) continue;

            q.emplace(j);
        }

        while (!q.empty()) {
            auto k = q.front();
            q.pop();

            for (int j = 0; j < v[k].size(); j++) {
                int n = v[k][j];

                result[n] = max(result[n], result[k] + cost[n]);
                
                if (--arr[n] == 0) {
                    q.emplace(n);
                }
            }
        }

        cout << result[W] << '\n';

        for (int j = 1; j <= N; j++) {
            arr[j] = 0;
            result[j] = 0;
            cost[j] = 0;
        }
    }

    return 0;
}

