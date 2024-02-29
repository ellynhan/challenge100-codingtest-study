#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, div, p = 0, arr[200000] = {};

    while(1) {
        cin >> n;
        if (n == -1) {
            break;
        } 
        
        div = 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                arr[p++] = i;
                div += i;
            }
        }

        if (div == n) {
            cout << n << " = ";
            for (int k = 0; k < p - 1; k++) {
                cout << arr[k] << " + "; 
                arr[k] = 0;
            }   
            cout << arr[p - 1] << "\n";
            arr[p - 1] = 0;
        } else {
            cout << n << " is NOT perfect." << "\n";
        }
        p = 0;
    }
}