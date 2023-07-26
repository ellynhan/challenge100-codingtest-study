#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, M; cin >> N >> M;
  vector<int> queue;

  int i;
  for(i=0; i<N; i++){
    queue.push_back(i+1);
  }

  int select, tmp;
  int cnt = 0;

  while(!(cin >> select).eof()){
    auto it = find(queue.begin(), queue.end(), select);
    int num = it - queue.begin();
    if(num < (queue.size() + 1) / 2){
      while(select != queue.front()){
        tmp = queue.front();
        queue.erase(queue.begin());
        queue.push_back(tmp);
        cnt++;
      }
    } else {
      while(select != queue.front()){
        tmp = queue.back();
        queue.erase(queue.end() - 1);
        queue.insert(queue.begin(), tmp);
        cnt++;
      }
    }
    queue.erase(queue.begin());
  }
  cout << cnt;
}
