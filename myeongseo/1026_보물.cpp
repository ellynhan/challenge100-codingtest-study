#include <bits/stdc++.h>

using namespace std;

int N, value, answer=0;
priority_queue<int> A;
priority_queue<int, vector<int>, greater<int>> B;


void input() {
    cin >> N;
    //A 입력
    for(int i=0; i<N; i++) {
        cin >> value;
        A.push(value);
    }
    //B 입력
    for(int j=0; j<N; j++) {
        cin >> value;
        B.push(value);
    }
}


void output() {
    for(int k=0; k<N; k++) {
        answer += A.top()*B.top();
        A.pop(); B.pop();
    }

    cout << answer << endl;
}


int main() {
    input();
    output();
    return 0;
}
