#include <iostream>
#include <algorithm>

#define MAX 10000
#define EMPTY -1

using namespace std;


int K, N;
int totalCount = 0;
int carNum;
int park[MAX];
int emptyCursor, sizeCursor;

int main()
{
  // INPUT & SOLVE
  for (int i = 0; i < MAX; i++) park[i] = EMPTY;

  cin >> K >> N;
  emptyCursor = 0;
  sizeCursor  = K;
  for (int n = 0; n < N; n++) {
    cin >> carNum;
    if (carNum > 0) {
      if (totalCount == sizeCursor) {
        sizeCursor *= 2;
      }
      park[emptyCursor] = carNum;
      while(park[emptyCursor] != EMPTY) emptyCursor++;
      
      totalCount++;
    } else {
      int popCursor = 0;
      while(popCursor != sizeCursor && park[popCursor] != -carNum) popCursor++;
      if (popCursor != sizeCursor) park[popCursor] = EMPTY;
      else continue;
      emptyCursor = min(popCursor, emptyCursor);
      
      totalCount--;

      if (totalCount <= sizeCursor / 3) {
        int i = 0;
        for (int j = 0; j < sizeCursor && i != totalCount; j++) {
          if (park[j] != EMPTY) {
            if (i == j) i++;
            else {
              park[i++] = park[j];
              park[j] = EMPTY;
            }
          }
        }
        sizeCursor /= 2;
      }
    }
  }

  // PRINT
  for (int i = 0; i < sizeCursor; i++) {
    if (park[i] != EMPTY) {
      cout << i + 1 << ' ' << park[i] << '\n';
    }
  }
}