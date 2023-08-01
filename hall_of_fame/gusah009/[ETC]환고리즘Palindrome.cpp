#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define PALINDROME 1
#define QUASI_PALINDROME 2
#define NONE 3


int N;
vector<string> inp;
queue<int> answer;

void input()
{ 
  cin >> N;
  FOR(n, N) {
    string tmp;
    cin >> tmp;
    inp.push_back(tmp);
  }
}

bool checkPalin(string &str)
{
  int len = str.length();
  FOR(i, len / 2) {
    if (str[i] != str[len - 1 - i]) {
      return false;
    }
  }
  return true;
}

bool checkQuasiPalin(string &str)
{
  int len = str.length();

  int correct = 0;
  // 0번째 제거했을 때 같은 개수
  FOR(i, (len + 1) / 2) {
    if(str[i + 1] == str[(len - 1) - i]) correct++;
  }

  if (correct == (len - 1) / 2 + ((len - 1) % 2)) return true;    
  for(int i = 0; i < len - 1; i++) {
    if (i < (len - 1) / 2) {
      if (str[i + 1] == str[len - 1 - i])     correct--;
      if (str[i] == str[len - 1 - i])         correct++;
    } else if ((len - 1) % 2 == 1 && i == (len - 1) / 2) {
      if (str[i + 1] == str[len - 1 - i - 0]) correct--;
      if (str[i] == str[len - 1 - i - 1])     correct++;
    } else {
      if (str[i + 1] == str[len - 1 - i - 1]) correct--;
      if (str[i] == str[len - 1 - i - 1])     correct++;
    }
    if (correct == (len - 1) / 2 + ((len - 1) % 2)) return true;    
  }
  return false;
}

void solve()
{
  FOR(n, N) {
    if (checkPalin(inp[n])) answer.push(PALINDROME);
    else if (checkQuasiPalin(inp[n])) answer.push(QUASI_PALINDROME);
    else answer.push(NONE);
  }
}

void print()
{
  while(!answer.empty()) {
    cout << answer.front() << '\n';
    answer.pop();
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