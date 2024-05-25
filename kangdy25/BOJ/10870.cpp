// 피보나치 수 5 / 브론즈 2

#include <bits/stdc++.h>
using namespace std;

int Fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return Fibonacci(n - 2) + Fibonacci(n - 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    cout << Fibonacci(N) << "\n";
}