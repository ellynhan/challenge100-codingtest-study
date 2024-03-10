#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    
    int dx, dy, dw, dh;
    dx = x - 0;
    dy = y - 0;
    dw = w - x;
    dh = h - y;
    int arr[4] = {dx, dy, dw, dh};
    
    cout << *min_element(arr, arr+4);
}