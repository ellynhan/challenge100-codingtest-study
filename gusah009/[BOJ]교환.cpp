#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, K;
int answer = -1;
string strN = "";
bool flag[1000001][10] = {0};

void input()
{
  cin >> N >> K;
}

void solve()
{
  strN = to_string(N);
  // cout << strN.size();

  queue<pair<string, int> > Q;
  Q.push({strN, 0});
  while(!Q.empty()) {
    string next = Q.front().first;
    int k = Q.front().second;
    Q.pop();
    if (flag[stoi(next)][k] == true) continue;
    flag[stoi(next)][k] = true;
    // cout << k << ' ' << next << '\n';
    
    if (k == K) {
      answer = max(answer, stoi(next));
      continue;
    }

    FOR(i, strN.size()) {
      for (int j = i + 1; j < strN.size(); j++){
        swap(next[i], next[j]);
        if (next[0] != '0') Q.push({next, k + 1});
        swap(next[i], next[j]);
      }
    }
  }
}

void print()
{
  cout << answer << '\n';
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