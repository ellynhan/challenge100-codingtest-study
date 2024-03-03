#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long N, sum = 0;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        sum += i;
    }
    
    cout << sum << "\n" << "2";
}