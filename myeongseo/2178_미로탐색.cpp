#include <bits/stdc++.h>

using namespace std;

int N, M, k, l, o, answer = 10000;
string way;
bool maze[101][101];
queue<tuple<int, int, int>> q;

void input() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> way;
        for(int j=0; j<M; j++) {
            maze[i][j] = way[j]-'0';
        }
    }
}

void bfsMove(int n, int m, int result) {
    maze[n][m]=false;

    if(n==N-1&&m==M-1) {
        if(result < answer) answer = result;
    }


    if(n>0&&maze[n-1][m]==1) {q.push({n-1,m, result}); maze[n-1][m]=false;} //up
    if(m+1<M&&maze[n][m+1]==1) {q.push({n,m+1, result}); maze[n][m+1]=false;} //right
    if(n+1<N&&maze[n+1][m]==1) {q.push({n+1,m,result}); maze[n+1][m]=false;} //down
    if(m>0&&maze[n][m-1]==1) {q.push({n,m-1, result}); maze[n][m-1]=false;} //left

    if(!q.empty()) {
        k=get<0>(q.front()); l=get<1>(q.front()); o=get<2>(q.front());
        q.pop();
        bfsMove(k, l, o+1);
    }
}

int main() {
    input();
    bfsMove(0, 0, 1);

    cout << answer << endl;
    return 0;
}
