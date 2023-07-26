#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
int map[1001][1001];

int walk_0[1001][1001];  // no wall was broken down
int walk_1[1001][1001];  // one wall was broken down

queue<tuple<int, int, bool>> Q;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int ans;

void print_map() {
  cout << "\nMap" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << map[i][j] << ' ';
    }
    cout << endl;
  }
}

void print_walk_0() {
  cout << "\nWalk: broke down 0 wall before" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << walk_0[i][j] << ' ';
    }
    cout << endl;
  }
}

void print_walk_1() {
  cout << "\nWalk: broke down 1 wall before" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << walk_1[i][j] << ' ';
    }
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string line;
    cin >> line;
    for (int j = 0; j < m; j++) {
      map[i][j] = line[j] - '0';
    }
  }

  walk_0[0][0] = 1;
  walk_1[0][0] = 1;

  Q.push({0, 0, false});

  // {x 좌표, y 좌표, 벽을 부순 적이 있는지}

  while (!Q.empty()) {
    auto cur = Q.front(); Q.pop();

    int x, y;
    bool b;
    tie(x, y, b) = cur;

    if (x == n-1 && y == m-1) {
      if (b == true) ans = walk_1[x][y];
      if (b == false) ans = walk_0[x][y];
      break;
    }

    int cur_dist = 0;
    if (b == true) {
      cur_dist = walk_1[x][y] + 1;
    } else {
      cur_dist = walk_0[x][y] + 1;
    }

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      // out of bound check
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

      // 뚫린 길일 때, 이전에 지난 적이 없다면
      if (map[nx][ny] == 0) {
        if (b == true) {
          if (walk_1[nx][ny] == 0) {
            walk_1[nx][ny] = cur_dist;
            Q.push({nx, ny, b});
          }
        }
        if (b == false) {
          if (walk_0[nx][ny] == 0) {
            walk_0[nx][ny] = cur_dist;
            Q.push({nx, ny, b});
          }
        }
      }

      // 막힌 길이면
      // 1. 벽뿌를 한 적이 없고
      // 2. 벽뿌 후 지난 적이 없어야 함
      if (map[nx][ny] == 1 && b == false && walk_1[nx][ny] == 0) {
        walk_1[nx][ny] = cur_dist;
        Q.push({nx, ny, true});
      }
    }
  }

  // print_map();
  // print_walk_0();
  // print_walk_1();
  if (ans == 0) ans = -1;

  cout << ans << '\n';

  return 0;
}
