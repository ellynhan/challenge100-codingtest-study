// 가로수 / 실버 4

#include <bits/stdc++.h>
using namespace std;

int inputArr[100002];
int diffArr[100002];

long long int GCD(long long int a, long long int b) {
    while (a >= 1 && b >= 1) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    if (a >= 1) {
        return a;
    } 
    return b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, count;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> inputArr[i];
        if (i >= 1) {
            diffArr[i-1] = inputArr[i] - inputArr[i-1];
        }
    }
    
    int firstValue = diffArr[0];
    
    for (int i = 0; i < N; i++) {
        firstValue = GCD(firstValue, diffArr[i]);
    }
    
    count = (inputArr[N-1] - inputArr[0]) / firstValue - N + 1;
    cout << count << "\n";
}