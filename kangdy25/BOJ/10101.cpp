#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int A, B, C;
    cin >> A >> B >> C;
    
    if (A == 60 && B == 60 && C == 60) {
        cout << "Equilateral";
    } else if (A + B + C == 180 && (A == B || B == C || C == A)) {
        cout << "Isosceles";
    } else if (A + B + C == 180 && (A != B && B != C && C != A)) {
        cout << "Scalene";
    } else {
        cout << "Error";
    }
}