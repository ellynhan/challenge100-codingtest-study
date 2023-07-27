#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define SIZE    50
#define WATER   0
#define LAND    1
#define SEA     0
#define NOTHING -987654321

int N, M;
int dir1[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int dir2[8][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int isl[SIZE][SIZE] = {0};
int islNumbering[SIZE][SIZE];
vector<int> islInclude[SIZE * SIZE];
int islHeight[SIZE * SIZE] = {0};
int islandNum = 1;

void input()
{
  cin >> N >> M;
  FOR(n, N) {
    string tmp;
    cin >> tmp;
    FOR(m, M) {
      isl[n][m] = tmp[m] == 'x' ? LAND : WATER;
    }
  }
  
  // init
  FOR(n, N) {
    FOR(m, M) {
      islNumbering[n][m] = NOTHING;
    }
  }
}

void setSea(int n, int m)
{
  islNumbering[n][m] = SEA;
  FOR(i, 4) {
    int next_n = n + dir1[i][0];
    int next_m = m + dir1[i][1];
    if (0 <= next_n && next_n < N &&
        0 <= next_m && next_m < M &&
        islNumbering[next_n][next_m] != SEA &&
        isl[next_n][next_m] == WATER) {
          setSea(next_n, next_m);
        }
  }
}

void setIslandNum(int n, int m)
{
  islNumbering[n][m] = islandNum;
  FOR(i, 8) {
    int next_n = n + dir2[i][0];
    int next_m = m + dir2[i][1];
    if (0 <= next_n && next_n < N &&
        0 <= next_m && next_m < M &&
        isl[next_n][next_m] == LAND && 
        islNumbering[next_n][next_m] == NOTHING) {
          setIslandNum(next_n, next_m);
        }
  }
}

int checkIslandInclude(int n, int m, int islNum)
{
  int result = NOTHING;
  FOR(i, 4) {
    int next_n = n + dir1[i][0];
    int next_m = m + dir1[i][1];
    if (0 > next_n && next_n >= N &&
        0 > next_m && next_m >= M)
          return SEA;
    else if (islNumbering[next_n][next_m] != islNum)
          result = islNumbering[next_n][next_m];
          if (result == SEA) return SEA;
  }
  return result;
}

void setIslandInclude(int n, int m, int islNum)
{
  islNumbering[n][m] = -islNum;

  FOR(i, 4) {
    int next_n = n + dir1[i][0];
    int next_m = m + dir1[i][1];
    if (0 <= next_n && next_n < N &&
        0 <= next_m && next_m < M &&
        (islNumbering[next_n][next_m] == islNum ||
         islNumbering[next_n][next_m] == NOTHING))
          setIslandInclude(next_n, next_m, islNum);
  }
} 

int setIslandHeight(int n)
{
  int result = 0;
  FOR(i, islInclude[n].size()) {
    result = max(result, setIslandHeight(islInclude[n][i]));
  }
  islHeight[n] = result;
  return islHeight[n] + 1;
}

void solve()
{
  // 바다 구하기
  FOR(n, N) {
    if (isl[n][0] == WATER) {
      setSea(n, 0);
    }
    if (isl[n][M - 1] == WATER) {
      setSea(n, M - 1);
    }
  }

  FOR(m, M) {
    if (isl[0][m] == WATER) {
      setSea(0, m);
    }
    if (isl[N - 1][m] == WATER) {
      setSea(N - 1, m);
    }
  }

  // 섬 넘버링
  FOR(n, N) {
    FOR(m, M) {
      if (isl[n][m] == LAND && islNumbering[n][m] == NOTHING) {
        setIslandNum(n, m);
        islandNum++;
      }
    }
  }

  // 높이 -1로 초기화
  FOR(i, islandNum) {
    islHeight[i] = -2;
  }

  // 섬 포함
  FOR(n, N) {
    FOR(m, M) {
      if (isl[n][m] == LAND &&
          islNumbering[n][m] > 0) {  
            int result = checkIslandInclude(n, m, islNumbering[n][m]);
            if (result != SEA) {
              // cout << -result << ':' << islNumbering[n][m] << '\n';;
              islInclude[-result].push_back(islNumbering[n][m]);
            } else {
              islHeight[islNumbering[n][m]] = -1;
            }
            setIslandInclude(n, m, islNumbering[n][m]);
      }
    }
  }
// FOR(n, N) {
//   FOR(m, M) {
//     cout << -islNumbering[n][m] << ' ';
//   }
//   cout << '\n';
// }
// cout << '\n';

  FOR(n, islandNum) {
    if (islHeight[n] == -1) {
      setIslandHeight(n);
    }
  }
  
  // FOR(i, islandNum) {
  //   cout << islHeight[i] << ' ';
  // }
  // cout << '\n';
}

void print()
{
  int height[SIZE * SIZE] = {0};
  for(int n = 1; n < islandNum; n++) {
    height[islHeight[n]]++;
  }

  int index = 0;
  while(height[index] != 0) {
    cout << height[index++] << ' ';
  }
  if (index == 0) cout << -1;
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