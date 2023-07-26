#include <algorithm>
#include <iostream>
#include <queue>
#include<set>
using namespace std;

int k, len;
string N;
string answer = "-1";

void init(){
  cin >> N >> k;
  len = N.size();

  if(len == 1 || (len == 2 && stoi(N) % 10 == 0)){
    cout << -1;
    exit(0);
  }
}

void exchange(){
  queue<string> arr;
  arr.push(N);

  string currStr;
  int cnt = 0;

  while(cnt < k){
    int qSize = arr.size();
    set<string> visit;
    
    while(qSize--){
      currStr = arr.front(); arr.pop();

      for(int i=0; i<currStr.size(); i++){
        for(int j=i+1; j<currStr.size(); j++){
          if(i == 0 && currStr[j] == '0') continue;

          swap(currStr[i], currStr[j]);
          if(visit.find(currStr) == visit.end()){
            if(cnt == k-1 && stoi(answer) < stoi(currStr)){
              answer = currStr;
            }
            arr.push(currStr);
            visit.insert(currStr);
          }
          swap(currStr[i], currStr[j]);

        }
      }
    }
    
    cnt++;
  }
}

void printAnswer(){
  cout << answer;
}

int main(){
  init(); // 1. 입력받기
  exchange(); // 2. bfs로 가능한 변화 시도
  printAnswer(); // 3. 출력하기
}
