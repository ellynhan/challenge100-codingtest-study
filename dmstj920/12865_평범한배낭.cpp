#include <iostream>
#include <algorithm>
#define MAX 101

using namespace std;

int n, k;
int dp[MAX][100001];
int W[MAX];
int V[MAX];

int main()
{
    int i,j;
    cin >> n >> k;

    for(i=1; i<=n; i++){
        cin >> W[i] >> V[i];
    }

    for(i=1; i<=n; i++){
        for(j=1; j<=k; j++){
            if(j >= W[i])  //최대 무게보다 작다면
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][k];

    return 0;
}
