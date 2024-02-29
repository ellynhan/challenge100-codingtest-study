#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int A = 1, B = 1;
    while (A != 0 && B != 0) {
        cin >> A >> B;
        if (A == 0 && B == 0) {
            break;
        } else if (A % B == 0) {
            cout << "multiple" << "\n";
        } else if (B % A == 0) {
            cout << "factor" << "\n";
        } else {
            cout << "neither" << "\n";
        } 
    }
}