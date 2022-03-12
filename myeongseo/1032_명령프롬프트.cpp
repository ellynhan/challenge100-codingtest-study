#include <bits/stdc++.h>

using namespace std;

int N;
string patern, file;

int main() {
    cin >> N;
    cin >> patern;

    while(--N) {
        cin >> file;

        for(int i=0; i<patern.length(); i++) {
            if(patern[i]=='?') continue;
            else if(patern[i]==file[i]) continue;
            else patern[i] = '?';
        }

    }
    cout << patern << endl;
}
