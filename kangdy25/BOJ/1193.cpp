#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int X;
    cin >> X;

    int i = 1;

    while (X > i) {
        X -= i;
        i++;
    }

    if (i % 2 == 0)
        cout << X << "/" << i - X + 1;
    else
        cout << i - X + 1 << "/" << X;
}