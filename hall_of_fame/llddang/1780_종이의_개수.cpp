#include <iostream>
using namespace std;

int arr[2187][2187];
int zeroCnt = 0;
int oneCnt = 0;
int minusCnt = 0;

void countConfetti(int ci, int cj, int n){
    int i, j, color = arr[ci][cj];
    for(i=ci; i<ci+n; i++){
        for(j=cj; j<cj+n; j++){
            if(color != arr[i][j]) break;
        }
        if(j != cj+n) break;
    }

    if(i == ci+n){
        if(color == -1) minusCnt++;
        else if(color == 0) zeroCnt++;
        else oneCnt++;
        return;
    }

    n /= 3;
    for(i=0; i<3; i++)
    for(j=0; j<3; j++)
        countConfetti(ci + n*i, cj + n*j, n);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    for(int i=0; i<N; i++)
    for(int j=0; j<N; j++) cin >> arr[i][j];

    countConfetti(0, 0, N);

    cout << minusCnt << "\n";
    cout << zeroCnt << "\n";
    cout << oneCnt << "\n";
}
