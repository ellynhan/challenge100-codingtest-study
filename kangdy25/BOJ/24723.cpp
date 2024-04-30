// 녹색거탑 / 브론즈 4
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, result = 1;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        result *= 2;
    }
    cout << result << "\n";
}