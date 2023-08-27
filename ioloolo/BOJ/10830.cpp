#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, B;

ll arr[5][5];
ll cpy[5][5];
ll answer[5][5];

void multiply(ll x[5][5], ll y[5][5]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cpy[i][j] = 0;

            for (int k = 0; k < N; k++) {
                cpy[i][j] += (x[i][k] * y[k][j]);
            }

            cpy[i][j] %= 1000;
        }
    }

    memcpy(x, cpy, sizeof(cpy));
}

int main() {
    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        answer[i][i] = 1;

        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    while (B > 0) {
        if (B % 2 == 1) {
            multiply(answer, arr);
        }

        multiply(arr, arr);

        B /= 2;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

