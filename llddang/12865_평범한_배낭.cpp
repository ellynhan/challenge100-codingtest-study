#include <iostream>
using namespace std;

int N, K;
int arr[100][2];
int dp[101][100001]={0};

int main(){
    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> arr[i][0] >> arr[i][1];

    for(int i=1; i<=N; i++){
        int w = arr[i-1][0], v = arr[i-1][1];
        for(int j=0; j<=K; j++){
            if(w <= j)
                dp[i][j] = max(dp[i-1][j-w] + v, dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[N][K];
}
