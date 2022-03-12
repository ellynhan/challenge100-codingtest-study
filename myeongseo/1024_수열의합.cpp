#include <bits/stdc++.h>

using namespace std;

int N, L;
int answer=0, len=0;

void input() {
    cin >> N >> L;
}


void solve() {
    //len을 L이상의 길이로
    while(len<L) {answer += len; len++;}

    // a a+1 a+2 a+3 .... => (len*a) + (answer=0+1+2...)
    while((N-answer)%len!=0) { answer += len; len++;}
}


void output() {
    if(len>100) cout << -1;
    else if(N-answer<0) cout << -1;
    else {
        for(int i=0; i<len; i++) {
            cout << (N-answer)/len + i << " ";
        }
    }
}


int main() {
    input();
    solve();
    output();
    return 0;
}
