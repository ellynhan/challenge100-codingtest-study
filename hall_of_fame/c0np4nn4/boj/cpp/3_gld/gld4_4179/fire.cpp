#include <iostream>
#include <queue>

using namespace std;

int n, m;
int ans = 9999;

char map[1000][1000];

int walk[1000][1000];
int fire[1000][1000];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

queue<pair<int, int>> J;
queue<pair<int, int>> F;

void print_fire() {
  cout << "\n=-=-=-=-=-=-=-=-= Fire =-=-=-=-=-=-=-=-=" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0 ;j < m; j++) {
      if (fire[i][j] == 9999) cout << "_ ";
      else cout << fire[i][j] << ' ';
    }
    cout << endl;
  }
}

void print_walk() {
  cout << "\n=-=-=-=-=-=-=-=-= Walk =-=-=-=-=-=-=-=-=" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0 ;j < m; j++) {
      if (walk[i][j] == -1) cout << "_ ";
      else cout << walk[i][j] << ' ';
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
      map[i][j] = line[j];
      walk[i][j] = -1;
      fire[i][j] = 9999;

      if (map[i][j] == 'J') {
        if (i==0 || j==0 || i==n-1 || j==m-1) ans = 1; 
        walk[i][j] = 1;
        J.push({i, j});
      }

      if (map[i][j] == 'F') {
        fire[i][j] = 1;
        F.push({i, j});
      }
    }
  }

  // 1. fire
  while (!F.empty()) {
    auto cur = F.front();
    F.pop();

    int x = cur.first;
    int y = cur.second;

    // cout << "[-] x: " << x << ", y: " << y << ", fire[x][y]: " << fire[x][y] << endl;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (map[nx][ny] == '#') continue;
      if (fire[nx][ny] != 9999) continue;

      fire[nx][ny] = fire[x][y] + 1;
      F.push({nx, ny});
    }
  }

  // 2. walk
  while (!J.empty()) {
    auto cur = J.front();
    J.pop();

    int x = cur.first;
    int y = cur.second;

    // cout << "[-] x: " << x << ", y: " << y << ", walk[x][y]: " << walk[x][y] << endl;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (map[nx][ny] == '#') continue;
      if (walk[nx][ny] > 0) continue;

      walk[nx][ny] = walk[x][y] + 1;
      J.push({nx, ny});

      if ((nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1) && walk[nx][ny] != -1) {
        if (fire[nx][ny] > walk[nx][ny])
          if (ans > walk[nx][ny]) 
            ans = walk[nx][ny];
      }
    }
  }

  // print_fire();
  // print_walk();

  if (ans == 9999) {
    cout << "IMPOSSIBLE" << '\n';
  } else {
    cout << ans << '\n';
  }

  return 0;
}
