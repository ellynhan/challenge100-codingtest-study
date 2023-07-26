#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)
#define MAX 20
#define KOREAN_BYTE 2
#define K 2

int N;
set<string> S[MAX];
pair<pair<int, int>, double> answer = {{-1, -1}, -1};

void input()
{
  cin >> N;

  string inp;
  FOR(n, N)
  {
    string tmp;
    while (true)
    {
      cin >> inp;
      if (inp == "$")
        break;
      FOR(i, inp.size())
      {
        if (inp[i] >= 0)
        {
          inp.erase(i, 1);
          i--;
        }
      }
      tmp += inp;
    }

    for (int i = 0; i < tmp.size() - KOREAN_BYTE; i += K)
    {
      S[n].insert(tmp.substr(i, KOREAN_BYTE * K));
    }
  }
}

void solve()
{
  FOR(i, N)
  {
    for (int j = i + 1; j < N; j++)
    {
      vector<string> buff(S[i].size() + S[j].size());
      auto it1 = set_intersection(S[i].begin(), S[i].end(),
                                  S[j].begin(), S[j].end(),
                                  buff.begin());
      double kInter = it1 - buff.begin();
      
      auto it2 = set_union(S[i].begin(), S[i].end(),
                           S[j].begin(), S[j].end(),
                           buff.begin());
      double kUnion = it2 - buff.begin();

      if (answer.second < kInter / kUnion) {
        answer.first = {i + 1, j + 1};
        answer.second = kInter / kUnion;
      }
    }
  }
}

void print()
{
  cout << answer.first.first << ' ' << answer.first.second << '\n';
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