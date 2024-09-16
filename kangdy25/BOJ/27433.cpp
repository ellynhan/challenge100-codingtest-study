// 팩토리얼 2 / 브론즈 5 

#include <bits/stdc++.h>
using namespace std;

long long Factorial(long long a) {
    if (a == 0 || a == 1) {
        return 1;
    } else {
        return a * Factorial(a-1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long N;
    cin >> N;
    
    cout << Factorial(N) << "\n";
}
