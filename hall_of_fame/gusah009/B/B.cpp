#include <iostream>
#include <unordered_map>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

int N, K;
int P[10001] = {0};
int isModExist[10001] = {0};
int isExist[10001] = {0};
int answer = INF;

int main()
{
  cin >> N >> K;
  FOR(n, N) {
    cin >> P[n];
    P[n] -= 1;
    isModExist[P[n]]++;
  }

  int i = 0, j = 0;
  while(i != N) {
    isExist[P[i]]++;
    isModExist[P[i]]--;
    bool flag = true;
    FOR(k, K) {
      if (isExist[k] == 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      while (isExist[P[j]] - 1 != 0) {
        isModExist[P[j]]++;
        isExist[P[j]]--;
        j++;
      }
      if (i - j < answer) {
        bool flag2 = true;
        FOR(k, K) {
          if (isModExist[k] == 0) {
            flag2 = false;
            break;
          }
        }
        if (flag2) {
          answer = i - j;
        }
      }
      isModExist[P[j]]++;
      isExist[P[j]]--;
      j++;
    }
    i++;
  }

  if (answer == INF) cout << 0 << '\n';
  else cout << answer + 1 << '\n';
}