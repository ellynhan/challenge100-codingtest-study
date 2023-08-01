#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1001
#define f first
#define s second

string inp;
// char, length, range [i:j]
pair<pair<char, int>, pair<int, int> > DP[MAX][MAX], answer;

void input()
{
  cin >> inp;
}

void getPalin(int j, int i, string& palin)
{
  if (DP[j][i].s.f == -1) {
    palin += DP[j][i].f.f;
    return;
  }

  if (DP[j][i].f.f != '-') {
    palin += DP[j][i].f.f;
  } 

  getPalin(DP[j][i].s.f, DP[j][i].s.s, palin);
}

pair<int, int> getPalinRange(int j, int i) {

  if (DP[j][i].f.f != '-') {
    return {j, i};
  } 

  return getPalinRange(DP[j][i].s.f, DP[j][i].s.s);
}

void solve()
{
  DP[0][0] = {{inp[0], 1}, {-1, -1}};
  for(int i = 1; i < inp.size(); i++) {
    for (int j = i; j >= 0; j--) {
      if (inp[j] == inp[i]) {
        if (j == i) {
          DP[j][i] = {{inp[i], 1}, {-1, -1}};
        } else if (j == i - 1) {
          DP[j][i] = {{inp[i], 2}, {-1, -1}};
        } else {
          DP[j][i] = {{inp[i], DP[j+1][i-1].f.s + 2}, {j+1, i-1}};
        }
      } else {
        if (j == i - 1) {
          char fastChar = inp[j] < inp[i] ? inp[j] : inp[i];
          DP[j][i] = {{fastChar , 1}, {-1, -1}};
        } else {
          int maxSize = max(DP[j+1][i].f.s, DP[j][i-1].f.s);
          if (maxSize <= 1) {
            char fastChar = *min_element(&inp[0] + j, &inp[0] + i + 1);
            DP[j][i] = {{fastChar, 1}, {-1, -1}};
          } else {
            if (DP[j+1][i].f.s > DP[j][i-1].f.s) {
              DP[j][i] = {{'-', DP[j+1][i].f.s}, getPalinRange(j+1, i)};
            } else if (DP[j+1][i].f.s < DP[j][i-1].f.s) {
              DP[j][i] = {{'-', DP[j][i-1].f.s}, getPalinRange(j, i-1)};
            } else {
              string palin1 = "", palin2 = "";
              getPalin(j+1, i, palin1);
              getPalin(j, i-1, palin2);
              int a = palin1 < palin2 ? j + 1 : j;
              int b = palin1 < palin2 ? i : i - 1;
              DP[j][i] = {{'-', DP[j+1][i].f.s}, getPalinRange(a, b)};
            }
          }
        }
      }
    }
  }
}

void print()
{
  string answer = "", tmp = "";
  getPalin(0, inp.size() - 1, answer);
  tmp = answer.substr(0, answer.size() - (DP[0][inp.size()-1].f.s % 2));
  reverse(tmp.begin(), tmp.end());
  cout << answer << tmp << '\n';
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  print();
}