// 소수 구하기 / 실버 3

#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long A) {
    for (int i = 2; i * i <= A; i++) {
        if (A % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int M, N;
    cin >> M >> N;
    
    for (int j = M; j <= N; j++) {
        if (j == 1) {
            continue;
        } else if (j == 2) {
            cout << "2" << "\n";
        } else if (isPrime(j)) {
            cout << j << "\n";
        }
    }

}