#include <iostream>
using namespace std;

int simple[302][302];
int vv[303][303];
int N, M;

void init()
{
  cin >> N >> M;
  int i, j;
  for (i = 0; i < N + 1; i++)
  {
    for (j = 0; j < M + 1; j++)
    {
      if (i == 0 || j == 0)
        simple[i][j] = 0;
      else
      {
        cin >> simple[i][j];
      }
    }
  }
}

void makeVV()
{
  int i, j;
  for (i = 0; i < N + 1; i++)
  {
    for (j = 0; j < M + 1; j++)
    {
      if (i == 0 || j == 0)
        vv[i][j] = 0;
      else
        vv[i][j] = simple[i][j] + vv[i - 1][j] + vv[i][j - 1] - vv[i - 1][j - 1];
    }
  }
}

void check()
{
  int i, j, cnt = 0, ii, jj;
  int tmp;
  for (i = 1; i < N + 1; i++)
  {
    for (j = 1; j < M + 1; j++)
    {
      for (ii = i - 1; ii >= 0; ii--)
      {
        for (jj = j - 1; jj >= 0; jj--)
        {
          tmp = vv[i][j] - vv[i][jj] - vv[ii][j] + vv[ii][jj];
          if (tmp == 10)
            cnt++;
          else if (tmp > 10)
            break;
        }
      }
    }
  }
  cout << cnt;
}

void printS()
{
  int i, j;
  for (i = 0; i < N + 2; i++)
  {
    for (j = 0; j < M + 2; j++)
    {
      cout << simple[i][j] << " ";
    }
    cout << "\n";
  }
}

void printVV()
{
  int i, j;
  for (i = 0; i < N + 2; i++)
  {
    for (j = 0; j < M + 2; j++)
    {
      cout << vv[i][j] << " ";
    }
    cout << "\n";
  }
}

int main()
{
  init();
  makeVV();

  check();
}
