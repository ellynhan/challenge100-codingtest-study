#include <iostream>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
typedef long long ll;

int T, N[100001];
ll odd[100001];
ll even[100001];

void input()
{
  cin >> T;
	odd[1] = 1;
	odd[2] = 1;
	odd[3] = 2;
	even[1] = 0;
	even[2] = 1;
	even[3] = 2;
  FOR(t, T) {
    cin >> N[t];
  }
}

void solve()
{
	for (int i = 4; i <= 100001; i++) {
		if (even[i] == 0)even[i] = (odd[i - 1] + odd[i - 2] + odd[i - 3]) % 1000000009;
		if (odd[i] == 0)odd[i] = (even[i - 1] + even[i - 2] + even[i - 3]) % 1000000009;

	}
}

void print()
{
  FOR(t, T) {
	  cout << odd[N[t]] << " " << even[N[t]] << '\n';
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