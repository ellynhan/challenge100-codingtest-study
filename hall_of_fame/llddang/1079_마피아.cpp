#include <iostream>
#define MAX 16
using namespace std;

int N, mafia;
int scoreBoard[MAX][MAX];
int score[MAX];
int live[MAX] = {0, };

int playGame(int n, int day){
  int ret = 0;
  if(n % 2 == 0){ // night
    for(int i=0; i<N; i++){
      if(i == mafia || live[i] == 1) continue;

      live[i] = 1;
      for(int j=0; j<N; j++) score[j] += scoreBoard[i][j];
      ret = max(ret, playGame(n-1, day+1));
      for(int j=0; j<N; j++) score[j] -= scoreBoard[i][j];
      live[i] = 0;
    }
  } else { // day
    int idx = 0;
    int maxScore = 0;
    for(int i=0; i<N; i++){
      if(live[i] == 1) continue;
      if(maxScore < score[i]){
        maxScore = score[i];
        idx = i;
      }
    }
    
    if(idx == mafia) return day;
    live[idx] = 1;
    ret = playGame(n-1, day);
    live[idx] = 0;
  }

  return ret;
}

int main(){
  cin >> N;
  for(int i=0; i<N; i++) cin >> score[i];
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      cin >> scoreBoard[i][j];
  cin >> mafia;

  cout << playGame(N, 0);
}
