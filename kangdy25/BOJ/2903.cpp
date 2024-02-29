#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, P = 1, result;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        P = 2 * P;
    }
    P = P + 1;
    P = P * P;
    cout << P;
}
