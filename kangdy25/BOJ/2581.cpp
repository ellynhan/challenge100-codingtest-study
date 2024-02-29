#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int M, N, sum = 0;
    cin >> M >> N;
    int small = -1;
    
    while(M <= N) {
        bool check = true;
        if (M <= 1) check = false;
        for (int i = 2; i * i <= M; i++) {
            if (M % i == 0) {
                check = false;
                break;
            }
        }
        
        if (check == true) {
            sum += M;
            if (small == -1) {
                small = M;
            }
        }
        M++;
    }
    if (sum == 0) {
        cout << "-1";
    } else {
        cout << sum << "\n" << small;
    }
}