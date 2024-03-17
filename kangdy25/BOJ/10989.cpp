#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    int input[10001] = { 0, };

    for(int i = 0; i < N; i++) {
        int in;
        cin >> in;
        input[in]++;
    }

    for (int i = 1; i < 10001; i++) {
        for (int j = 0; j < input[i]; j++) {
            cout << i << '\n';
        }
    }
}