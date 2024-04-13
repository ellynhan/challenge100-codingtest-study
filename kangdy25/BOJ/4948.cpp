// 베르트랑 공준 / 실버 2

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int a) {
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, count;
    
    while(1) {
        count = 0;
        cin >> N;
        if (N == 0) {
            break;
        } else if (N == 1) {
            cout << "1" << "\n";
        } else {
            for (int i = N + 1; i <= 2 * N; i++) {
                if (isPrime(i)) {
                    count++;
                }
            }
            cout << count << "\n";
        }
        
    }
}