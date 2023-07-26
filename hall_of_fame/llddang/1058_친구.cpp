#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<string> semiFriend;
  vector<string> Friend;

  int N; cin >> N;
  string tmpS;
  int i, j, k;
  for(i=0; i<N; i++){
    cin >> tmpS;
    semiFriend.push_back(tmpS);
    Friend.push_back(tmpS);
  }

  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      if(i == j) continue;
      if(semiFriend[i][j] == 'Y'){
        for(k=0; k<N; k++){
          if(i == k) continue;
          if(semiFriend[j][k] == 'Y'){
            Friend[i][k] = 'Y';
          }
        }
      }
    }
  }

  int answer = 0, tmpA;
  for(auto str:Friend){
    tmpA = 0;
    for(auto s:str){
      if(s == 'Y')
        tmpA++;
    }
    if(tmpA > answer)
      answer = tmpA;
  }

  cout << answer;
}
