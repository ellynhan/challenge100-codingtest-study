#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[101][101];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            arr[i][j] = 1e9;
        }
    }

    for (int i = 0; i < M; i++) {
        int v, e, w;
        cin >> v >> e >> w;

        if (arr[v][e] > w) {
            arr[v][e] = w;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (arr[j][i] != 1e9 && arr[i][k] != 1e9) {
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << (i == j || arr[i][j] == 1e9 ? 0 : arr[i][j]) << " ";
        }
        cout << '\n';
    }

    return 0;
}

