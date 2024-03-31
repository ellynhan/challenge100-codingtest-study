#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    string name, state;
    map<string, string, greater<string>> log;
    map<string, string>::iterator it;
    
    for (int i = 0; i < N; i++) {
        cin >> name >> state;
        log[name] = state;
    }
    for (it = log.begin(); it != log.end(); it++) {
        if (it->second == "enter") {
            cout << it->first << "\n";
        }
    }
}