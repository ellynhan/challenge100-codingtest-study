#include <bits/stdc++.h>

#define MAX 2001

using namespace std;

int N, M;
int arr[MAX];
bool flag[MAX][MAX];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            flag[i][i + 1] = true;
        }
    }

    for (int i = 1; i <= N; i++) {
        flag[i][i] = true;
    }

    for (int i = N - 1; i >= 1; i--) {
        for (int j = i + 2; j <= N; j++) {
            if (arr[i] == arr[j] && flag[i + 1][j - 1]) {
                flag[i][j] = true;
            }
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;

        cout << flag[s][e] << '\n';
    }

    return 0;
}

