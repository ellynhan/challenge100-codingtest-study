#include <iostream>
using namespace std;

int N;
string arr[64];
string answer = "";

void solve(int ci, int cj, int n){
    int i, j;
    for(i=ci; i<ci+n; i++){
        for(j=cj; j<cj+n; j++){
            if(arr[ci][cj] != arr[i][j]) break;
        }
        if(j != cj+n) break;
    }

    if(i != ci+n){
        n /= 2;
        answer += '(';
        solve(ci, cj, n);
        solve(ci, cj+n, n);
        solve(ci+n, cj, n);
        solve(ci+n, cj+n, n);
        answer += ')';
    } else {
        answer += arr[ci][cj];
    }
}


int main(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];

    solve(0, 0, N);

    cout << answer;
}
