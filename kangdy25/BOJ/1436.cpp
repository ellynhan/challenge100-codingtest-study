#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    int devil = 666;
    int series = 0;
    string target;
    
    while(1) {
        target = to_string(devil);
        for (int i = 0; i < target.length() - 2; i++) {
            if (target[i] == '6' && target[i+1] == '6' && target[i+2] == '6') {
                series++;
                if (series == N) {
                    cout << devil << "\n";
                    return 0;
                }
                break;
            }
        }
        devil++;
    }
}