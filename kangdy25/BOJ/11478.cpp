#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    set<string> partS;
    string S, sliceS;
    cin >> S;

    for (int i = 0; i < S.length(); i++) {
        for (int j = 0; j < S.length() - i; j++) {
            sliceS = S.substr(j, i + 1);
            partS.insert(sliceS);
        }
    }
    cout << partS.size() << "\n";
}