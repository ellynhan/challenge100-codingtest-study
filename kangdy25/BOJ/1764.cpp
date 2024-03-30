#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> deudbo;
    pair<map<string, int>::iterator, bool> pr;

    int N, M, count = 0;
    string S;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> S;
        deudbo.insert(pair<string, int>(S, 1));
    }
    for (int i = 0; i < M; i++) {
        cin >> S;
        pr = deudbo.insert(pair<string, int>(S, 1));
        if (!pr.second) {
            deudbo[S]++;
        }
    }

    for (auto it = deudbo.begin(); it != deudbo.end(); it++) {
        if (it->second == 2) {
            count++;
        }
    }
    cout << count << "\n";

    for (auto it = deudbo.begin(); it != deudbo.end(); it++) {
        if (it->second == 2) {
            cout << it->first << "\n";
        }
    }
}