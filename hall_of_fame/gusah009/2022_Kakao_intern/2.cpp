#include <string> // 20m
#include <vector>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)
#define ull unsigned long long

int solution(vector<int> queue1, vector<int> queue2) {
  int answer = 0;
  ull sum1 = 0;
  ull sum2 = 0;
  FOR(i, queue1.size()) {
    sum1 += queue1[i];
    sum2 += queue2[i];
  }
  if ((sum1 + sum2) % 2 == 1) return -1;

  int cursor1 = 0, cursor2 = 0;
  while(true) {
    if (sum1 > sum2) {
      if (cursor1 == queue1.size() + queue2.size()) {
        answer = -1;
        break;
      }
      if (cursor1 < queue1.size()) {
        sum1 -= queue1[cursor1];
        sum2 += queue1[cursor1];
      } else {
        sum1 -= queue2[cursor1 - queue1.size()];
        sum2 += queue2[cursor1 - queue1.size()];
      }
      cursor1++;
    } else if (sum1 < sum2) {
      if (cursor2 == queue2.size() + queue1.size()) {
        answer = -1;
        break;
      }
      if (cursor2 < queue1.size()) {
        sum1 += queue2[cursor2];
        sum2 -= queue2[cursor2];
      } else {
        sum1 += queue1[cursor2 - queue2.size()];
        sum2 -= queue1[cursor2 - queue2.size()];
      }
      cursor2++;
    } else if (sum1 == sum2) {
      break;
    }
    answer++;
  }
  return answer;
}