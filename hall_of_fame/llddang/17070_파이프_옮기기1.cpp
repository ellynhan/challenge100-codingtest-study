#include <iostream>
using namespace std;

int N;
int map[16][16];
int answer = 0;

void solve(int ci, int cj, int shape){
    if(ci == N-1 && cj == N-1){
        answer++;
        return;
    }

    if(shape != 3 && ci < N && cj + 1 < N){
        if(map[ci][cj+1] != 1)
            solve(ci, cj+1, 1);
    }

    if(ci+1 < N && cj+1 < N){
        if(map[ci][cj+1] != 1 && map[ci+1][cj] != 1 && map[ci+1][cj+1] != 1)
            solve(ci+1, cj+1, 2);
    }

    if(shape != 1 && ci + 1 < N && cj < N){
        if(map[ci+1][cj] != 1)
            solve(ci+1, cj, 3);
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
    for(int j=0; j<N; j++) cin >> map[i][j];

    solve(0,1,1);

    cout << answer;
}
