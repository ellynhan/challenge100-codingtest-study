#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

string start, target;
string words[51];
bool isUse[51] = {0};
int n = 0;
int answer = INF;

void input()
{
  cin >> start >> target;
  while(cin >> words[n]) {
    n++;
  }
}

void DFS(string str, int depth)
{

  int i = 0;
  for(; i < n; i++) {
    if (!isUse[i]) {
      if (str == words[i]) {
        break;
      }
    }
  }

  if (i == n) return;
  
  if (str == target) {
    answer = min(answer, depth);
    return;
  }

  isUse[i] = true;
  
  FOR(s, str.size()) {
    char tmp = str[s];
    FOR(j, 26) {
      if (str[s] != 'a' + j) {
        str[s] = 'a' + j;
        DFS(str, depth + 1);
        str[s] = tmp;
      }
    }
  }
  
  isUse[i] = false;
}

void solve()
{
  FOR(i, start.size()) {
    char tmp = start[i];
    FOR(j, 26) {
      if (start[i] != 'a' + j) {
        start[i] = 'a' + j;
        DFS(start, 1);
        start[i] = tmp;
      }
    }
  }
}

void print()
{
  cout << (answer == INF ? 0 : answer);
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