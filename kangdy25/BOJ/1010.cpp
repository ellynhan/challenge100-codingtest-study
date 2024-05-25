// 다리 놓기 / 실버 5

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, result = 1;
    cin >> N >> K;
    int NK = N - K;

    for (int i = N; i >= 1; i--) {
        result *= i;
    }
    for (int j = K; j >= 1; j--) {
        result /= j;
    }
    for (int j = NK; j >= 1; j--) {
        result /= j;
    }
    cout << result << "\n";
}