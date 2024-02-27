#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K, count = 0;
    cin >> N >> K;
    
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            count++;
        }
        if (count == K) {
            cout << i;
            break;
        }
    }
    if (count < K) {
        cout << "0";
    }
}