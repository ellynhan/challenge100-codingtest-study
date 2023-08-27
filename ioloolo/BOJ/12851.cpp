#include <bits/stdc++.h>

#define MAX 100001

using namespace std;

int n, k;
int visited[MAX];
int answer[2];

void bfs(int a, int b) {
    static bool first = true;

    queue<pair<int, int>> q;

    q.emplace(a, b);
    visited[a] = true;

    while (!q.empty()) {
        auto [x, cnt] = q.front();
        q.pop();

        visited[x] = true;

        if (!first && answer[0] == cnt && x == k) {
            answer[1]++;
        }

        if (first && x == k) {
            answer[0] = cnt;
            first = false;
            answer[1]++;
        }

        if (x+1 < 100001 && x+1 >= 0 && !visited[x+1]) {
            q.emplace(x + 1, cnt + 1);
        }

        if (x-1 < 100001 && x-1 >= 0 && !visited[x-1]) {
            q.emplace(x - 1, cnt + 1);
        }

        if (x*2 < 100001 && x*2 >= 0 && !visited[x*2]) {
            q.emplace(x * 2, cnt + 1);
        }
    }
}

int main(){
    cin >> n >> k;

    bfs(n, 0);

    cout << answer[0] << '\n' << answer[1];

    return 0;
}

