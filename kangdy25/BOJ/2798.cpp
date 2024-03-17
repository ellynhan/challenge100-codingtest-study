#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, maxValue = 0, blackJack = 0;
    int arr[102] = {};
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                blackJack = arr[i] + arr[j] + arr[k];
                if (blackJack >= maxValue && blackJack <= M) {
                    maxValue = blackJack;
                }
            }
        }
    }
    cout << maxValue;
}