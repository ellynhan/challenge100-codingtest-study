#include <iostream>
#include <queue>

using namespace std;
using ll=long long;

int f, s, g, u, d;
ll fl[1000001];

queue<int> Q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> f >> s >> g >> u >> d;

  // init
  for (int i = 1; i<= f; i++) {
    fl[i] = -1;
  }
  fl[s] = 0;
  Q.push(s);

  while (!Q.empty()) {
    int cur = Q.front(); Q.pop();

    if (cur == g) {
      break;
    }

    // cout << "\ncur: " << cur << endl;
    int up = cur + u;
    int down = cur - d;
    // cout << "up: " << up << endl;
    // cout << "down: " << down << endl;

    if (!(up > f || fl[up] >= 0)) {
      fl[up] = fl[cur] + 1;
      Q.push(up);
    }

    if (!(down < 1 || fl[down] >= 0)) {
      fl[down] = fl[cur] + 1;
      Q.push(down);
    }
  }

  if (fl[g] != -1) cout << fl[g] << '\n';
  else
    cout << "use the stairs" << '\n';



  return 0;
}
