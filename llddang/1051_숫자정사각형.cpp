#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, M; cin >> N >> M;
  vector<vector<int>> square;
  int i, j;
  for(i=0; i<N; i++){
    vector<int> tmpV;
    string tmp; cin >> tmp;
    for(j=0; j<M; j++){
      tmpV.push_back(tmp[j]);
    }
    square.push_back(tmpV);
    tmpV.clear();
  }
  int minNum = min(N, M);
  while(minNum){
    for(i=0; i<N; i++){
      for(j=0; j<M; j++){
        if( i + minNum - 1 >= N || j + minNum - 1 >= M ) break;
        if(square[i][j] == square[i+minNum-1][j] && 
           square[i][j] == square[i+minNum-1][j+minNum-1] &&
           square[i][j] == square[i][j+minNum-1]){
           cout << minNum * minNum;
           return 0;
        }
      }
    }
    minNum--;
  }
}
