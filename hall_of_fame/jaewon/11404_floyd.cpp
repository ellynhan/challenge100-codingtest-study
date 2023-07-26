#include <iostream>
using namespace std;
int n,m,a,b,c;
long long dp[100][100]; //dp[i][j] = i에서 j까지 가는데 최단 경로
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m ;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dp[i][j]=INT32_MAX;
        }
        dp[i][i]=0;
    }
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        dp[a-1][b-1]=min((int)dp[a-1][b-1],c);
    }
    
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(dp[i][j]>=INT32_MAX){
                dp[i][j]=0;
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<'\n';
    }

}
