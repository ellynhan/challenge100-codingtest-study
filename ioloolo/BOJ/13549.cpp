#include<bits/stdc++.h>

using namespace std;

int N, K;
int p[100001];
int answer;
queue<int> q;

void bfs() {
    q.push(N);
    p[N] = 0;

    while (!q.empty()) {
        auto n = q.front();
        q.pop();

        if (n == K) {
            answer = p[n];
        }

        if (n*2 < 100001 && p[n*2] > p[n]) {
            p[n*2] = p[n];
            q.push(n*2);
        }

        if (n+1 < 100001 && p[n+1] > p[n] + 1) {
            p[n+1] = p[n] + 1;
            q.push(n+1);
        }

        if (n-1 >= 0 && p[n-1] > p[n] + 1) {
            p[n-1] = p[n] + 1;
            q.push(n-1);
        }
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    for (int & i : p) {
        i = 1e9;
    }

    bfs();

    cout << answer;

    return 0;
}

