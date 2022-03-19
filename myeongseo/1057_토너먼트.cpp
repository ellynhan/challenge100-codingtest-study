#include<bits/stdc++.h>

using namespace std;

int N, K, I;
int answer=1;

void input() {
    cin >> N >> K >> I;
}


void nextRound() {
    if(K%2==1) K = (K+1)/2;
    else K = K/2;

    if(I%2==1) I = (I+1)/2;
    else I = I/2;
}


void output() {
    while(true) {
        if(K-I==1 && K%2==0) break;
        else if(I-K==1 && I%2==0) break;
        answer += 1;
        nextRound();
    }
    cout << answer << endl;
}


int main() {
    input();
    output();
}
