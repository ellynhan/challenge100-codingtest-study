#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 20

int N;
string S[MAX];
string T[MAX];
queue<bool> answer;

void Input()
{
  cin >> N;
  FOR(n, N) {
    cin >> S[n];
    cin >> T[n];
  }
}

bool CreateBackspace(string &s, string &t, int s_cursor, int t_cursor)
{
  while (s_cursor < s.size() &&
          t_cursor < t.size() &&
          s[s_cursor] == t[t_cursor]) {
    s_cursor++;
    t_cursor++;
  }

  if (t_cursor == t.size()) {
    if ((s.size() - s_cursor) % 2 == 1) return false;
    else                                return true;
  }
  s_cursor += 2;

  while (s_cursor < s.size()) {
    if (s[s_cursor] == t[t_cursor]) {
      if (CreateBackspace(s, t, s_cursor, t_cursor)) return true;
    }
    s_cursor += 2;
  }
  return false;
}

bool IsPossible(string &s, string &t)
{
  int s_len = s.size();
  int t_len = t.size();
  int s_cursor = 0;
  int t_cursor = 0;
  if (s_len % 2 != t_len % 2) s_cursor++;
  while (s_cursor < s_len) {
    if (s[s_cursor] == t[t_cursor]) {
      if (CreateBackspace(s, t, s_cursor, t_cursor)) return true;
    }
    s_cursor++;
  }
  return false;
  
}

void Solve()
{
  FOR(n, N) {
    string &s = S[n];
    string &t = T[n];
    if (s.length() < t.length()) {
      answer.push(false);
      continue;
    }
    answer.push(IsPossible(s, t));
  }
}

void Print()
{
  while(!answer.empty()) {
    cout << (answer.front() ? "YES" : "NO") << '\n';
    answer.pop();
  }
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  Input();
  Solve();
  Print();
}