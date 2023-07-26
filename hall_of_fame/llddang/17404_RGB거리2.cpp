#include <iostream>
#define MAX 1000*1000+1
using namespace std;

int value[1001][3];

int main(){
  int N; cin >> N;
  int ans = MAX;

  int r,g,b;
  for(int i=1; i<=N; i++){
    cin >> r >> g >> b;
    value[i][0] = r;
    value[i][1] = g;
    value[i][2] = b;
  }

  for(int start=0; start<3; start++){
    int dp[1001][3];
    int i;
    for(i=0; i<3; i++){
      if(start == i) dp[1][i] = value[1][i];
      else dp[1][i] = MAX;
    }

    for(i=2; i<=N; i++){
      dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + value[i][0];
      dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + value[i][1];
      dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + value[i][2];
    }

    for(int end=0; end<3; end++){
      if(end == start) continue;
      ans = min(ans, dp[N][end]);
    }
  }
  cout << ans;
  return 0;
}
