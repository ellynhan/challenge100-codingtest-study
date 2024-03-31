#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<int, int> AB;
    pair<map<int, int>::iterator, bool> pr;
    
    int M, N, value, count = 0;
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        cin >> value;
        AB.insert(pair<int, int>(value, 1));
    }
    for (int i = 0; i < N; i++) {
        cin >> value;
        pr =AB.insert(pair<int, int>(value, 1));
        if (!pr.second) {
            AB[value]++;
        }
    }
    for (auto it = AB.begin(); it != AB.end(); it++) {
        if (it->second == 1) {
            count++;
        }
    }
    cout << count << "\n";
}