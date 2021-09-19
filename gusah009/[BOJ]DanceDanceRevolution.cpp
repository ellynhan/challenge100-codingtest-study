#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321
#define MAX 5

int arr[100001] = {0};
int N = -1;
int DP[MAX][MAX] = {0};

int answer = INF;

void input()
{
  int inp = -1;
  while(inp != 0) {
    cin >> inp;
    N++;
    arr[N] = inp;
  }
}

void solve()
{
  FOR(i, MAX) {
    FOR(j, MAX) {
      DP[i][j] = INF;
    }
  }
  DP[arr[0]][0] = 2;
  DP[0][arr[0]] = 2;

  for (int n = 1; n < N; n++) {
    int nextStep = arr[n];
    int nextDP[MAX][MAX];
    FOR(i, MAX) {
      FOR(j, MAX) {
        nextDP[i][j] = INF;
      }
    }

    FOR(i, MAX) {
      FOR(j, MAX) {
        if (DP[i][j] != INF) {
          int nextForce;
          if (i == 0) {
            nextForce = 2;
          } else if (i == nextStep) {
            nextForce = 1;
          } else if (i % 2 != nextStep % 2) {
            nextForce = 3;
          } else if (i % 2 == nextStep % 2) {
            nextForce = 4;
          }
          nextDP[nextStep][j] = min(nextDP[nextStep][j], DP[i][j] + nextForce);

          
          if (j == 0) {
            nextForce = 2;
          } else if (j == nextStep) {
            nextForce = 1;
          } else if (j % 2 != nextStep % 2) {
            nextForce = 3;
          } else if (j % 2 == nextStep % 2) {
            nextForce = 4;
          }
          nextDP[i][nextStep] = min(nextDP[i][nextStep], DP[i][j] + nextForce);
        }
      }
    }

    FOR(i, MAX) {
      FOR(j, MAX) {
        DP[i][j] = nextDP[i][j];
      }
    }
  }
  FOR(i, MAX) {
    FOR(j, MAX) {
      answer = min(DP[i][j], answer);
    }
  }
}

void print()
{
  cout << answer;
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