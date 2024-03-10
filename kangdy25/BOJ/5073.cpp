#include <bits/stdc++.h>
using namespace std;

int whatIsMax(int a, int b, int c) {
    int max_value = max({a, b, c}); 
    return max_value;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c;
    
    while(1) {
        cin >> a >> b >> c;
        // 모두 0인 경우
        if (a == 0 && b == 0 && c == 0) {
            break;
        } else if (whatIsMax(a, b, c) >= (a + b + c) - whatIsMax(a, b, c)) {
            cout << "Invalid" << "\n";
        } else if (a == b && b == c) {
            cout << "Equilateral" << "\n";
        } else if ((a == b && b != c) ||
                    (a == c && b != c) ||
                    (b == c && a != c)) {
            cout << "Isosceles" << "\n";
        } else {
            cout << "Scalene" << "\n";
        }
    }
    
}