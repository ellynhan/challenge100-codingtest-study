#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int map[26][26];

int cnt;
vector<int> house_cnt;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

queue<pair<int, int>> Q;

void print_map() {
  cout << "=-=-=-=-=-= map =-=-=-=-=" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << map[i][j] << ' ';
    }
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);


  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      map[i][j] = -1;
    }
  }

  cin >> n;

  for (int i = 0; i < n; i++) {
    string line;
    cin >> line;
    for (int j = 0; j < n; j++) {
      map[i][j] = static_cast<int>(line[j] - '0');
    }
  }

  for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++) {
      int house = 0;

      if (map[i][j] == 1) {
        // cout << "i: " << i << ", j: " << j << endl;
        Q.push({i, j});

        map[i][j] = 0;

        cnt++;
        house++;
      }

      while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        int x = cur.first;
        int y = cur.second;

        // cout << "\n[_]  x: " << x << ",  y: " << y << endl;
        for (int k = 0; k < 4; k++) {
          int nx = x + dx[k];
          int ny = y + dy[k];
          // cout << "[_] nx: " << nx << ", ny: " << ny << endl;

          if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
          if (map[nx][ny] == 0) continue;

          if (map[nx][ny] == 1) {
            map[nx][ny] = 0;
            house++;

            // cout << "[+] nx:" << nx << ", ny: " << ny << endl;
            Q.push({nx, ny});
          }
        }
      }

      if (house != 0) {
        // print_map();
        house_cnt.push_back(house);
      }
    }
  }

  cout << cnt << endl;
  sort(house_cnt.begin(), house_cnt.end());

  for (auto c: house_cnt) {
    cout << c << ' ';
  }
  cout << endl;

  return 0;
}
