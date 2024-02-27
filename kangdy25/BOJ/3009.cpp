#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x[3], y[3], X, Y;
    for (int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
    }
    // X 찾기
    if (x[0] == x[1] && x[1] != x[2]) {
        X = x[2];
    } else if (x[0] == x[2] && x[1] != x[2]) {
        X = x[1];
    } else if (x[1] == x[2] && x[0] != x[1]) {
        X = x[0];
    }
    
    // Y 찾기
    if (y[0] == y[1] && y[1] != y[2]) {
        Y = y[2];
    } else if (y[0] == y[2] && y[1] != y[2]) {
        Y = y[1];
    } else if (y[1] == y[2] && y[0] != y[1]) {
        Y = y[0];
    }
    
    cout << X << " " << Y;
}