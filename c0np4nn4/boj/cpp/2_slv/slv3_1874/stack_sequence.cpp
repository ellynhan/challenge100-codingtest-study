#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <list>

using namespace std;

stack<int> st;
list<int> seq;
vector<char> op;

void push(int i) {
  // cout << "[-] push, n: " << i << endl;

  op.push_back('+');
  st.push(i);
}

void pop() {
  // cout << "[-] pop, top: " << st.top() << endl;

  op.push_back('-');
  st.pop();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;


  for(int i = 0; i < n; i++) {
    int nn;
    cin >> nn;
    seq.push_back(nn);
  }


  for(int i = 1; i <= n; i++) {
    // cout << "[+] i: " << i << endl;

    if (st.empty()) {
      push(i);
    }

    else {
      if (st.top() == seq.front()) {
        seq.pop_front();
        pop();
        i--;
      }
      else {
        push(i);
      }
    }
  }

  while (!st.empty()) {
    if (st.top() == seq.front()) {
      seq.pop_front();
      pop();
    } else {
      break;
    }
  }

  if (!st.empty()) {
    cout << "NO" << '\n';
  }

  else {
    for (auto c: op) {
      cout << c << '\n';
    }
  }


  return 0;
}
