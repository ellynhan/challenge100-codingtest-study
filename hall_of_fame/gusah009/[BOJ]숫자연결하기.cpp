#include <iostream>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define ull unsigned long long
ull N, K;
ull cnt = 1;
int answer = 1;

void input()
{
  cin >> N >> K;
  
  ull tmp = N;
  while ( tmp > 0 ) {
    tmp /= 10;
    cnt *= 10;
  }
}

void solve()
{
  ull _mod = N % K;
  ull cntMod = cnt % K;
  ull result = _mod;
  ull cntModResult = 1;
  while(result != 0) {
    if (answer > K) {
      answer = -1;
      break;
    }
    answer++;
    cntModResult *= cntMod;
    cntModResult += 1;
    cntModResult %= K;
    // cout << cntModResult << '\n';
    result = (_mod * cntModResult) % K;
  }
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