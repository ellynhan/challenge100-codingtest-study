// 1021 실버4 회전하는 큐
// https://www.acmicpc.net/problem/1021

#include<bits/stdc++.h>

using namespace std;

int N, M, element;
int target[50];
int now=1, resultL, resultR, answer;

void input() {
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        cin >> element;
        target[i] = element;
    }
}


void left(int now,int j) {
    if(now < target[j]) resultL = target[j] - now;
    else resultL = N - now + target[j];
  
    for(int k=0; k<j; k++) {
        // now를 target[j]+1로 설정하기 때문에
        // 이전 target[k]에서 걸려 없어진 경우를 고려해야함
        if(target[k]==now) resultL-=1;
        //nkj 또는 kjn 또는 jnk
        else if(now<target[k]&&target[k]<target[j]) resultL-=1;
        else if(target[k]<target[j]&&target[j]<now) resultL-=1;
        else if(target[j]<now&&now<target[k]) resultL-=1;
    }
}


void right(int now,int j) {
    if(now > target[j]) resultR = now - target[j];
    else resultR = N - target[j] + now;
  
    for(int k=0; k<j; k++) {
        //target[k]==now인 경우를 고려하지 않음

        //njk 또는 jkn 또는 knj
        if(now<target[j]&&target[j]<target[k]) resultR-=1;
        else if(target[j]<target[k]&&target[k]<now) resultR-=1;
        else if(target[k]<now&&now<target[j]) resultR-=1;
    }
}


void output() {
    for(int j=0; j<M; j++) {
        if(now==target[j]) { now++; continue; }
        left(now, j);
        right(now, j);
        answer += min(resultL, resultR);
        now = target[j]+1;
    }
    cout << answer <<endl;
}


int main() {
    input();
    output();
    return 0;
}
