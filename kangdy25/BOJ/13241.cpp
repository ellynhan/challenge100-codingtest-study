// 최소공배수 / 실버 5

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long int A, B, realA, realB;
    cin >> A >> B;
    realA = A;
    realB = B;
    
    while (A >= 1 && B >= 1) {
        if (A < B) {
            B %= A;
        } else {
            A %= B;
        }
    }
    if (A >= 1) {
        cout << A * (realA / A) * (realB / A);
    } else {
        cout << B * (realA / B) * (realB / B);
    }
}