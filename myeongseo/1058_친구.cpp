#include<bits/stdc++.h>

using namespace std;

char friends[50][50];
string friendRow;
int N, result, answer=0;

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> friendRow;
        for(int j=0; j<N; j++) {
            friends[i][j] = friendRow[j];
        }
    }
}


// k와 m이 한다리 건너 아는지
bool know(int k, int m) {
    for(int n=0; n<N; n++) {
        if(friends[k][n]=='Y' && friends[n][m]=='Y') return true;
    }
    return false;
}


// k의 친구 세기
int countFriend(int k) {
    result = 0;
    for(int m=0; m<N; m++) {
        if(m==k) continue;
        else if(friends[k][m] == 'Y') { result += 1; } // 친구일 때
        else if(know(k, m)) { result += 1; } // 한다리 건너 알 때
    }
    return result;
}


void output() {
    for(int k=0; k<N; k++) {
        answer = max(answer, countFriend(k));
    }
    cout << answer << endl;
}


int main() {
    input();
    output();
}
