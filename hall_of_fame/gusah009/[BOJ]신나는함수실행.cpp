#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)
#define INF 1987654321
#define SIZE 50

int a, b, c;
int DP[SIZE + 1][SIZE + 1][SIZE + 1] = {0};

template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val)
{
  std::fill((T *)array, (T *)(array + N), val);
}

int recur(int a, int b, int c)
{
  if (a <= 0 || b <= 0 || c <= 0)
  {
    a = a <= 0 ? 0 : a;
    b = b <= 0 ? 0 : b;
    c = c <= 0 ? 0 : c;
    DP[a][b][c] = 1;
    return DP[a][b][c];
  }
  if (DP[a][b][c] != INF)
    return DP[a][b][c];

  if (a > 20 || b > 20 || c > 20)
    return recur(20, 20, 20);

  int result = INF;
  if (a < b && b < c)
  {
    result = recur(a, b, c - 1) +
             recur(a, b - 1, c - 1) -
             recur(a, b - 1, c);
  }
  else
  {
    result = recur(a - 1, b, c) +
             recur(a - 1, b - 1, c) +
             recur(a - 1, b, c - 1) -
             recur(a - 1, b - 1, c - 1);
  }
  DP[a][b][c] = result;
  return DP[a][b][c];
}

void input_solve_print()
{
  while (true)
  {
    cin >> a >> b >> c;
    if (a == -1 && b == -1 && c == -1)
      break;
    Fill(DP, INF);
    cout << "w(" << a << ", " << b << ", " << c << ") = " << recur(a, b, c) << '\n';
  }
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input_solve_print();
}