#include <iostream>
#include <vector>

using namespace std;

typedef struct point {
  int x;
  int y;
} Point;

int main()
{
  int N;
  int isPoss[4] = {0};
  bool answer = true;
  cin >> N;
  vector<Point> police(N);
  Point thief;
  for (int n = 0; n < N; n++) {
    int tmp1, tm2;
    cin >> police[n].x >> police[n].y;
  }
  cin >> thief.x >> thief.y;

  for (int n = 0; n < N; n++) {
    if (police[n].x <= thief.x) {
      if (abs(police[n].y - thief.y) <= abs(police[n].x - thief.x)) {
        isPoss[0]++;
        // cout << "0\n";
      }
    }
    if (police[n].y <= thief.y) {
      if (abs(police[n].y - thief.y) >= abs(police[n].x - thief.x)) {
        isPoss[1]++;
        // cout << "1\n";
        
      }   
    }
    if (police[n].x >= thief.x) {
      if (abs(police[n].y - thief.y) <= abs(police[n].x - thief.x)) {
        isPoss[2]++;
        // cout << "2\n";
        
      }

    }
    if (police[n].y >= thief.y) {
      if (abs(police[n].y - thief.y) >= abs(police[n].x - thief.x)) {
        isPoss[3]++;
        // cout << "3\n";
      }

    }
  }
  for (int n = 0; n < 4; n++) {
    if (isPoss[n] == 0) {
      answer = false;
      break;
    }
  }
  if (!answer) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}