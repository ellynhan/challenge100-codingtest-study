#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    while (!isPrime(N)) {
        for (int i = 2; i * i <= N; i++) {
            if (N % i == 0) {
                cout << i << "\n";
                N = N / i;
                break;
            }
        }
    }
    
    if (N > 1) {
        cout << N;
    }
}