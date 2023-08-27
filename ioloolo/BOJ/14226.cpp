#include <bits/stdc++.h>

using namespace std;

int S;
int visited[1001][1001];
int minimum = 2e9;

void bfs() {
    queue<pair<int, int>> q;
    q.emplace(1, 0);

    visited[1][0] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int clip = q.front().second;

        int time = visited[x][clip];

        q.pop();

        if (x == S) {
            minimum = min(minimum, time);
            continue;
        }

        if (visited[x][x] == -1) {
            visited[x][x] = time + 1;
            q.emplace(x, x);
        }

        if (x+clip <=S && visited[x+clip][clip] == -1) {
            visited[x + clip][clip] = time + 1;
            q.emplace(x+clip, clip);
        }

        if (x-1 >= 0 && visited[x-1][clip] == -1) {
            visited[x - 1][clip] = time + 1;
            q.emplace(x-1, clip);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> S;

    for (auto & i : visited)
        for (int & j : i)
            j = -1;

    bfs();

    cout << minimum;
}
