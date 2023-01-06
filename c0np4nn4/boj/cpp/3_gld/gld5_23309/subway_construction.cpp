#include <iostream>
#include <iomanip>

using namespace std;

int station[2000001];
int prev_station[2000001];
int next_station[2000001];
int location[2000001];

int n, m;
int idx_station = 0;

void table_check() {
  cout << endl;
  // check
  cout << "\n[+] table check\n\n";

  cout << "[-] index:   ";
  for (int i = 0; i <= 9; i++) {
    cout << i << setw(7);
  }
  cout << '\n';

  cout << "[-] station: ";
  for (int i = 0; i <= 9; i++) {
    cout << station[i] << setw(7);
  }
  cout << '\n';

  cout << "[-] prev:    ";
  for (int i = 0; i <= 9; i++) {
    cout << prev_station[i] << setw(7);
  }
  cout << '\n';

  cout << "[-] next:    ";
  for (int i = 0; i <= 9; i++) {
    cout << next_station[i] << setw(7);
  }
  cout << '\n';

  cout << "\n[-] location: ";
  for (int i = 0; i < 32; i++) {
    if (i % 8 == 0) cout << '\n';
    cout << location[i] << setw(7);
  }
  cout << '\n';

  cout << endl;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // dummy node
  station[0] = 0;
  next_station[0] = 0;
  prev_station[0] = 0;

  cin >> n >> m;

  for(int i = 1; i < n + 1; i++) {
    int num = 0;
    cin >> num;

    station[i] = num;
    prev_station[i] = i - 1;
    next_station[i] = i + 1;

    location[num] = i;

    if (i == 1) {
      prev_station[i] = n;
    }

    if (i == n) {
      next_station[i] = 1;
    }
  }

  // index an empty section
  idx_station = n + 1;


  while (m--) {
    string op; 
    cin >> op;

    if (op == "BN") {
      int i = 0;
      cin >> i;
    
      cout << station[next_station[location[i]]] << '\n';

      int j = 0;
      cin >> j;

      station[idx_station] = j;
      next_station[idx_station] = next_station[location[i]];
      prev_station[idx_station] = prev_station[next_station[location[i]]];

      prev_station[next_station[location[i]]] = idx_station;
      next_station[location[i]] = idx_station;

      location[j] = idx_station;

      idx_station += 1;
    }

    if (op == "BP") {
      int i = 0;
      cin >> i;

      cout << station[prev_station[location[i]]] << '\n';

      int j = 0;
      cin >> j;

      station[idx_station] = j;
      next_station[idx_station] = location[i];
      prev_station[idx_station] = prev_station[location[i]];

      next_station[prev_station[location[i]]] = idx_station;
      prev_station[location[i]] = idx_station;

      location[j] = idx_station;

      idx_station += 1;
    }

    if (op == "CN") {
      int i = 0;
      cin >> i;

      cout << station[next_station[location[i]]] << '\n';

      int idx_closing_station = next_station[location[i]];

      next_station[location[i]] = next_station[idx_closing_station];
      prev_station[next_station[idx_closing_station]] = prev_station[idx_closing_station];

      // clear
      location[station[idx_closing_station]] = 0;
      station[idx_closing_station] = 0;
      next_station[idx_closing_station] = 0;
      prev_station[idx_closing_station] = 0;

      idx_station += 1;
    }

    if (op == "CP") {
      int i = 0;
      cin >> i;

      cout << station[prev_station[location[i]]] << '\n';

      int idx_closing_station = prev_station[location[i]];

      prev_station[location[i]] = prev_station[idx_closing_station];
      next_station[prev_station[idx_closing_station]] = next_station[idx_closing_station];

      // clear
      location[station[idx_closing_station]] = 0;
      station[idx_closing_station] = 0;
      next_station[idx_closing_station] = 0;
      prev_station[idx_closing_station] = 0;

      idx_station += 1;
    }

    // check
    // table_check();
  }

  return 0;
}
