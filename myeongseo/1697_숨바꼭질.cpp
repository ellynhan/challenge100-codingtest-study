#include<bits/stdc++.h>

using namespace std;

int N, K, result, answer;
queue<pair<int, int>> q;
bool visited[100001] = {false};

int bfs(int n, int t) {
    while(n!=K) {
        n = q.front().first;
        t = q.front().second;
        q.pop();

        if(n>0&&n<=100001&&visited[n-1]==0) { q.push({n-1, t+1}); visited[n-1]=1; }
        if(n>=0&&n<100000&&visited[n+1]==0) { q.push({n+1, t+1}); visited[n+1]=1; }
        if(n>0&&2*n<100001&&visited[2*n]==0) { q.push({2*n, t+1}); visited[2*n]=1; }
    }
    return t;
}

int main() {
    cin >> N >> K;
    if(K < N) answer = N - K;
    else {
        q.push({N, 0});
        visited[N] = true;
        answer = bfs(N, 0);
    }
    cout << answer << endl;
    return 0;
}
