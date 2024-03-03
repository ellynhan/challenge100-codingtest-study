#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int V, A, B, result;
    cin >> A >> B >> V;
    
    if ((V-A) % (A-B) == 0) {
        result = (V - A) / (A - B) + 1;
    } else {
        result = (V-A) / (A - B) + 2;   
    }
    
    cout << result;
}