#include <iostream>
#include <queue>
#include <map>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX_L 100
#define MAX_N 500000
#define BUCKET_COUNT 5

pair<string, int> fragment[MAX_N];
pair<string, int>* genome[2][MAX_N];
int N, K, maxLeng = 0, startL = 0;
queue<pair<string, int>*> bucket[BUCKET_COUNT + 1];
queue<pair<string, int>*> bucket2[BUCKET_COUNT * BUCKET_COUNT * BUCKET_COUNT];
char type[BUCKET_COUNT + 1] = {'\0', 'a', 'c', 'g', 'n', 't'};
bool flag = 0;

void input()
{
  cin >> K;
  int n = 0;
  while (cin >> fragment[n].first) {
    genome[flag][n] = fragment + n;
    fragment[n].second = n;
    maxLeng = max(maxLeng, (int)fragment[n].first.length());
    n++;
  }
  N = n;

  FOR(n, N) {
    genome[flag][n]->first.resize(maxLeng);
  }

  while(startL != maxLeng - 2) {
    bool f = true;
    FOR(n, N) {
      if (genome[flag][0]->first[startL] != genome[flag][n]->first[startL]) {
        f = false;
        break;
      }
    }
    if (!f) break;
    else {
      startL++;
    }
  }
}

void setBucket(int n) {
  FOR(i, BUCKET_COUNT + 1) {
    FOR(j, BUCKET_COUNT + 1) {
      FOR(k, BUCKET_COUNT + 1) {
        if (genome[flag][n]->first[startL] == type[i + 1] && genome[flag][n]->first[startL + 1] == type[j + 1] && genome[flag][n]->first[startL + 2] == type[k + 1]) {
          bucket2[i * 25 + j * 5 + k].push(genome[flag][n]);
          return;
        }
      }
    }
  }
}

void solve()
{
  FOR(n, N) {
    setBucket(n);
  }
  int n = 0;
  FOR (i, BUCKET_COUNT * BUCKET_COUNT * BUCKET_COUNT) {
    if (bucket2[i].size() + n <= K - 2) {
      K -= bucket2[i].size();
      N -= bucket2[i].size();
      while (!bucket2[i].empty()) {
        bucket2[i].pop();
      }
      continue;
    }
    if (n > K) {
      N -= bucket2[i].size();
      while (!bucket2[i].empty()) {
        bucket2[i].pop();
      }
      continue;
    }
    while (!bucket2[i].empty()) {
      pair<string, int>* str = bucket2[i].front();
      bucket2[i].pop();

      genome[!flag][n] = str;
      n++;
    }
  }
  flag = !flag;
  for (int l = maxLeng - 1; l >= startL; l--) {
    FOR(n, N) {
      FOR(i, BUCKET_COUNT + 1) {
        if (genome[flag][n]->first[l] == type[i]) {
          bucket[i].push(genome[flag][n]);
          break;
        }
      }
    }
    int n = 0;
    FOR (i, BUCKET_COUNT + 1) {
      while (!bucket[i].empty()) {
        pair<string, int>* str = bucket[i].front();
        bucket[i].pop();

        genome[!flag][n] = str;
        n++;
      }
    }
    flag = !flag;
  }
}

void print()
{
  cout << genome[flag][K - 2]->second + 1 << '\n';
  cout << genome[flag][K - 1]->second + 1 << '\n';
  cout << genome[flag][K]->second + 1 << '\n';
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