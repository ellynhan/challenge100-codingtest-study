#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 101

int board[MAX][MAX] = {0};
int A, B, N, M;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<pair<pair<int, int>, int> > robots;
bool wallFlag = false;
bool crashFlag = false;
pair<int, int> crashIndex;
int currentIndex[MAX], repeat[MAX];
char operation[MAX];

void input()
{
  robots.clear();
  wallFlag = false;
  crashFlag = false;

  cin >> B >> A;
  cin >> N >> M;
  int x, y;
  char charD;
  int intD;
  FOR(n, N) {
    cin >> x >> y;
    cin >> charD;
    if (charD == 'N') {
      intD = 0;
    } else if (charD == 'E') {
      intD = 1;      
    } else if (charD == 'S') {
      intD = 2;      
    } else if (charD == 'W') {
      intD = 3;      
    }
    robots.push_back({{y - 1, x - 1}, intD});
  }
  FOR(m, M) {
    cin >> currentIndex[m] >> operation[m] >> repeat[m];
  }
  
}

void solve()
{
  int* currentY;
  int* currentX;
  int* currentDir;
  FOR(m, M) {
    currentY = &robots[currentIndex[m] - 1].first.first;
    currentX = &robots[currentIndex[m] - 1].first.second;
    currentDir = &robots[currentIndex[m] - 1].second;

    if (operation[m] == 'L') {
      FOR(i, repeat[m]) {
        *currentDir = (*currentDir + 3) % 4;
      }
    } else if (operation[m] == 'R') {
      FOR(i, repeat[m]) {
        *currentDir = (*currentDir + 1) % 4;
      }
    } else if (operation[m] == 'F') {
      FOR(i, repeat[m]) {
        (*currentY) += dir[*currentDir][0];
        (*currentX) += dir[*currentDir][1];
        // cout << *currentY << ' ' << *currentX << '\n';
        // cout << robots[currentIndex[m] - 1].first.first << ' ' << robots[currentIndex[m] - 1].first.second << '\n';
        if (*currentY < 0 || *currentY >= A ||
            *currentX < 0 || *currentX >= B) {
              wallFlag = true;
              crashIndex = {currentIndex[m], -1};
              return;
            }
        FOR(index, robots.size()) {
          if (index != currentIndex[m] - 1) {
            int otherY = robots[index].first.first;
            int otherX = robots[index].first.second;
            if (*currentY == otherY && *currentX == otherX) {
              crashFlag = true;
              crashIndex = {currentIndex[m], index + 1};
              return;
            }
          }
        }
      }
    }

  //   bool board[MAX][MAX] = {0};
  //   FOR(index, robots.size()) {
  //     int otherY = robots[index].first.first;
  //     int otherX = robots[index].first.second;
  //     board[otherY][otherX] = true;
  //     cout << robots[index].second << '\n';
  //   }
  //   FOR(a, A) {
  //     FOR(b, B) {
  //       cout << board[a][b] << ' ';
  //     }
  //     cout << '\n';
  //   }
  //   cout << '\n';
  }
}

void print()
{
  if (wallFlag) {;
    cout << "Robot " << crashIndex.first << " crashes into the wall";
  } else if (crashFlag) {
    cout << "Robot " << crashIndex.first << " crashes into robot " << crashIndex.second;
  } else {
    cout << "OK";
  }
  cout << '\n';
}

int main()
{
    // std::ofstream out("out.txt");
    // std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    // std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  print();
}