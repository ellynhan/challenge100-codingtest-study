#include <iostream>

using namespace std;

int k;
int arr[14];
int seq[14];
bool issue[50];

void func(int t) {
  if (t == 6) {
    for (int i = 1; i <= 6; i++) {
      cout << seq[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for (int i = 0; i < k; i++) {
    if (issue[arr[i]] == false) {
      if (seq[t] <= arr[i]) {
        seq[t + 1] = arr[i];
        issue[arr[i]] = true;
        func(t + 1);
        issue[arr[i]] = false;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (true) {
    for (int i = 0; i < 14; i++) {
      seq[i] = 0;
      issue[i] = false;
    }

    cin >> k;
    if (k == 0) break;

    for (int i = 0; i < k; i++) {
      cin >> arr[i];
    }

    func(0);
    cout << '\n';
  }
  return 0;
}
