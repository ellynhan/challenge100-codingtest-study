#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N; cin >> N;
    vector<vector<int>> db(N, vector<int>(N, 0));
    vector<vector<int>> dp(N+1, vector<int>(N+2, 0));
    for(int i=0; i < N; i++){
        for(int j=0; j<=i; j++){
            int tmp; cin >> tmp;
            db[i][j] = tmp;
        }
    }

    for(int i=0; i < N; i++){
        for(int j=1; j<=i+1; j++){
            dp[i+1][j] = max(dp[i][j-1], dp[i][j]) + db[i][j-1];
        }
    }

    int maxV = dp[N][1];
    for(int i=2; i<=N; i++){
        maxV = max(maxV, dp[N][i]);
    }

    cout << maxV << "\n";

}
