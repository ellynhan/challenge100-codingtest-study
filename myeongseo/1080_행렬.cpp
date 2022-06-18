#include <bits/stdc++.h>

using namespace std;

char A[50][50], B[50][50];
int N, M;
string row;
int answer = 0;

void input() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> row;
        for(int j=0; j<M; j++) {
            A[i][j] = row[j];
        }
    }

    for(int i=0; i<N; i++) {
        cin >> row;
        for(int j=0; j<M; j++) {
            B[i][j] = row[j];
        }
    }
}

// 3x3 뒤집기 (만약 범위 이상이면 false)
bool flip(int n, int m) {
    if(n+2>=N) return false;
    else if(m+2>=M) return false;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(A[n+i][m+j]=='0') A[n+i][m+j] = '1';
            else A[n+i][m+j] = '0';
        }
    }
    return true;
}

void solve() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(A[i][j] != B[i][j]) {
                if( flip(i, j) ) answer++;
                else { answer=-1; return; }
            }
        }
    }
}

void output() {
    cout << answer << endl;
}

int main() {
    input();
    solve();
    output();
    return 0;
}
