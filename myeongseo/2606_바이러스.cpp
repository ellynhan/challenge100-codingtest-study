#include<bits/stdc++.h>

using namespace std;

int N, M, a, b;
int computers[101][101];
queue<int> q;
set<int> victim;

void input() {
    cin >> N;
    cin >> M;
    while(M--) {
        cin >> a >> b;
        computers[a][b] = 1;
        computers[b][a] = 1;
    }
}

void bfs(int i) {
    for(int k=1; k<N+1; k++) {
        if(computers[i][k]==1) {
            victim.insert(k);
            q.push(k);
            computers[i][k]=0; computers[k][i]=0;
        }
    }
    if(!q.empty()) {
        int m = q.front();
        q.pop();
        bfs(m);
    }
}
