#include<iostream>

using namespace std;
int paper[2200][2200];
int answer[3];

bool isPaper(int x, int y, int len){
    int paperNum = paper[x][y];
    for(int i=x; i<x+len; i++){
        for(int j=y; j<y+len; j++){
            if(paper[i][j] != paperNum) return false;
        }
    }
    return true;
}

void solve(int x, int y, int len){
    if(isPaper(x, y, len)) answer[paper[x][y] + 1]++;
    else{
        len /= 3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                solve(x + len*i, y + len*j, len);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> paper[i][j];
        }
    }
    solve(0, 0, N);

    cout << answer[0] << '\n' << answer[1] << '\n' << answer[2];
}