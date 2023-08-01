#include <iostream>
#include <deque>

using namespace std;

deque<int> q;

deque<int> q_l;
deque<int> q_r;

int cnt;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    q.push_back(i);
  }

  while (m--) {
    int t;
    cin >> t;

    int cnt_l = 0;
    auto q_l = q;
    while (q_l.front() != t) {
      int v = q_l.front();
      q_l.pop_front();
      q_l.push_back(v);
      cnt_l++;
    }

    int cnt_r = 0;
    auto q_r = q;
    while (q_r.front() != t) {
      int v = q_r.back();
      q_r.pop_back();
      q_r.push_front(v);
      cnt_r++;
    }

    if (cnt_l < cnt_r) {
      cnt += cnt_l;
      while (q.front() != t) {
        int v = q.front();
        q.pop_front();
        q.push_back(v);
      }
      q.pop_front();

    } else {
      cnt += cnt_r;

      while (q.front() != t) {
        int v = q.back();
        q.pop_back();
        q.push_front(v);
      }
      q.pop_front();
    }
  }

  cout << cnt << '\n';


  

  return 0;
}
