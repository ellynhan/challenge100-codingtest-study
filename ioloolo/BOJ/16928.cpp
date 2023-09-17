#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[102];
bool visited[102];

void bfs(int x, int c){
    queue<pair<int, int>> q;
    q.emplace(x, c);

    while (!q.empty()) {
        auto [loc, cnt] = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++){
            int next = loc + i;

            if (next == 100) {
                cout << cnt+1;
                return;
            } else if(next < 100) {
                while (arr[next] != 0) {
                    next = arr[next];
                }

                if (!visited[next]) {
                    visited[next] = true;
                    q.emplace(next, cnt + 1);
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N+M; i++){
        int a, b;
        cin >> a >> b;
        arr[a] = b;
    }

    bfs(1, 0);

    return 0;
}

