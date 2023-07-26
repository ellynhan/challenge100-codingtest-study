#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

string S, P;

void input()
{
  cin >> S >> P;
}

void solve()
{
	if (S.find(P) != string::npos) {
    cout << 1;
	} else {
    cout << 0;
  }
}

void print()
{

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