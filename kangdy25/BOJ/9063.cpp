#include <bits/stdc++.h>
using namespace std;

int N, x[100000], y[100000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    
    int maxX = *max_element(x, x + N);
    int minX = *min_element(x, x + N);
    
    int maxY = *max_element(y, y + N);
    int minY = *min_element(y, y + N);
    
    if (N == 1) {
        cout << "0";
    } else {
        cout << (maxX - minX) * (maxY - minY);
    }
}