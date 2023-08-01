#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define SIZE 5
#define MAX 1000000

long long N, B;
int power[MAX] = {0};
long long matrix[SIZE][SIZE];
long long answer[SIZE][SIZE];
long long matrixs[MAX][SIZE][SIZE];

long long (*multiple(long long matrix1[][SIZE], long long matrix2[][SIZE]))[SIZE]
{
  static long long tmpMatrix[SIZE][SIZE];
  FOR(i, N) {
    FOR(j, N) {
      tmpMatrix[i][j] = 0;
      FOR(k, N) {
        tmpMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  return tmpMatrix;
}

void input()
{
  FOR(i, SIZE) {
    FOR(j, SIZE) {
      matrix[i][j] = -1;
      answer[i][j] = 0;
      if (i == j) answer[i][j] = 1;
    }
  }

  cin >> N >> B;
  FOR(i, N) {
    FOR(j, N) {
      cin >> matrix[i][j];
    }
  }
}

void solve()
{
  long long tmp1 = 1;
  long long tmp2 = 0;
  while(tmp1 <= B) {
    tmp1 *= 2;
    tmp2++;
  }

  FOR(i, N) {
    FOR(j, N) {
      matrixs[0][i][j] = matrix[i][j];
    }
  }

  FOR(k, tmp2) {
    long long (*tmpArr)[SIZE] = multiple(matrixs[k], matrixs[k]);
    FOR(i, N) {
      FOR(j, N) {
        matrixs[k + 1][i][j] = tmpArr[i][j] % 1000;
      }
    }
  }

  int powerIndex = tmp2;
  while (tmp1 > 1) {
    if (B >= tmp1) {
      B -= tmp1;
      power[powerIndex] = 1;
    }
    tmp1 /= 2;
    powerIndex--;
  }
  power[powerIndex] = B;

  // cout << powerIndex << '\n';
  long long i = 0;
  while(powerIndex != tmp2) {
    if (power[powerIndex] == 1) {
      long long (*tmpArr)[SIZE] = multiple(matrixs[i], answer);
      FOR(i, N) {
        FOR(j, N) {
          answer[i][j] = tmpArr[i][j] % 1000;
        }
      }
    }
    powerIndex++;
    i++;
  }
}

void print()
{
  FOR(i, N) {
    FOR(j, N) {
      cout << answer[i][j] << ' ';
    }
    cout << '\n';
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