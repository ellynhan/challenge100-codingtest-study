// 다음 소수 / 실버 4

#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long A) {
    for (long long i = 2; i * i <= A; i++) {
        if (A % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N, value, result;
    cin >> N;

    for (long long i = 0; i < N; i++) {
        cin >> value;
        for (long long j = value; j < 4000000008; j++) {
            if (j == 0 || j == 1) {
                cout << "2" << "\n";
                break;
            } else if (isPrime(j)) {
                result = j;
                cout << result << "\n";
                break;
            }
        }
    }
}