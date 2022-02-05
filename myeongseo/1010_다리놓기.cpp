#include <bits/stdc++.h>

using namespace std;

int combination(int M, int N) {
    int result = 1;
    for(int i = 0; i<N; i++) {
        result *= (M - i);
        result /= (i+1);
    }
    return result;
}

int main() {
    int testCase, N, M;
    cin >> testCase;
    while(testCase--) {
        cin >> N >> M;
        cout << combination(M,N) <<endl;
    }
}
