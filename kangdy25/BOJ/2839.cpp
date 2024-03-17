#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, five = 0, three = 0, totalCount = 5000, value = 0;
    cin >> N;
    
    for (int fiveCount = 0; fiveCount * 5 <= N; fiveCount++) {
        value = N - (fiveCount * 5); 
        if (value % 3 == 0) {
            three = value / 3;
            five = fiveCount;
            if (three + five < totalCount) {
                totalCount = three + five;
            }
        }
    }
    if (totalCount == 5000) {
        cout << "-1";
    } else {
        cout << totalCount;
    } 
}