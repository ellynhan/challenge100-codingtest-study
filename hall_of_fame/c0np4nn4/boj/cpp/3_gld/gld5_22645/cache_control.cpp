// ref: https://www.geeksforgeeks.org/lru-cache-implementation/

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

list<int> ll;
unordered_map<int, list<int>::iterator> cache;
int least_id;

int main() {
  int n;
  int m;
  cin >> n >> m;


  while (n--) {
    int id;
    cin >> id;

    // not found
    if (cache.find(id) == cache.end()) {
      if (cache.size() == m) {
        least_id = ll.back();

        ll.pop_back();

        cache.erase(least_id);
      }
    }

    // found
    else {
      ll.erase(cache[id]);
    }

    // update
    ll.push_front(id);
    cache[id] = ll.begin();
  }

  for (auto data: ll) {
    cout << data << '\n';
  }

  return 0;
}
