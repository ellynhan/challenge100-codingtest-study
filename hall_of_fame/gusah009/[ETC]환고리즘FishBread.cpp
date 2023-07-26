#include <iostream>
#include <queue>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 100
#define TC_COUNT 5
#define IS_EXIST 0
#define IS_NOT_EXIST -1
#define MORE_THAN_TWO -2
#define f first
#define s second

int K;
int arr[TC_COUNT][MAX] = {0};
queue<string> answer;

void input()
{ 
  cin >> K;
  FOR(i, TC_COUNT) {
    FOR(k, K) {
      cin >> arr[i][k];
    }
  }
}

bool check(int tc) {
  FOR(k, K) {
    if (arr[tc][k] != k + 1) return false;
  }
  return true;
}

void flip(int tc, int i, int j) // [i: j)
{
  int tmp;
  for(int a = i; a < (i + j + 1) / 2; a++) {
    tmp = arr[tc][a];
    arr[tc][a] = -arr[tc][i + j - a - 1];
    arr[tc][i + j - a - 1] = -tmp;
  }
}

bool isExistOutOfPlacePositive(int tc)
{
  FOR(k, K) {
    if (arr[tc][k] > 0 && arr[tc][k] != k + 1) return true;
  }
  return false;
}

pair<pair<int, int>, int> findOutOfPlace(int tc, int i, int j)
{
  int st = IS_NOT_EXIST;
  int end = IS_NOT_EXIST;
  int flag = IS_NOT_EXIST;
  for (int k = i; k < j; k++) {
    int current = arr[tc][k];
    int prev = arr[tc][k - 1];
    if (current < 0 && current != k + 1) {
      flag = IS_EXIST;
      if (st != IS_NOT_EXIST) {
        flag = MORE_THAN_TWO;
        break;
      }
      st = k;
      do {
        k++;
      } while (k < K && (arr[tc][k] == arr[tc][k - 1] + 1));
      end = k;
    }
  }
  return {{st, end}, flag};
}

void solve()
{
  FOR(tc, TC_COUNT) {
    int st1, end1, flag1, st2, end2, flag2;
    pair<pair<int, int>, int> n1 = findOutOfPlace(tc, 0, K); 
    st1 = n1.f.f;
    end1 = n1.f.s;
    flag1 = n1.s;
    if (flag1 == IS_NOT_EXIST) {
      answer.push("over");
      continue;
    }
    // cout << "!!!: " << st1 << ' ' << -arr[tc][end1 - 1] << ' ' << end1 << ' ' << -arr[tc][st1] + 1 << ' ' << '\n';
    int f_st = min(st1, -arr[tc][end1 - 1] - 1);
    int f_end = max(end1, -arr[tc][st1]);
    flip(tc, f_st, f_end);
    if(isExistOutOfPlacePositive(tc)) {
      flip(tc, f_st, f_end);
      pair<pair<int, int>, int> n1 = findOutOfPlace(tc, end1, K); 
      st1 = n1.f.f;
      end1 = n1.f.s;
      flag1 = n1.s;
      if (flag1 == IS_NOT_EXIST) {
        answer.push("over");
        continue;
      }
      flip(tc, min(st1, -arr[tc][end1 - 1] - 1), max(end1, -arr[tc][st1]));
    }
    // cout << "HERE! " << tc <<  " \n";
    // FOR(k, K) {
    //   cout << arr[tc][k] << ' ';
    // }
    // cout << '\n';
    if (check(tc)) {
      answer.push("one");
      continue;
    }
    pair<pair<int, int>, int> n2 = findOutOfPlace(tc, 0, K); 
    st2 = n2.f.f;
    end2 = n2.f.s;
    flag2 = n2.s;
    if (flag1 == IS_NOT_EXIST) {
      answer.push("over");
      continue;
    }
    flip(tc, min(st2, -arr[tc][end2 - 1] - 1), max(end2, -arr[tc][st2]));
    
    // cout << "HERE2! " << tc <<  " \n";
    // FOR(k, K) {
    //   cout << arr[tc][k] << ' ';
    // }
    // cout << '\n';
    if (check(tc)) answer.push("two");
    else           answer.push("over");
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