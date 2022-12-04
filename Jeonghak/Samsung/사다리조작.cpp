#include<iostream>
#include<vector>
#define MAX_DEPTH 4
using namespace std;

int N, M, H;
int answer = MAX_DEPTH;

vector<vector<int>> ladder;

bool isClear() {
    for(int i=1; i<=N; i++) {
        int vertical = i;
        for(int j=1; j<=H; j++) {
            if(ladder[j][vertical]) vertical++;
            else if(ladder[j][vertical-1]) vertical--;
        }
        if(i != vertical) return false;
    }
    return true;
}

void dfs(int y, int x, int depth) {
    if(depth >= answer || depth == MAX_DEPTH) return;

    if(isClear()) {
        answer = depth;
        return;
    }
    
    for(int i=y; i<=H; i++) {
        for(int j=1; j<=N; j++) {
            if(ladder[i][j] || ladder[i][j-1]) continue;
            ladder[i][j] = 1;
            dfs(i, j, depth + 1);
            ladder[i][j] = 0;
        }
    }
}

int main() {
    cin >> N >> M >> H;
    ladder.resize(H + 2, vector<int>(N + 2));

    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = 1;
    }

    dfs(1, 1, 0);
    answer = answer == MAX_DEPTH ? -1 : answer;
    cout << answer;
}