#include <iostream>
using namespace std;

int arr[128][128];
int white = 0, blue = 0;

void confetti(int ci, int cj, int n){
    int prev = arr[ci][cj];
    for(int i=ci; i<ci + n; i++){
        for(int j=cj; j<cj + n; j++){
            if(prev == arr[i][j]) continue;

            confetti(ci, cj, n / 2);
            confetti(ci, cj + n/2, n/2);
            confetti(ci + n/2, cj, n / 2);
            confetti(ci + n/2, cj + n/2, n / 2);
            
            return;
        }
    }
    if(prev == 1) blue++;
    else white++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    for(int i=0; i<N; i++)
    for(int j=0; j<N; j++) cin >> arr[i][j];
    
    confetti(0, 0, N);
    cout << white << "\n" << blue;
}
