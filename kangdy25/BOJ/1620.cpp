#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> pokemon1;
    map<int, string> pokemon2;
    map<string, int>::iterator it;
    int N, M;
    string value, search;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> value;
        pokemon1.insert({ value, i });
        pokemon2.insert({ i, value });
    }
    
    for (int j = 0; j < M; j++) {
        cin >> search;
        
        if (isdigit(search[0])) {
            int num = stoi(search);
            cout << pokemon2[num] << "\n";
        } else {
            cout << pokemon1[search] << "\n";
        }
    }
}