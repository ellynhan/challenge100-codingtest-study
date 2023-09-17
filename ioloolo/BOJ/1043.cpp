#include <bits/stdc++.h>

using namespace std;

int N, M, X;
int parent[53];
int arr[53][53];
int arr_size[53];

int find_parent(int x) {
    if (x == parent[x]) return parent[x];
    return parent[x] = find_parent(parent[x]);
}

void union_parent(int x, int y) {
    int px = find_parent(parent[x]);
    int py = find_parent(parent[y]);

    parent[max(px, py)] = parent[min(px, py)];
}

int main() {
    cin >> N >> M >> X;

    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < X; i++) {
        int a;
        cin >> a;
        parent[a] = 0;
    }

    for (int i = 0; i < M; i++) {
        int a, b, n;

        cin >> n >> a;

        arr[i][0] = a;
        arr_size[i] = n;

        for (int j = 1; j < n; j++) {
            cin >> b;
            arr[i][j] = b;
            union_parent(a, b);
        }
    }

    int answer = M;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < arr_size[i]; j++) {
            if (find_parent(parent[arr[i][j]]) == 0) {
                answer--;
                break;
            }
        }
    }

    cout << answer;

    return 0;
}

