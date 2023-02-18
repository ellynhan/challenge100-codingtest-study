#include <iostream>

using namespace std;

double max_score;
double sum;

int main() {
  int n;
  cin >> n;

  // while (n--) {
  for (int i = 0; i < n; i++) {
    double tmp;
    cin >> tmp;

    if (tmp > max_score) max_score = tmp;

    sum += tmp;
  }

  // cout << sum << endl;
  // cout << max_score << endl;

  cout << ((sum / max_score) * 100) / (double)n << '\n';
  return 0;
}
