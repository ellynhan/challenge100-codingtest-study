#include <bits/stdc++.h>

#define MAX 101

using namespace std;

int n, m, r;
int arr[MAX];
int dist[MAX][MAX];

int answer;
int cnt;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                dist[i][j] = 1e7;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < r; i++) {
        int v, e, l;
        cin >> v >> e >> l;

        dist[v][e] = l;
        dist[e][v] = l;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cnt = arr[i];

        for (int j = 0; j <= n; j++) {
            if (i != j && dist[i][j] <= m) {
                cnt += arr[j];
            }
        }

        answer = max(answer, cnt);
    }

    cout << answer;

    return 0;
}

