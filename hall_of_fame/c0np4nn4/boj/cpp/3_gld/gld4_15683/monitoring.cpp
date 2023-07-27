#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int n, m;
int map[9][9];

int watch[9][9];

int ans = 9999;

int blind_spot;

// x, y, type
vector<tuple<int, int, int>> camera_pos;
bool issue[9];


void left_on(int x, int y) {
  if (y == 0) {
    return;
  } else {
    for (int i = y - 1; i >= 0; i--) {
      if (map[x][i] == 6) return;
      if (map[x][i] == 0 && watch[x][i] == 0) {
        map[x][i] = '#';
        blind_spot -= 1;
      }
      watch[x][i] += 1;
    }
  }
}

void left_off(int x, int y) {
  if (y == 0) {
    return;
  } else {
    for (int i = y - 1; i >= 0; i--) {
      if (map[x][i] == 6) return;
      if (map[x][i] == '#' && watch[x][i] == 1) {
        map[x][i] = 0;
        blind_spot += 1;
      }
      watch[x][i] -= 1;
    }
  }
}

// [1] up
void up_on(int x, int y) {
  if (x == 0) {
    return;
  } else {
    for (int i = x - 1; i >= 0; i--) {
      if (map[i][y] == 6) return;
      if (map[i][y] == 0 && watch[i][y] == 0) {
        map[i][y] = '#';
        blind_spot -= 1;
      }
      watch[i][y] += 1;
    }
  }
}

void up_off(int x, int y) {
  if (x == 0) {
    return;
  } else {
    for (int i = x - 1; i >= 0; i--) {
      if (map[i][y] == 6) return;
      if (map[i][y] == '#' && watch[i][y] == 1) {
        map[i][y] = 0;
        blind_spot += 1;
      }
      watch[i][y] -= 1;
    }
  }
}

// [1] right
void right_on(int x, int y) {
  if (y == m - 1) {
    return;
  } else {
    for (int i = y + 1; i < m; i++) {
      if (map[x][i] == 6) return;
      if (map[x][i] == 0 && watch[x][i] == 0) {
        map[x][i] = '#';
        blind_spot -= 1;
      }
      watch[x][i] += 1;
    }
  }
}
void right_off(int x, int y) {
  if (y == m - 1) {
    return;
  } else {
    for (int i = y + 1; i < m; i++) {
      if (map[x][i] == 6) return;
      if (map[x][i] == '#' && watch[x][i] == 1) {
        map[x][i] = 0;
        blind_spot += 1;
      }
      watch[x][i] -= 1;
    }
  }
}

// [1] down
void down_on(int x, int y) {
  if (x == n - 1) {
    return;
  } else {
    for (int i = x + 1; i < n; i++) {
      if (map[i][y] == 6) return;
      if (map[i][y] == 0 && watch[i][y] == 0) {
        map[i][y] = '#';
        blind_spot -= 1;
      }
      watch[i][y] += 1;
    }
  }
}
void down_off(int x, int y) {
  if (x == n - 1) {
    return;
  } else {
    for (int i = x + 1; i < n; i++) {
      if (map[i][y] == 6) return;
      if (map[i][y] == '#' && watch[i][y] == 1) {
        map[i][y] = 0;
        blind_spot += 1;
      }
      watch[i][y] -= 1;
    }
  }
}

void print_map() {
  cout << "=-=-=-= map =-=-=-=" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] == 35) {
        cout << '#' << ' ';
      } else {
        cout << map[i][j] << ' ';
      }
    }
    cout << endl;
  }
}


void func(int k) {
  // print_map();
  if (k == camera_pos.size()) {
    if (ans > blind_spot) {
      ans = blind_spot;
      // cout << "blind_spot: " << blind_spot << endl;
      // cout << "done\n" << endl;
      return;
    }
  }

  for (int i = 0; i < camera_pos.size(); i++) {
    if (issue[i] == false && i <= k) {
      int x, y, cam_type;
      tie(x, y, cam_type) = camera_pos[i];

      if (cam_type == 1) {
        issue[i] = true;
        left_on(x, y);
        func(k + 1);
        left_off(x, y);
        issue[i] = false;

        issue[i] = true;
        up_on(x, y);
        func(k + 1);
        up_off(x, y);
        issue[i] = false;

        issue[i] = true;
        right_on(x, y);
        func(k + 1);
        right_off(x, y);
        issue[i] = false;


        issue[i] = true;
        down_on(x, y);
        func(k + 1);
        down_off(x, y);
        issue[i] = false;
      }

      if (cam_type == 2) {
        issue[i] = true;
        left_on(x, y);
        right_on(x, y);
        func(k + 1);
        left_off(x, y);
        right_off(x, y);
        issue[i] = false;

        issue[i] = true;
        up_on(x, y);
        down_on(x, y);
        func(k + 1);
        up_off(x, y);
        down_off(x, y);
        issue[i] = false;
      }

      if (cam_type == 3) {
        issue[i] = true;
        left_on(x, y);
        up_on(x, y);
        func(k + 1);
        left_off(x, y);
        up_off(x, y);
        issue[i] = false;

        issue[i] = true;
        up_on(x, y);
        right_on(x, y);
        func(k + 1);
        up_off(x, y);
        right_off(x, y);
        issue[i] = false;

        issue[i] = true;
        right_on(x, y);
        down_on(x, y);
        func(k + 1);
        right_off(x, y);
        down_off(x, y);
        issue[i] = false;

        issue[i] = true;
        down_on(x, y);
        left_on(x, y);
        func(k + 1);
        down_off(x, y);
        left_off(x, y);
        issue[i] = false;
      }

      if (cam_type == 4) {
        issue[i] = true;
        left_on(x, y);
        up_on(x, y);
        right_on(x, y);

        func(k + 1);

        left_off(x, y);
        up_off(x, y);
        right_off(x, y);
        issue[i] = false;

        issue[i] = true;
        up_on(x, y);
        right_on(x, y);
        down_on(x, y);

        func(k + 1);

        up_off(x, y);
        right_off(x, y);
        down_off(x, y);
        issue[i] = false;

        issue[i] = true;
        right_on(x, y);
        down_on(x, y);
        left_on(x, y);

        func(k + 1);

        right_off(x, y);
        down_off(x, y);
        left_off(x, y);
        issue[i] = false;

        issue[i] = true;
        down_on(x, y);
        left_on(x, y);
        up_on(x, y);

        func(k + 1);

        down_off(x, y);
        left_off(x, y);
        up_off(x, y);
        issue[i] = false;
      }

      if (cam_type == 5) {
        issue[i] = true;
        left_on(x, y);
        up_on(x, y);
        right_on(x, y);
        down_on(x, y);

        func(k + 1);

        left_off(x, y);
        up_off(x, y);
        right_off(x, y);
        down_off(x, y);
        issue[i] = false;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  blind_spot = n * m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];

      if (map[i][j] != 0) {
        blind_spot -= 1;
      }

      if (map[i][j] > 0 && map[i][j] < 6) {
        camera_pos.push_back({i, j, map[i][j]});
      }
    }
  }

  func(0);

  cout << ans << '\n';

  return 0;
}
