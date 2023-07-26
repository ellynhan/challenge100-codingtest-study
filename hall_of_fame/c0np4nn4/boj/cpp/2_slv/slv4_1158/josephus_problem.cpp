#include <iostream>
#include <vector>

using namespace std;

int num[5001];
int nxt[5001];
int prv[5001];

int n, k;
int idx;

vector<int> seq;

void check_table() {
  cout << "\n[+] idx: " << idx << endl;

  cout << "[-] num: ";
  for (int j = 1; j <= n; j++) {
    cout << num[j] << " ";
  }
  cout << endl;

  cout << "[-] prv: ";
  for (int j = 1; j <= n; j++) {
    cout << prv[j] << " ";
  }
  cout << endl;

  cout << "[-] nxt: ";
  for (int j = 1; j <= n; j++) {
    cout << nxt[j] << " ";
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;

  // starting point
  idx = k;

  for (int i = 1; i <= n; i++) {
    num[i] = i;
    nxt[i] = i + 1;
    prv[i] = i - 1;

    if (i == n) nxt[i] = 1;
    if (i == 1) prv[i] = n;
  }

  // while (n--) {
  for (int i = 0; i < n; i++) {
    seq.push_back(idx);

    prv[nxt[idx]] = prv[idx];
    nxt[prv[idx]] = nxt[idx];

    int org_idx = idx;


    // fowarding
    for (int j = 0; j < k; j++) {
      idx = nxt[idx];
    }

    prv[org_idx] = 0;
    nxt[org_idx] = 0;

  }

  cout << '<';
  for (int i = 0; i < seq.size(); i++) {
    cout << seq[i];
    if (i != seq.size() - 1) {
      cout << ", ";
    }
  }
  cout << '>';
  cout << '\n';

  return 0;
}
