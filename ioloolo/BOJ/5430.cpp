#include <bits/stdc++.h>

using namespace std;

deque<int> dq;

bool solution(string& command){
    bool rev = false;
    
    for (char& cmd : command) {
        if (cmd == 'R') {
            rev = !rev;
        } else {
            if (dq.empty()) return false;

            if (rev) dq.pop_back();
            else dq.pop_front();
        }
    }
    
    if (rev) reverse(dq.begin(), dq.end());
    
    return true;
}

int main () {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string command, line, token;
    int T, cnt;
    
    cin >> T;
    while (T--) {
        cin >> command >> cnt >> line;

        rotate(line.begin(), line.begin() + 1, line.end());
        line.pop_back();
        line.pop_back();
        
        stringstream sstream(line);
        while (getline(sstream, token, ',')) {
            dq.push_back(stoi(token));
        }

        if (solution(command)) {
            cout << '[';
            while(!dq.empty()) {
                cout << dq.front();
                dq.pop_front();
                if (!dq.empty()) cout << ',';
            }
            cout << "]\n";
        } else {
            cout << "error\n";
        }
    }
}

