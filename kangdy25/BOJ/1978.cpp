#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, num;
    cin >> N;
    
    int count = N;
    
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num == 1) {
            count--;
        }
        
        for (int j = 2; j * j <= num; j++) {
            if (num % j == 0) {
                count--;
                break;
            }
        }
    }
    cout << count;
}