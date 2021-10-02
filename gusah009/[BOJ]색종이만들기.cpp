#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 128
#define CUT 2

int N;
int board[MAX][MAX] = {0};
int paperZero = 0, paperOne = 0;

void input()
{
  cin >> N;
  FOR(i, N) {
    FOR(j, N) {
      cin >> board[i][j];
    }
  }
}

int paper(int a, int b, int size)
{
  if (size == 0) return board[a][b];

  vector<int> result;
  FOR(i, CUT) {
    FOR(j, CUT) {
      result.push_back(paper(a + i * size, b + j * size, size / 2));
    }
  }
  
  bool flag = true;
  FOR(i, CUT * CUT - 1) {
    if (result[i] != result[i + 1]) flag = false;
  }
  if (flag) return result[0];
  else {
    FOR(i, CUT * CUT) {
      if (result[i] == 0) {
        paperZero++;
      } else if (result[i] == 1) {
        paperOne++;
      }
    }
    return 2;
  }
}

void solve()
{
  int flag = paper(0, 0, N / 2);
  if (flag == 0) paperZero++;
  else if (flag == 1) paperOne++;
}

void print()
{
  cout << paperZero << '\n';
  cout << paperOne << '\n';
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