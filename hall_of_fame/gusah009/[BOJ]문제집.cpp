#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M;
int isEasySolve[32001] = {0};
bool isSolved[32001] = {0};
vector<int> edge[32001];
int answer[32001] = {0};

void input()
{
  cin >> N >> M;
  FOR(m, M) {
    int A, B;
    cin >> A >> B;
    edge[A - 1].push_back(B - 1);
    isEasySolve[B - 1]++;
  }
}

void solve()
{
  priority_queue<int, vector<int>, greater<int> > pq;
  int answer_index = 0;

  FOR(n, N) {
    if (!isEasySolve[n]) {
      if (!isSolved[n]) {
        isSolved[n] = true;
        answer[answer_index++] = n;
        FOR(i, edge[n].size()) {
          isEasySolve[edge[n][i]]--;
          if (isEasySolve[edge[n][i]] == 0) {
            pq.push(edge[n][i]);
          }
        }
      }
    }
    while(!pq.empty() && pq.top() <= n) {
      int next = pq.top();
      pq.pop();
      if (!isSolved[next]) {
        isSolved[next] = true;
        answer[answer_index++] = next;
        FOR(i, edge[next].size()) {
          isEasySolve[edge[next][i]]--;
          if (isEasySolve[edge[next][i]] == 0) {
            pq.push(edge[next][i]);
          }
        }
      }
    }
  }
}

void print()
{
  FOR(n, N) {
    cout << answer[n] + 1 << ' ';
  }
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