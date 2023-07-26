#include <iostream>

using namespace std;

#define FOR(i, j, k) for(int i = j; i < k; i++)
#define START 0
#define MAX 8

int N, M;
int arr[MAX] = {0};

void input()
{
  cin >> N >> M;
}

void DFS(int index) 
{
  if (index == M) {
    FOR(m, 0, M) {
      cout << arr[m] << ' ';
    }
    cout << '\n';
    return;
  }

  FOR(i, 1, N + 1) {
    if (index == 0) {
      arr[index] = i;
      DFS(index + 1);
    } else if (arr[index - 1] <= i) {
      arr[index] = i;
      DFS(index + 1);
    }
  }
}

void solve_print()
{
  DFS(START);
}


int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve_print();
}