#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;
priority_queue<pair<int, int>> A;
int testCase, element;
priority_queue<pii, vector<pii>, greater<pii>> result;

void input() {
    cin >> testCase;
    int N = testCase, i=0;
    while(N--) {
        cin >> element;
        A.push({element,i});                            // a[i] = element
        i++;
    }                                                   // element를 기준으로 내림차순
}


void solve() {
    while(!A.empty()) {
        result.push({A.top().second, --testCase});      // P[i] = --testCase
        A.pop();
    }                                                   // i를 기준으로 오름차순
}


void output() {
    while(!result.empty()) {
        cout << result.top().second << " ";            //P[0]부터 P[N-1]까지 출력
        result.pop();
    }
}


int main() {
    input();
    solve();
    output();
    return 0;
}
