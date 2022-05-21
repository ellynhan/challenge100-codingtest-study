#include <bits/stdc++.h>

using namespace std;

int M, N, repaintB, repaintW;
int result = 50;
char color;
int B[50][50] = {0,};                    // start가 B, 다시 칠해야하면 1
int W[50][50] = {0,};                    // start가 W, 다시 칠해야하면 1

void input() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> color;
            if(color == 'W') {
                W[i][j] = (i+j)%2;       //i+j가 짝수이면(원래 W부분이면) 0
                B[i][j] = (i+j+1)%2;     //i+j가 홀수이면 0

            }
            else {
                W[i][j] = (i+j+1)%2;    //i+j가 홀수이면(원래 B부분이면) 0
                B[i][j] = (i+j)%2;      //i+j가 짝수이면 0
            }
        }
    }
}


void chess8x8(int n, int m) {
    //8*8 내에서
    for(int k=n; k<n+8; k++) {
        for(int p=m; p<m+8; p++) {
            if(W[k][p]==1) repaintW+=1; //W중 1인것 개수
            if(B[k][p]==1) repaintB+=1; //B중 1인것 개수
        }
    }
    if(result > repaintW) result = repaintW;
    if(result > repaintB) result = repaintB;
}


void solve() {
    //8*8 시작/끝 범위 지정
    for(int n=0; n<N-7; n++) {
        for(int m=0; m<M-7; m++) {
            repaintW=0; repaintB=0;
            chess8x8(n, m);
        }
    }
}


void output() {
    cout << result << endl;
}


int main() {
    input();
    solve();
    output();
    return 0;
}
