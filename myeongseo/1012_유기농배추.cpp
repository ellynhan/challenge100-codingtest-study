#include <bits/stdc++.h>

using namespace std;

int M, N, K;
int x, y, worm;
array<array<int, 50>, 50> field = {0,};


void input() {
    cin >> M >> N >> K;
    int k = K;
    while(k--) {
        cin >> x >> y;
        field[x][y] = 1;
    }
}

void dfs(int x, int y) {
    field[x][y] = 0;
    if(y+1 < N && field[x][y+1]==1) dfs(x, y+1);
    if(y-1 >= 0 && field[x][y-1]==1) dfs(x, y-1);
    if(x+1 < M && field[x+1][y]==1) dfs(x+1, y);
    if(x-1 >= 0 && field[x-1][y]==1) dfs(x-1, y);
}

void solve() {
    worm = 0;
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(field[i][j] == 1) { dfs(i, j); worm += 1; }
        }
    }
}

void output() {
    cout << worm << endl;
}

int main() {
    int testCase;
    cin >> testCase;
    while(testCase--) {
        input();
        solve();
        output();
    }
    return 0;
}
