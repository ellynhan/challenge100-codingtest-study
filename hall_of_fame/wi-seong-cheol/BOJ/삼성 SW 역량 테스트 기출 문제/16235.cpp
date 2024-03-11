//
//  16235.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 3/11/24.
//

/*
 [Input]
 5 2 4
 2 3 2 3 2
 2 3 2 3 2
 2 3 2 3 2
 2 3 2 3 2
 2 3 2 3 2
 2 1 3
 3 2 3
 [Output]
 13
 */
// 시간복잡도: O(n ^ 4)
// 최악시간: 10,000
// 난이도: Gold 3
// Timer: 19m
// Url: https://www.acmicpc.net/problem/16235

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Tree {
    int x, y, age;
};
int n, m, k;
vector<int> tree[11][11];
int board[11][11];
int A[11][11];
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

vector<Tree> spring() {
    vector<Tree> deadTree;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            sort(tree[i][j].begin(), tree[i][j].end());
            for(int k = 0; k < tree[i][j].size(); k++) {
                if(board[i][j] >= tree[i][j][k]) {
                    board[i][j] -= tree[i][j][k];
                    tree[i][j][k]++;
                } else {
                    deadTree.push_back({i, j, tree[i][j][k]});
                    tree[i][j].erase(tree[i][j].begin() + k);
                    k--;
                }
            }
        }
    }

    return deadTree;
}

void summer(const vector<Tree>& deadTree) {
    for(auto t: deadTree) {
        board[t.x][t.y] += t.age / 2;
    }
}

void fall() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < tree[i][j].size(); k++) {
                if(tree[i][j][k] % 5 == 0) {
                    for(int dir = 0; dir < 8; dir++) {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if(OOB(nx, ny)) continue;
                        tree[nx][ny].push_back(1);
                    }
                }
            }
        }
    }
}

void winter() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] += A[i][j];
        }
    }
}

int countTree() {
    int ret = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ret += tree[i][j].size();
        }
    }
    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> A[i][j];
            board[i][j] = 5;
        }
    }
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x - 1][y - 1].push_back(z);
    }

    while(k--) {
        // 봄
        // 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다.
        // 나이가 어린 나무부터 먹고, 나무는 양분을 먹지 못하면 즉시 죽는다.
        vector<Tree> deadTree = spring();

        // 여름
        // 봄에 죽은 나무가 양분으로 변한다.
        // 죽은 나무의 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다.
        summer(deadTree);

        // 가을
        // 나무가 번식한다.
        fall();

        // 겨울
        // 땅에 양분을 추가한다.
        winter();
    }

    int cnt = countTree();
    cout << cnt;

	return 0;
}
