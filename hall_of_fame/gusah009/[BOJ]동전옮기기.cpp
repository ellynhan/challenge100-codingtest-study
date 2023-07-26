#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
char S[10006];
char T[10006];

bool matching(int s, int t, queue<char> bullets)
{
  if (t == n)
    return true;

  while (S[s] == 'y')
  {
    s++;
  }

  if (s < n && S[s] == T[t])
  {
    if (matching(s + 1, t + 1, bullets))
      return true;
  }
  if (T[t] == bullets.front())
  {
    bullets.pop();
    if (matching(s, t + 1, bullets))
      return true;
  }
  return false;
}

int main()
{
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> S[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> T[i];
  }

  queue<char> bullets;
  int index_1, index_2;
  cin >> index_1 >> index_2;
  bullets.push(S[index_1]);
  bullets.push(S[index_2]);
  S[index_1] = 'y';
  S[index_2] = 'y';

  bool success = matching(0, 0, bullets);

  if (success == true)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}