#include <iostream>
using namespace std;

int N, M;
string arr[50];
int answer = 0;

int main(){
  cin >> N >> M;
  for(int i=0; i<N; i++) cin >> arr[i];
  int num; cin >> num;

  for(int i=0; i<N; i++){
    int offCnt = 0;
    for(int j=0; j<M; j++){
      if(arr[i][j] == '0') offCnt++;
    }
    if(offCnt <= num && offCnt % 2 == num % 2){
      int match = 1;
      for(int j=i+1; j<N; j++){
        if(arr[i] == arr[j]) match++;
      }
      answer = max(answer, match);
    }
  }

  cout << answer;
}
