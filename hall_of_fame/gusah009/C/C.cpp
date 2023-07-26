#include <iostream>
#include <unordered_map>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N;
int location, dist;
char dir;
unordered_map<int, int> gogogo;
int YeongHee;

int main()
{
  cin >> N;
  FOR(n, N) {
    cin >> location >> dir >> dist;
    if (dir == 'R') {
      gogogo.insert({location, dist});
    } else if (dir == 'L') {
      gogogo.insert({location, -dist});
    }
  }
  cin >> YeongHee;

  FOR(n, N) {
    YeongHee += gogogo[YeongHee];
  }
  cout << YeongHee << '\n';
}