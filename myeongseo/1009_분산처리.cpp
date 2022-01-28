#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> lastData;
vector<int> result;
int a, b;

void input() {
    int testCase;
    cin >> testCase;
    while(testCase--) {
        cin >> a >> b;
        lastData.push_back({a,b});
    }
}

void solve() {
    int answer;
    for(auto d :lastData) {
        a = d.first;
        b = d.second;
        answer = 1;
        for(int i=0; i<b; i++) {
            answer *= a;
            answer %= 10;
        }
        if(answer == 0) result.push_back(10);
        else result.push_back(answer);
    }
}

void output() {
    for(auto r : result)
        cout << r << endl;
}

int main() {
    input();
    solve();
    output();
    return 0;
}
