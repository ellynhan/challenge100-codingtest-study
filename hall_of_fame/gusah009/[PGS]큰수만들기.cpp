#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)

string str, answer = "";
int K;
stack<int> stk;

void input()
{
  cin >> str;
  cin >> K;
}

int insert_at_bottom(int x)
{
 
    if(stk.size() == 0)
    stk.push(x);
 
    else
    {  
        int a = stk.top();
        stk.pop();
        insert_at_bottom(x);
 
        stk.push(a);
    }
}
 
// Below is the function that
// reverses the given stack using
// insert_at_bottom()
int reverse()
{
    if(stk.size()>0)
    {
        int x = stk.top();
        stk.pop();
        reverse();
         
        insert_at_bottom(x);
    }
}
 
void solve()
{
  FOR(i, str.size())
  {
    while (!stk.empty() && str[i] - '0' > stk.top())
    {
      if (K > 0)
      {
        stk.pop();
        K -= 1;
      }
      else
      {
        break;
      }
    }
    stk.push(str[i] - '0');
  }

  reverse();
}

void print()
{
  while (!stk.empty())
  {
    cout << stk.top();
    stk.pop();
  }
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  print();
}