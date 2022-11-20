#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, start;
int adjacent_matrix[1001][1001] = {false,};

// stack
vector<int> dfs() {
    int cur;
    vector<bool> visit(N+1, false);
    vector<int> result;
    vector<int> v;
    v.push_back(start);
    result.push_back(start);
    visit[start] = true;

    while (!v.empty()) {
        cur = v.back();
        v.pop_back();

        for (int i = 1; i <= N; i++) {
            if (adjacent_matrix[cur][i] && !visit[i]) {
                // stack push 순서에 유의
                v.push_back(cur);
                v.push_back(i);
                visit[i] = true;
                result.push_back(i);
                break;
            }
        }
    }
    return result;
}

vector<int> bfs() {
    int cur;
    vector<bool> visit(N+1, false);
    vector<int> result;
    queue<int> q;
    q.push(start);
    visit[start] = true;

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        result.push_back(cur);

        for (int i = 1; i <= N; i++) {
            if (adjacent_matrix[cur][i] && !visit[i]) {
                q.push(i);
                visit[i] = true;
            }
        }
    }
    return result;
}

int main() {
    cin >> N >> M >> start;

    int from, to;
    for (int i = 0; i < M; i++) {
        cin >> from >> to;
        adjacent_matrix[from][to] = true;
        adjacent_matrix[to][from] = true;
    }

    vector<int> dfs_result = dfs();
    vector<int> bfs_result = bfs();

    for (auto x : dfs_result) {
        cout << x << " ";
    }
    cout << endl;

    for (auto x : bfs_result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}