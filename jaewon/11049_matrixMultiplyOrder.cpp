#include <iostream>
using namespace std;
int matrix[500][2];
int dp[500][500]={0}; //최대값으로 초기화 필요함
int main(){
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n ;
    for(int i=0; i<n; i++){
        cin >> matrix[i][0];
        cin >> matrix[i][1];
        for(int j=0; j<n; j++){
            dp[i][j]=INT32_MAX;
        }
    }
    //길이가 1일 때
    for(int i=0; i<n-1; i++){
        dp[i][i+1]=matrix[i][0]*matrix[i][1]*matrix[i+1][1];
    }
    //길이가 2일 때
    for(int i=0; i<n-2; i++){
        dp[i][i+2]=min(dp[i][i+2],dp[i][i+1]+matrix[i][0]*matrix[i+2][0]*matrix[i+2][1]);
        dp[i][i+2]=min(dp[i][i+2],dp[i+1][i+2]+matrix[i][0]*matrix[i][1]*matrix[i+2][1]);
    }

    for(int len=3; len<n; len++){
        for(int i=0; i<n-len; i++){
            //첫 한덩이
            dp[i][i+len]=matrix[i][0]*matrix[i][1]*matrix[i+len][1]+dp[i+1][i+len];
            //여러 덩이들
            for(int j=1; j<len-1; j++){
               dp[i][i+len]=min(dp[i][i+len],dp[i][i+j]+dp[i+j+1][i+len]+matrix[i][0]*matrix[i+j][1]*matrix[i+len][1]);
            }
            //뒷 한덩이
            dp[i][i+len]=min(dp[i][i+len],matrix[i][0]*matrix[i+len-1][1]*matrix[i+len][1]+dp[i][i+len-1]);
        }
    }

    cout<<dp[0][n-1];
}
