#include<bits/stdc++.h>

using namespace std;

int N, M, answer=1;
string numbers;
int rectangle[50][50];


// 정사각형의 밑의 열에도 같은 숫자가 있는지 확인
void findPair(int row1, int col1, int col2) {
    int row2 = row1 + col2 - col1;
    if (row2 >= N) return;
    else if (rectangle[row2][col1]==rectangle[row2][col2] && rectangle[row2][col2]==rectangle[row1][col1]) {
            answer = max(answer, (row2-row1+1)*(col2-col1+1));
    }
}


//하나의 열에 같은 숫자 두개이상인지 확인
void sameRow(int n) {
    for(int k=0; k<M; k++) {
        for(int m=k+1; m<M; m++) {
            // 다른 행에 같은 숫자의 열 있는지 확인
            if(rectangle[n][k] == rectangle[n][m]) findPair(n, k, m);
        }
    }
}


int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> numbers;
        for(int j=0; j<M; j++) {
            rectangle[i][j] = numbers[j]-'0';
        }
    }

    for(int n=0; n<N; n++) {
        sameRow(n);
    }

    cout << answer << endl;
}
