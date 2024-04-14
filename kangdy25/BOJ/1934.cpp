// 최소공배수 / 브론즈 1

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, answer[45002] = {0,}, A[45002] = {0,}, B[45002] = {0,};
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> A[i] >> B[i];
    }

    for (int i = 0; i < T; i++) {
        for (int j = 1; j <= min(A[i], B[i]); j++) {
            if (A[i] % j == 0 && B[i] % j == 0) {
                answer[i] = j * (A[i] / j) * (B[i] / j);
            }
        }
        cout << answer[i] << "\n";
    }
}