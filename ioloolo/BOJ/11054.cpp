#include <bits/stdc++.h>

#define MAX 1001

using namespace std;

int N;
int answer;
int arr[MAX];
int DP[2][MAX];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        DP[0][i] = 1;

        for (int j = 1; j <= i; j++) {
            if (arr[j] < arr[i] && DP[0][i] < DP[0][j] + 1) {
                DP[0][i] = DP[0][j] + 1;
            }
        }
    }

    for (int i = N; i >= 1; i--) {
        DP[1][i] = 1;

        for (int j = N; j >= i; j--) {
            if (arr[i] > arr[j] && DP[1][j] + 1 > DP[1][i]) {
                DP[1][i] = DP[1][j] + 1;
            }
        }
    }

    for (int i = 0; i <= N; i++) {
        answer = max(answer, DP[0][i] + DP[1][i] - 1);
    }
    
    cout << answer;

    return 0;
}

