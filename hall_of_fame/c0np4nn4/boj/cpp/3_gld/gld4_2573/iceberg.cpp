#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int year;
int n, m;
int curr_map[301][301];
int next_map[301][301];

int vis[301][301];

// The element of Q is the 'height of iceberg'.
queue<pair<int, int>> curr_Q;
queue<pair<int, int>> next_Q;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void print_map() {
  cout << "\n=-=-=-=-=-= map =-=-=-=-=-=" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout <<  curr_map[i][j] << ' ';
    }
    cout << endl;
  }
}

void init_map() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> curr_map[i][j];

      if (curr_map[i][j] > 0) {
        curr_Q.push({i, j});
      }
    }
  }
}

bool oob(int x, int y) {
  return (x < 0 || y < 0 || x >= n || y >= m);
}

void init_vis() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      vis[i][j] = false;
    }
  }
}

void melt() {
  // melt
  while (!curr_Q.empty()) {
    int x, y;
    tie(x, y) = curr_Q.front(); curr_Q.pop();

    next_map[x][y] = curr_map[x][y];

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (oob(nx, ny)) continue;
      if (curr_map[nx][ny] > 0) continue;

      vis[nx][ny] = true;
      next_map[x][y]--;
    }

    if (next_map[x][y] <= 0) {
      next_map[x][y] = 0;
    }

    if (next_map[x][y] > 0) {
      next_Q.push({x, y});
    }
  }

  // update
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      curr_map[i][j] = next_map[i][j];
    }
  }

  // update
  while (!next_Q.empty()) {
    curr_Q.push(next_Q.front()); next_Q.pop();
  }
}


bool is_continue() {
  // 0. solo iceberg
  if (curr_Q.size() == 1) {
    // cout << "solo iceberg" << endl;
    year = 0;
    return false;
  }

  // 1. all melt
  //  - [x] map iterator
  //  - [o] Q check
  if (curr_Q.empty()) {
    // cout << "all melt" << endl;
    year = 0;
    return false;
  }

  // 2. more than 2 icebergs
  //  - BFS
  queue<pair<int, int>> tmp_Q;
  tmp_Q.push(curr_Q.front());

  bool tmp_vis[301][301];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      tmp_vis[i][j] = false;
    }
  }

  int tmp_cnt = 0;
  while (!tmp_Q.empty()) {
    int x, y;
    tie(x, y) = tmp_Q.front(); tmp_Q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (oob(nx, ny)) continue;
      if (tmp_vis[nx][ny]) continue;
      if (curr_map[nx][ny] == 0) continue;

      tmp_cnt++;

      tmp_vis[nx][ny] = true;
      tmp_Q.push({nx, ny});
    }
  }

  if (curr_Q.size() != tmp_cnt) {
    return false;
  }

  return true;
}



int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  init_map();

  while (is_continue()) {
    init_vis();
    melt();
    year++;

    // print_map();
  }

  cout << year << endl;

  return 0;
}
