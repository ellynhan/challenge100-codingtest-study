#include <bits/stdc++.h>

using namespace std;

int N, result=0, houses[25][25];
string row;
priority_queue<int, vector<int>, greater<int>> answer;
queue<pair<int, int>> q;


void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> row;
        for(int j=0; j<N; j++) {
            houses[i][j] = row[j] - '0';
        }
    }
}

// 1. dfs
void dfs(int m, int n) {
    houses[m][n] = 0;
    result+=1;

    if(m>0&&houses[m-1][n]==1) dfs(m-1, n); // 왼
    if(m+1<N&&houses[m+1][n]==1) dfs(m+1, n); // 오
    if(n>0&&houses[m][n-1]==1) dfs(m, n-1); //위
    if(n+1<N&&houses[m][n+1]==1) dfs(m, n+1); //아래
}

// 2. bfs
void bfs(int m, int n) {
    houses[m][n] = 0;
    result+=1;

    if(m>0&&houses[m-1][n]==1) { q.push({m-1, n}); houses[m-1][n]=0; } // 왼
    if(m+1<N&&houses[m+1][n]==1) { q.push({m+1, n}); houses[m+1][n]=0; } // 오
    if(n>0&&houses[m][n-1]==1) { q.push({m, n-1}); houses[m][n-1]=0; }//위
    if(n+1<N&&houses[m][n+1]==1) { q.push({m, n+1}); houses[m][n+1]=0; }//아래

    if(!q.empty()) {
        int row = q.front().first;
        int column = q.front().second;
        q.pop();
        bfs(row, column);
    }
}

void solve() {
    for(int m=0; m<N; m++) {
        for(int n=0; n<N; n++) {
            result = 0;
            if(houses[m][n]==1) {
                dfs(m, n);
                answer.push(result);
            }
        }
    }
}

void output() {
    cout << answer.size() << endl;
    while(!answer.empty()) {
        cout << answer.top() << endl;
        answer.pop();
    }
}

int main() {
    input();
    solve();
    output();
    return 0;
}
