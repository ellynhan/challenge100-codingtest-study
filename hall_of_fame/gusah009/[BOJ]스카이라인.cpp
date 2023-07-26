#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N;
vector<pair<int, int> > timeline;
multiset<int> S;

void input()
{
  cin >> N;
  FOR(n, N) {
    int L, R, H;
    cin >> L >> H >> R;
    timeline.push_back({L, H});
    timeline.push_back({R, -H});
  }
  sort(timeline.begin(), timeline.end());
}

void solve()
{
  S.insert(0);
  int prevX = timeline[0].first;
  int prevY = -1;

  int i = 0;
  while(i < 2 * N) {
    while(prevX == timeline[i].first) {
      int H = timeline[i].second;
      if (H < 0) {
        S.erase(S.find(-H));
      } else {
        S.insert(H);
      }
      i++;
    }
    
    int val = *S.rbegin();
    if(val != prevY){
      cout << prevX << ' ' << *S.rbegin() << ' ';
      prevY = val;
    }
    prevX = timeline[i].first;
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