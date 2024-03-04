#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    
    if ((a + b + c - max({a, b, c})) <= max({a, b, c})) {
        cout << 2 * (a + b + c - max({a, b, c})) - 1;
    } else {
        cout << a + b + c;
    }
    
}