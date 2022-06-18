#include <bits/stdc++.h>

using namespace std;

int L, s, n;
int startN1, startN2, endN1;
priority_queue<int, vector<int>, greater<int>> S;

void input() {
    cin >> L;
    for(int i=0; i<L; i++) {
        cin >> s;
        S.push(s);
    }
    cin >> n;
}


void solve() {
    s = 0;
    while(!S.empty()) {
        if(S.top()==n) { cout << 0 << endl; break; }
        if(n<S.top()) {
            // n이 start에 포함되는 경우 (end가 n이 아닌 경우)
            startN1 = n - s;
            endN1 = S.top() - n - 1;
            // end가 n인 경우
            startN2 = n - 1 - s;
            // n이 S내에 있을 때
            cout << startN1 * endN1 + startN2;
            break;
        }
        s = S.top();
        S.pop();
    }
}


int main() {
    input();
    solve();
    return 0;
}
