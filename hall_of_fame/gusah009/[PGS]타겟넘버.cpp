#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N;
int numbers[21] = {0};
int target;
int answer = 0;

void input()
{
  cin >> N;
  FOR(n, N) {
    cin >> numbers[n];
  }
  cin >> target;
}

void DFS(int sum, int depth)
{
  if (depth == N - 1) {
    if (sum == target) {
      answer++;
    }
    return;
  }

  DFS(sum + numbers[depth + 1], depth + 1);
  DFS(sum - numbers[depth + 1], depth + 1);
  
}

void solve()
{
  DFS(numbers[0], 0);
  DFS(-numbers[0], 0);
}

void print()
{
  cout << answer << '\n';
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