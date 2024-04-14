// 골드바흐 파티션 / 실버 2

#include <bits/stdc++.h>
using namespace std;

vector<bool> v;
int T, N;

void isPrime() {
    v[0] = false;
    v[1] = false;
    
    for (int i = 2; i * i <= v.size(); i++) {
        if (v[i] == true) {
            for (int j = 2; i * j < v.size(); j++) {
                v[i * j] = false;
            }
        }
    }
}

int goldbach() {
    int count = 0;
    for (int n = 2; n < N / 2 + 1; n++) {
        if (v[n] == true && v[N - n] == true) {
            count++;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    
    v.assign(1000001, true);
    
    isPrime();
    
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << goldbach() << "\n";
    }
}