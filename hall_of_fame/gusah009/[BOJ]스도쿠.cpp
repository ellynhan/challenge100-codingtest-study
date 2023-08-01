#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 9

int board[9][9] = {0};
bool isUsedInRow[9][10] = {0};
bool isUsedInCol[9][10] = {0};
bool isUsedInBox[9][10] = {0};
vector<pair<int, int> > cursor;

void input()
{
  FOR(i, 9) {
    FOR(j, 9) {
      cin >> board[i][j];
      isUsedInRow[i][board[i][j]] = true;
      isUsedInCol[j][board[i][j]] = true;
      isUsedInBox[i / 3 * 3 + j / 3][board[i][j]] = true;
      if (board[i][j] == 0) cursor.push_back({i, j});
    }
  }
}

bool backtracking(int c)
{
  if (c == cursor.size()) {
    return true;
  }

  int i = cursor[c].first;
  int j = cursor[c].second;
  for (int num = 1; num < 10; num++) {
    if (!isUsedInRow[i][num] &&
        !isUsedInCol[j][num] &&
        !isUsedInBox[i / 3 * 3 + j / 3][num]) {
          isUsedInRow[i][num] = true;
          isUsedInCol[j][num] = true;
          isUsedInBox[i / 3 * 3 + j / 3][num] = true;
          board[i][j] = num;
          if (backtracking(c + 1)) return true;
          board[i][j] = 0;
          isUsedInRow[i][num] = false;
          isUsedInCol[j][num] = false;
          isUsedInBox[i / 3 * 3 + j / 3][num] = false;
        }
  }
  return false;
}

void solve()
{
  backtracking(0);
}

void print()
{
  FOR(i, MAX) {
    FOR(j, MAX) {
      cout << board[i][j] << ' ';
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