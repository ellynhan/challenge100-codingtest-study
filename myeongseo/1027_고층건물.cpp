#include <bits/stdc++.h>

using namespace std;

int N, height;
int buildings[50];
double gradient, maxG;
int canSee, maxN=0;


void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> height;
        buildings[i] = height;
    }
}


void left(int j) {
    maxG = -1000000000;
    for(int k=j-1; k>=0; k--) {
        gradient = (buildings[k]-buildings[j])/double(j-k);
        if(gradient > maxG) {
            canSee++;
            maxG = gradient;
        }
    }
}


void right(int j) {
    maxG = -1000000000;
    for(int m=j+1; m<N; m++) {
        gradient = (buildings[m]-buildings[j])/double(m-j);
        if(gradient > maxG) {
            canSee++;
            maxG = gradient;
        }
    }
}


void solve() {
    for(int j=0;j<N; j++) {
        canSee=0;
        left(j); //해당 건물 j에서 왼쪽을 바라볼때
        right(j); //해당 건물 j에서 오른쪽을 바라볼때
        if(canSee > maxN) { maxN = canSee; }
    }
}


void output() {
    cout << maxN << endl;
}


int main() {
    input();
    solve();
    output();
    return 0;
}
