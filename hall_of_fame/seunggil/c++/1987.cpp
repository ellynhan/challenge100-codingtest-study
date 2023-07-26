#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <cstring>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = { 0, 1, 0,-1};

bool alphabet[26] = {};
int n, m;
vector<vector<bool>> visitable;

bool isValid(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return visitable[x][y];
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    memset(alphabet, true, sizeof(alphabet));
    visitable = vector<vector<bool>>(n, vector<bool>(m, true));
    vector<vector<char>> inputData(n, vector<char>(m));

    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> inputData[i][j];

    //for (int i = 0; i < n; i++) {
    //    for (int j = 0; j < m; j++) {
    //        cout << inputData[i][j] << ' ';
    //    }cout << endl;
    //}

    // 현 위치
    int x = 0, y = 0;
    int length = 1;
    int ans = 1;

    stack<pair<int, bool>> dfs;

    alphabet[inputData[0][0] - 65] = false;
    visitable[0][0] = false;
    // 0,0에서는 오른쪽, 아래만 이동가능.
    for (int i = 0; i < 4; i++) {
        int x2 = 0 + dx[i];
        int y2 = 0 + dy[i];
        if (isValid(x2,y2) && alphabet[inputData[x2][y2] - 65]) {
            // 갔던거 돌아가기
            dfs.emplace((i + 2) % 4, false);
            dfs.emplace(i, true);
        }
    }
   

    while (dfs.size()) {
        //cout << x << ' ' << y << '\n';
        int dir = dfs.top().first;
        bool go = dfs.top().second;

        dfs.pop();

        if (!go) {
            length--;
            visitable[x][y] = true;
            alphabet[inputData[x][y] - 65] = true;
            x += dx[dir];
            y += dy[dir];

            continue;
        }

        length++;
        x += dx[dir];
        y += dy[dir];
        visitable[x][y] = false;
        alphabet[inputData[x][y] - 65] = false;
        ans = max(ans, length);

        for (int i = 0; i < 4; i++) {
            int x2 = x + dx[i];
            int y2 = y + dy[i];
            if (isValid(x2, y2) && alphabet[inputData[x2][y2] - 65]) {
                dfs.emplace((i + 2) % 4, false);
                dfs.emplace(i, true);
            }
        }
    }

    cout << ans;
    return 0;
}