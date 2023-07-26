#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

int N, M;
vector<int> friends[101];
int kevinNums[101][101];
pair<int, int> answer = {INF, -1};

void input()
{
  cin >> N >> M;
  int A, B;
  FOR(m, M) {
    cin >> A >> B;
    friends[A].push_back(B);
    friends[B].push_back(A);
  }

  FOR(i, 101) {
    FOR(j, 101) {
      kevinNums[i][j] = INF;
    }
  }
}

void DFS(int start, int nextFriend, int kevinNum)
{
  if (kevinNums[start][nextFriend] <= kevinNum) return;
  kevinNums[start][nextFriend] = kevinNum;

  FOR(i, friends[nextFriend].size()) {
    DFS(start, friends[nextFriend][i], kevinNum + 1);
  }
  return;
}

void solve()
{
  for (int n = 1; n <= N; n++) {
    int start = n;
    DFS(start, start, 0);
  }

  for (int i = 1; i <= N; i++) {
    int sum = 0;
    for (int j = 1; j <= N; j++) {
      sum += kevinNums[i][j];
    }

    if (answer.first > sum) answer = {sum, i};
  }
}

void print()
{
  cout << answer.second << '\n';
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