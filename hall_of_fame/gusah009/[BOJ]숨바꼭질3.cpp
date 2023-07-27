#include <iostream>
#include <queue>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 1987654321

int N, K;
int position[100001];

void input()
{
  FOR(i, 100001) {
    position[i] = MAX;
  }
  cin >> N >> K;
}

void solve()
{
  priority_queue<pair<int, int> > q;
  position[N] = 0;
  q.push({0, N});
  while(true) {
    int cost = -q.top().first;
    int next =  q.top().second;
    q.pop();
    position[next] = cost;
    if (next == K) break;

    int teleport = next * 2;
    while (teleport != 0 && teleport <= 100000) {
      if (position[teleport] > cost) {
        position[teleport] = cost;
        q.push({-cost, teleport});
      } else {
        break;
      }
      teleport *= 2;
    }

    if (next < 100000 && position[next + 1] > cost + 1) q.push({-(cost + 1), next + 1});
    if (next > 0      && position[next - 1] > cost + 1) q.push({-(cost + 1), next - 1});
  }
}

void print()
{
  // FOR(i, 100) {
  // cout << position[i] << ' ';
  // }
  cout << position[K] << '\n';
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  print();
}